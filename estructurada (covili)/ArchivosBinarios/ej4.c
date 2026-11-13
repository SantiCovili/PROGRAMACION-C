/*Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un
porcentaje de incremento. El archivo se llama precios.dat y fue generado utilizando la siguiente
estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres) */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARCH_PRECIOS "precios.dat"
#define TAM 51

typedef struct 
{
    int codigo;
    float precio;
    char desc[TAM];
} PRECIOS;

void actualizar(float);
FILE *archivo(char[],char[]);
void leeryvalidarfloat(float *,int);
void mostrar();

int main()
{
    float porcentaje;

    printf("Lista de precios actual: \n");
    mostrar();

    printf("\nIngrese el porcentaje de incrementos: ");
    leeryvalidarfloat(&porcentaje,0);

    actualizar(porcentaje);

    printf("\nLista de precios actualizada: \n");
    mostrar();

    return 0;
}

FILE *archivo(char nombre[],char tipo[])
{
    FILE *fp;
    fp=fopen(nombre,tipo);
    if(fp==NULL)
    {
        printf("Error al abrir el archivo");
        getchar();
        exit(1);
    }
    return fp;
}

void leeryvalidarfloat(float *dato,int lim)
{
    scanf("%f",dato);
    while(*dato < lim)
    {
        printf("Error. Reingrese: ");
        scanf("%f",dato);
    }
}

void actualizar(float porcentaje)
{
    PRECIOS aux;
    FILE *fp;

    fp=archivo(ARCH_PRECIOS,"r+b");
    fread(&aux,sizeof(aux),1,fp);
    while(!feof(fp))
    {
        aux.precio = aux.precio * (1+porcentaje/100);
        //el fread avanzo el puntero: hay q retrodecer un registro para pisarlo
        fseek(fp,-(long)sizeof(aux),SEEK_CUR);
        fwrite(&aux,sizeof(aux),1,fp);
        
        fseek(fp,0,SEEK_CUR);
        fread(&aux,sizeof(aux),1,fp);
    }
    fclose(fp);
}

void mostrar()
{
    PRECIOS aux;
    FILE *fp;
    // rb: abre un archivo binario solamente para lectura.

    fp=archivo(ARCH_PRECIOS,"rb");
    fread(&aux,sizeof(aux),1,fp);
    while(!feof(fp))
    {
        printf("Codigo: %d - %s - Precios: %.2f\n",aux.codigo,aux.desc,aux.precio);
        fread(&aux,sizeof(aux),1,fp);
    }
    fclose(fp);

}