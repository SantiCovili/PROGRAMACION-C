/*Ejercicio 1. Se dispone del archivo binario empleados.dat con los siguientes datos por empleado:
Legajo (entero)
Nombre (50 caracteres)
Antigüedad (entero, en años)
Sueldo (float)
Turno (carácter: ‘M’ mañana, ‘T’ tarde, ’N’ noche)

Se solicita:
a) Actualizar el sueldo de los empleados del turno noche, aplicando un aumento del porcentaje ingresado por teclado. 
La actualización debe realizarse sobre el propio archivo, mientras se lee.
b) Calcular e informar, mediante funciones, la cantidad total de registros del archivo.
c) Copiar a otro archivo, veteranos.dat, el registro completo de todos los empleados con 20 años de antigüedad o más.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[51];
    int antiguedad;
    float sueldo;
    char turno;
}EMPLEADOS;

void procesarArchivo();
void copiarArchivo();
int cantidadRegistros(FILE*archEmpleados, int tam);
void leeryvalidarporcentaje(float *dato, int min, int max);

FILE *abrirArchivo(char nombre[],char tipo[]);

int main()
{
    procesarArchivo();
    copiarArchivo();
    return 0;
}

void procesarArchivo()
{
    FILE *archEmpleados;
    EMPLEADOS aux;
    float incremento, porcentaje;
    int cantR;
    archEmpleados = abrirArchivo("empleados.dat","r+b");
    printf("ingresar porcentaje (de 0 a 100) de aumento del sueldo de los empleados del turno noche:");
    leeryvalidarporcentaje(&porcentaje, 1, 100);
    fread(&aux,sizeof(aux),1,archEmpleados);
    while(!feof(archEmpleados))
    {
        if(aux.turno == 'N')
        {
            incremento = (aux.sueldo * porcentaje)/100;
            aux.sueldo += incremento;
            fseek(archEmpleados,-(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux,sizeof(aux),1,archEmpleados);
            fflush(archEmpleados);
        }
        fread(&aux,sizeof(aux),1,archEmpleados);
    }
    cantR = cantidadRegistros(archEmpleados, sizeof(aux));
    printf("la cantidad total de registros del archivo: %d", cantR);
    fclose(archEmpleados);

}

void copiarArchivo()
{
    FILE *archEmpleados, *archVeteranos;
    EMPLEADOS aux;  
    archEmpleados = abrirArchivo("empleados.dat","rb");
    archVeteranos = abrirArchivo("veteranos.dat","wb");
    fread(&aux,sizeof(aux),1,archEmpleados);
    while(!feof(archEmpleados))
    {
        if(aux.antiguedad >= 20)
        {
            fwrite(&aux,sizeof(aux),1,archVeteranos);
        }
        fread(&aux,sizeof(aux),1,archEmpleados);
    }
    fclose(archEmpleados);
    fclose(archVeteranos);
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

void leeryvalidarporcentaje(float *dato, int min, int max)
{
    scanf("%f", dato);
    while((*dato < min || * dato > max) && *dato != 0)
    {
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
}