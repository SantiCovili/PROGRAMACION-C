/*La librería "Ateneo Universitario" almacena la lista de libros en el archivo binario Libros.dat utilizando la siguiente estructura:
codigo (entero)
titulo (hasta 50 caracteres)
precio (float)
Para incentivar las ventas o ajustar márgenes, la librería requiere un programa en C que realice lo siguiente:
Ajuste condicional de precios: Solicite un valor límite de precio y un porcentaje de ajuste. Si el libro tiene un precio inferior al limite
ingresado, se le aplicará un incremento. Si supera o iguala dicho valor, el precio no se modificará. La actualización debe realizarse sobre el archivo Libros.dat.
Informar la cantidad total de libros registrados utilizando cálculo directo sobre la longitud total del archivo binario con las funciones vistas en el curso
Exportación en formato CSV: Generar el archivo libros_actualizados.csv con los títulos de las columnas (Codigo,Titulo,Precio) separado por comas.*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct LIBRERIA
{
    int cod;
    char titulo[51];
    float precio;
}LIBROS;

FILE *AbrirArchivo(char nombre[], char tipo[]);
void modificarArchivo();
void exportar();
int cantidadRegistros(FILE *archLibros, int lim);
void leeryvalidarpreciolimite(float *dato, int lim);
void leeryvalidarporcentaje(float *dato, int min, int max);
int main()
{
    modificarArchivo();
    exportar();
    return 0;
}

void modificarArchivo()
{
    FILE *archLibros;
    LIBROS aux;
    int  cantR;  
    float PrecioLimite, porcentaje, incremento;
    archLibros = AbrirArchivo("Libros.dat", "r+b");
    printf("Ingresar porcentaje de ajuste: ");
    leeryvalidarporcentaje(&porcentaje, 1, 100);
    printf("ingresar valor limite de precio: ");
    leeryvalidarpreciolimite(&PrecioLimite,0);
    fread(&aux, sizeof(aux),1,archLibros);
    while(!feof(archLibros))
    {
        if(aux.precio < PrecioLimite)
        {
            incremento = (aux.precio * porcentaje)/100.0;
            aux.precio += incremento;
            fseek(archLibros, -(long)sizeof(aux),SEEK_CUR);
            fwrite(&aux, sizeof(aux), 1 ,archLibros);
            fflush(archLibros);
        }
        fread(&aux, sizeof(aux),1,archLibros);
    }
    cantR = cantidadRegistros(archLibros,sizeof(aux));
    printf("cantidad de libros registrados: %d", cantR);
    fclose(archLibros);

}

void exportar()
{
    FILE *archLibros, *archExp;
    LIBROS aux;
    archLibros = AbrirArchivo("Libros.dat","rb");
    archExp = AbrirArchivo("libros_actualizados.csv", "wt");
    fprintf(archExp,"Codigo,Titulo,Precio\n");
    fread(&aux,sizeof(aux),1,archLibros);
    while(!feof(archLibros))
    {
        fprintf(archExp,"%d,%s,%f\n",aux.cod,aux.titulo,aux.precio);
        fread(&aux,sizeof(aux),1,archLibros);
    }
    fclose(archLibros);
    fclose(archExp);

}


FILE *AbrirArchivo(char nombre[], char tipo[])
{
    FILE *fp;
    fp=fopen(nombre, tipo);
    if(fp==NULL)
    {
        printf("Error, no se pudo abrir el archivo \n");
        getch();
        exit(1);
    }
    return(fp);
}

int cantidadRegistros(FILE *archLibros, int tam)
{
    int cant;
    fseek(archLibros, 0 , SEEK_END);
    cant = ftell(archLibros)/tam;
    return cant;
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

void leeryvalidarpreciolimite(float *dato, int lim)
{
    scanf("%f", dato);
    while(*dato < lim)
    {
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
}