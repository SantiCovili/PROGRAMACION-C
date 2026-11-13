/*4. Realizar un programa que permita buscar un contacto en el archivo de agenda generado en punto anterior,
por apellido o nombre y mostrar el / los datos coincidentes si los hay.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 40

void LeerTexto(char texto[], int largo);
FILE *AbrirArchivo(char nombre[], char tipo[]);

int main()
{
    FILE *archDatos;
    archDatos = AbrirArchivo("agenda.txt","rt");
    char buscado[50];
    char linea[250];
    char *apellido, *nombre, *correo, *telefono;
    int encontrado = 0;
    printf("ingresar nombre o apellido a buscar");
    LeerTexto(buscado, 50);
    fgets(linea, sizeof(linea), archDatos);
    while(!feof(archDatos))
    {
        apellido = strtok(linea, ";");
        nombre   = strtok(NULL, ";");
        correo   = strtok(NULL, ";");
        telefono = strtok(NULL, ";\n"); 
        if(apellido != NULL && nombre != NULL)
        {
            if(strcmpi(apellido, buscado) == 0 || strcmpi(nombre, buscado) == 0)
            {
                printf("Apellido: %s | Nombre: %s | Correo: %s | Tel: %s\n", apellido, nombre, correo, telefono);
                encontrado = 1;
            }
        }
        fgets(linea, sizeof(linea), ArchAgenda);
    }
    if(!encontrado)
    {
        printf("No se encontraron contactos que coincidan con '%s'.\n", buscado);
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