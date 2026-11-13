/*Ejercicio 1.
Se tiene un archivo binario que registra el estado de diferentes productos en un almacén, con el siguiente diseño de registro:
ID Producto (entero)
Descripción (40 caracteres máximo)
Ubicación (char ’N’: Norte, ‘S’: Sur, ‘E’: Este, ‘O’: Oeste)
Cantidad Disponible (entero)

Se ha detectado que los productos ubicados en la zona ‘O’ (Oeste) del depósito deben ser reabastecidos. 
A estos productos se les debe incrementar la Cantidad Disponible en 100 unidades.
a) Realizar un programa en “C” que permita modificar directamente sobre el archivo las cantidades 
disponibles de los productos de la ubicación.*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 41

typedef struct 
{
    int id;
    char desc[TAM];
    char ubicacion;
    int cantDisp;
}PRODUCTOS;

FILE *AbrirArchivo(char nombre[],char tipo[]);
void procesarArchivo();

int main()
{
    procesarArchivo();
    return 0;
}
FILE *AbrirArchivo(char nombre[],char tipo[])
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

void procesarArchivo()
{
    FILE *archProductos;
    PRODUCTOS aux;
    archProductos = AbrirArchivo("Productos.dat", "r+b");
    fread(&aux,sizeof(aux),1,archProductos);
    while(!feof(archProductos))
    {
        if(aux.ubicacion == 'O')    
        {
            aux.cantDisp +=100;
            fseek(archProductos,-(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux,sizeof(aux),1,archProductos);
            fflush(archProductos);
        }
        fread(&aux,sizeof(aux),1,archProductos);
    }
    fclose(archProductos);
}