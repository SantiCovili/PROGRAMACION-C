/*
Un su almacena su información de productos en un archivo binario.

Cada registro dek archivo tiene el siguiente formato:
-Codigo (int)
-Nombre (char[40])
-Stock (int)
-Precio (float)
-Rubro (char) 'A'= Alimentos, 'B'= Bebidas, 'L'= Limpieza

El archivo ya existe y contiene información cargada previamente. Se pide:
a) Nodificar el archivo en el mismo lugar, aplicando el siguiente aumento según el rubro:
    Rubro A -> aumento del 8%
    Rubro B -> sin aumento
    Rubro C -> aumento del 3%
b) Crear un nuevo archivo binario que contenga solo los productos cuyo stock sea menor o igual a 15 unidades. Este archivo debe contener el mismo tipo de registro.
c) Informar la cantidad total de registros del archivo original utilizando las funciones vistas en el curso. No se permite ir leyendo para contarlos.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int cod;
    char nombre[41];
    int stock;
    float precio;
    char rubro;
}PRODUCTOS;


FILE *AbrirArchivo(char nombre[], char tipo[]);
void procesarArchivos();
int cantidadRegistros(FILE *arch, int tam);

int main()
{
    procesarArchivos();
    return 0;
}

void procesarArchivos()
{
    FILE *archProductos, *archProductos2;
    PRODUCTOS aux;
    int cantR;
    float incremento;
    archProductos = AbrirArchivo("productos.dat","r+b");
    archProductos2 = AbrirArchivo("productos2.dat","wb");
    fread(&aux,sizeof(aux),1,archProductos);
    while(!feof(archProductos))
    {
        if(aux.rubro == 'A')
        {
            incremento = (aux.precio * 8)/100;
            aux.precio += incremento;
            fseek(archProductos, -(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux,sizeof(aux),1,archProductos);
            fflush(archProductos);
        }
        if(aux.rubro == 'C' || aux.rubro == 'L')
        {
            incremento = (aux.precio * 3)/100;
            aux.precio += incremento;
            fseek(archProductos, -(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux,sizeof(aux),1,archProductos);
            fflush(archProductos);            
        }
        if(aux.stock<=15)
        {
            fwrite(&aux,sizeof(aux),1,archProductos2);
        }
        fread(&aux,sizeof(aux),1,archProductos);
    }
    cantR = cantidadRegistros(archProductos, sizeof(aux));
    printf("cantidad de registros del archivo original: %d", cantR);
    fclose(archProductos);
    fclose(archProductos2);

}

FILE *AbrirArchivo(char nombre[], char tipo[])
{
    FILE *fp;
    fp=fopen(nombre, tipo);
    if(fp==NULL)
    {
        printf("Error, no se pudo abrir el archivo \n");
        exit(1);
    }
    return(fp);
}

int cantidadRegistros(FILE *arch, int tam)
{
    int cant;
    fseek(arch, 0 , SEEK_END);
    cant = ftell(arch)/tam;
    return cant;
}