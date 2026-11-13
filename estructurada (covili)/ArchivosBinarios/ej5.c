/*5. Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma
individual a cada uno de sus productos.
Los productos que están guardados en el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 51

typedef struct 
{
    int codigo;
    float precio;
    char desc[TAM];
} PRODUCTOS;
void actualizar();
void mostrar();
void leeryvalidarfloat(float *dato,int lim);
FILE *archivo(char nombre[],char tipo[]);
void leeryvalidarint(int *dato, int lim);

int main()
{
    actualizar();
    mostrar();
    return 0;
}

void actualizar()
{
    int codigo;
    int pos=0;
    float nuevoprecio;
    PRODUCTOS aux;
    FILE *fp;

    printf("Ingrese el codigo del producto (0 para finalizar): ");
    leeryvalidarint(&codigo,0);

    fp=archivo("PRODUCTOS.dat","r+b");
    while(codigo!=0)
    {
        pos=0;

        while (feof(fp)==0 && pos==0)
        {
            fread(&aux,sizeof(PRODUCTOS),1,fp);

            if (codigo==aux.codigo)
            {
                pos=1;  
                printf("Ingrese el nuevo precio: ");
                leeryvalidarfloat(&nuevoprecio,0);
                
                aux.precio= nuevoprecio;
                fseek(fp,-(long)sizeof(aux),SEEK_CUR);
                fwrite(&aux,sizeof(PRODUCTOS),1,fp);
                fseek(fp,0,SEEK_CUR);
                
            }
        }
        if(pos==0)
        {
            printf("El producto no existe.");
        }
        rewind(fp); //rewind() sirve para volver el puntero del archivo al principio.
        printf("Ingrese el codigo del producto (0 para finalizar): ");
        leeryvalidarint(&codigo,0);  
    }
    fclose(fp);
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

FILE *archivo(char nombre[],char tipo[])
{
    FILE *fp;
    fp=fopen(nombre,tipo);
    if (fp==NULL)
    {
        printf("Error al abrir el archivo.");
        getchar();
        exit(1);
    }
    return fp;
}

void leeryvalidarint(int *dato,int lim)
{
    scanf("%d",dato);
    while (*dato<lim)
    {
        printf("Error en el dato. Reingrese: ");
        scanf("%d",dato);
    }
}

void mostrar()
{
    PRODUCTOS aux;
    FILE *fp;

    fp=archivo("PRODUCTOS.dat","rb");
    fread(&aux,sizeof(aux),1,fp);
    while (feof(fp)==0)
    {
        printf("Codigo: %d - %s - Precio: %.2f\n",aux.codigo,aux.desc,aux.precio);
        fread(&aux,sizeof(aux),1,fp);
    }
    fclose(fp);
}