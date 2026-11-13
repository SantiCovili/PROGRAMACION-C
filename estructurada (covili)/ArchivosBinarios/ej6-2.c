/*6. Dado el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Realizar un programa que permita eliminar productos dado su código*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 51
typedef struct 
{
    int cod;
    float precio;
    char desc[TAM];
}PRODUCTOS;

FILE* AbrirArchivo(char[],char[]);
void leeryvalidarint(int *,int);
void eliminar(int codigo);

int main()
{
    int cod;
    printf("ingresar codigo del producto a eliminar(finaliza con codigo = 0)");
    leeryvalidarint(&cod, 0);
    eliminar(cod);
    return 0;

}

void eliminar(int cod)
{
    FILE *archTemp, *archOrig;
    PRODUCTOS aux;
    int encontrado=0;
    archOrig = AbrirArchivo("Productos.dat","rb");
    archTemp = AbrirArchivo("Productos.tmp","wb");
    fread(&aux,sizeof(aux),1,archOrig);
    while(!feof(archOrig))
    {
        if(aux.cod != cod)
        {
            fwrite(&aux, sizeof(aux),1,archTemp);
        }
        else
        {
            encontrado=1;
        }
        fread(&aux,sizeof(aux),1,archOrig);

    }
    fclose(archOrig);
    fclose(archTemp);
    if(encontrado==1)
    {
        remove("Productos.dat");
        rename("Productos.tmp", "Productos.dat");
    }
    else
    {
        remove("Productos.tmp");
    }
}

FILE*AbrirArchivo(char nombre[],char tipo[])
{
    FILE* fp;
    fp = fopen(nombre,tipo);
    if(fp== NULL)
    {
        printf("Error.");
        exit(1);
    }
    return fp;
}

void leeryvalidarint(int *dato,int lim)
{
    scanf("%d",dato);
    while(*dato < lim)
    {
        printf("Error. Reingrese: ");
        scanf("%d",dato);
    }
}