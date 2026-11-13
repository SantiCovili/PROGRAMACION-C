/*Se tiene un archivo binario que registra los sueldos de los empleados de una empresa
Con el siguiente diseño de registro
Legajo( int)
Nombre(45)
Antigüedad (en años int)
Sueldo básico (float)
Area( char 'A': administración, 'P': producción, 'C' comercial)
Realizar un programa en C que permita modificar directamente sobre el archivo (llamado sueldos.dat)los sueldos básicos de
los empleados según la siguiente escala de antigüedad
Mayor a 10 años 5%
Mayor a 20 años 6%
Una vez actualizado se debe generar un nuevo archivo, que solo contenga a los empleados del área administrativa
e informar la cantidad de registros de dicho archivo, utilizando las funciones vistas en el curso.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[46];
    int antiguedad;
    float sueldoBasico;
    char area;
}EMPLEADOS;

void procesarArchivos();
void nuevoArchivo();
FILE *abrirArchivo(char nombre[],char tipo[]);
int cantidadRegistros(FILE*archEmpleados, int tam);


int main()
{
    procesarArchivos();
    nuevoArchivo();
}

void procesarArchivos()
{
    FILE *archEmpleados;
    EMPLEADOS aux;
    float incremento,porcentaje;
    archEmpleados = abrirArchivo("sueldos.dat","r+b");
    fread(&aux,sizeof(aux),1,archEmpleados);
    while(!feof(archEmpleados))
    {
        if(aux.antiguedad>20)
        {
            porcentaje = 6;
            incremento = (aux.sueldoBasico * porcentaje)/100;
            aux.sueldoBasico += incremento;
            fseek(archEmpleados,-(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux,sizeof(aux),1,archEmpleados);
            fflush(archEmpleados);
        }
        else if(aux.antiguedad>10 && aux.antiguedad<=20)
        {
            porcentaje = 5;
            incremento = (aux.sueldoBasico * porcentaje)/100;
            aux.sueldoBasico += incremento;
            fseek(archEmpleados,-(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux,sizeof(aux),1,archEmpleados);
            fflush(archEmpleados);
        }
        fread(&aux,sizeof(aux),1,archEmpleados);
    }
    fclose(archEmpleados);
}

void nuevoArchivo()
{
    FILE *archEmpleados, *archAdministrativa;
    EMPLEADOS aux;
    int CantR;
    archEmpleados = abrirArchivo("sueldos.dat","rb");
    archAdministrativa = abrirArchivo("Administrativos.dat","w+b");
    fread(&aux,sizeof(aux),1,archEmpleados);
    while(!feof(archEmpleados))
    {
        if(aux.area == 'A')
        {
            fwrite(&aux, sizeof(aux), 1, archAdministrativa);
        }
        fread(&aux,sizeof(aux),1,archEmpleados);
    }
    CantR = cantidadRegistros(archAdministrativa,sizeof(aux));
    printf("Cantidad de registros del area administrativa: %d", CantR);
    fclose(archEmpleados);
    fclose(archAdministrativa);
}

int cantidadRegistros(FILE*archEmpleados, int tam)
{
    int cant;
    fseek(archEmpleados,0,SEEK_END);
    cant=ftell(archEmpleados)/tam;
    return cant;

}

FILE *abrirArchivo(char nombre[],char tipo[])
{
    FILE *fp;
    fp = fopen(nombre,tipo);
    if(fp == NULL)
    {
        printf("Error.");
        exit(1);
    }
    return fp;
}