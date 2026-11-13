/*En una ferretería se cuenta con un archivo binario llamado Productos.dat que contiene los productos comercializados.
Se definió la siguiente estructura para el archivo:
codigo (entero)
descripcion (hasta 50 caracteres)
categoria (entero: 1 = Herramientas, 2 = Pinturas, 3 = Electricidad)
precio (float)
Debido a cambios en los costos de proveedores, se solicita realizar un programa en C que:
Ajuste masivo de precios: Solicite por teclado un porcentaje de aumento y el número de categoría a la cual aplicarlo. Actualice en el propio archivo Productos.dat
únicamente el precio de los productos que pertenezcan a esa categoría.
Conteo e informe: Informe por pantalla la cantidad total de registros grabados
en el archivo y cuántos productos pertenecen a la categoría actualizada.
Exportación: Genere un archivo de texto plano denominado productos_actualizados.csv con encabezados
(Codigo;Descripcion;Categoria;Precio) que contenga el catálogo
completo con los precios ya ajustados.*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct{
    int codigo;
    char desc[51];
    int categoria;
    float precio;
}PRODUCTOS;

FILE *AbrirArchivo(char nombre[], char tipo[]);
void procesarArchivo();
void exportar();
void leeyvalidaIntE2(float *dato, int min, int max);
void leeyvalidaIntE3(int *dato);
int cantidadRegistros(FILE *archProductos, int tam);

int main()
{
    procesarArchivo();
    exportar();
    return 0;
}

void procesarArchivo()
{
    FILE *archProductos;
    archProductos = AbrirArchivo("Productos.dat","r+b");
    PRODUCTOS aux;
    int catAux, cantidad = 0, cantR;
    float porcentaje, incremento;
    printf("Ingrese porcentaje de incremento(0-100): ");
    leeyvalidaIntE2(&porcentaje, 0, 100);
    printf("Ingrese categoria (H-P-E )a cual aplicar el incremento en numero (1-2-3): ");
    leeyvalidaIntE3(&catAux);
    fread(&aux, sizeof(aux), 1, archProductos);
    while(!feof(archProductos))
    {
        if(aux.categoria==catAux)
        {
            incremento = (aux.precio * porcentaje)/100.0;
            aux.precio += incremento;
            cantidad++;
            fseek(archProductos, -(long)sizeof(aux), SEEK_CUR);
            fwrite(&aux, sizeof(aux), 1, archProductos);
            fflush(archProductos);
        }
        fread(&aux, sizeof(aux), 1, archProductos);
    }
    cantR=cantidadRegistros(archProductos, sizeof(aux));
    fclose(archProductos);
    printf("La cantidad de registros es %d\n", cantR);
    printf("La cantidad de productos actualizados para la categoria elegida es %d \n", cantidad);    
}

void exportar()
{
    PRODUCTOS aux;
    FILE *archProductos, *archExportar;
    archProductos = AbrirArchivo("Productos.dat", "rb");
    archExportar = AbrirArchivo("productos_actualizados.csv", "wt");
    fprintf(archExportar, "Codigo;Descripcion;Categoria;Precio\n");
    fread(&aux, sizeof(aux), 1, archProductos);
    while(!feof(archProductos))
    {
        fprintf(archExportar,"&d;%s;%d;%.2f\n",aux.codigo,aux.desc,aux.categoria,aux.precio);
        fread(&aux, sizeof(aux), 1, archProductos);
    }
    fclose(archProductos);
    fclose(archExportar);    
}

int cantidadRegistros(FILE *archProductos, int tam)
{
    int cant;
    fseek(archProductos,0,SEEK_END);
    cant=ftell(archProductos)/tam;
    return cant;
}
void leeyvalidaIntE2(float *dato, int min, int max)
{
    scanf("%f", dato);
    while(*dato<min || *dato>max){
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
}

void leeyvalidaIntE3(int *dato){
    scanf("%d", dato);
    while(*dato!=1 && *dato!=2 && *dato!=3){
        printf("Error. Reingrese:");
        scanf("%d", dato);
    }
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