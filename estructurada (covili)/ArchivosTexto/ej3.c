/*3. Realizar un programa que genere un archivo llamado “agenda.txt” en el cual se almacene los siguientes
datos ingresados por teclado:
• Apellido
• Nombre
• Correo electrónico
• Teléfono
El ingreso se datos finaliza con apellido y nombre igual a “FINALIZAR”. Utilice el separador ; (punto y coma)
entre campos. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 40
typedef struct ej3
{
    char apellido[TAM];
    char nombre[TAM];
    char correo[TAM];
    char telefono[TAM];
}DATOS;

FILE *AbrirArchivo(char nombre[], char tipo[]);
void LeerTexto(char texto[], int largo);

int main()
{
    FILE *archDatos;
    DATOS auxdatos;
    archDatos = AbrirArchivo("agenda.txt", "wt");
    printf("---INGRESAR DATOS--- \n");
    printf("Ingrese el apellido: ");
    LeerTexto(auxdatos.apellido, TAM);
    printf("Ingrese el nombre: ");
    LeerTexto(auxdatos.nombre, TAM);
    while(strcmpi(auxdatos.apellido, "FINALIZAR") != 0 || strcmpi(auxdatos.nombre, "FINALIZAR") != 0)
    {
        printf("Ingrese el Correo Electronico: ");
        LeerTexto(auxdatos.correo, TAM);
        printf("Ingrese el telefono: ");
        LeerTexto(auxdatos.telefono, TAM);
        fprintf(archDatos, "%s;%s;%s;%s\n", auxdatos.apellido, auxdatos.nombre, auxdatos.correo, auxdatos.telefono);
        printf("Ingrese el apellido: ");
        LeerTexto(auxdatos.apellido, TAM);
        printf("Ingrese el nombre: ");
        LeerTexto(auxdatos.nombre, TAM);
    }
    fclose(archDatos);
    return 0;

    

}

void LeerTexto(char texto[], int largo)
{
    int i=0;
    fgets(texto, largo, stdin);
    while (texto[i]!='\0')
    {
        if (texto[i]=='\n')
        {
            texto[i]='\0';
        }
        else
        {
            i++;
        } 
    }
}

FILE *AbrirArchivo(char nombre[], char tipo[])
{
    FILE *fp;
    fp = fopen(nombre, tipo);
    if(fp == NULL)
    {
        printf("Error al abrir archivo");
        exit(1);
    }
    return fp;
}