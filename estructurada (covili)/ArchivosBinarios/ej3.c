/*3. El archivo ventas.dat contiene información histórica de las ventas realizadas por una empresa desde el
año 2014 al 2023. El formato de registro es el siguiente:
• Mes (entero)
• Año (entero)
• Dia (entero)
• Código de Producto (entero)
• Importe de la venta (real)
Se pide ingresar un rango de años y mostrar un cuadro ventas realizadas en cada mes de cada año. Por
ejemplo, si se ingresa desde 2020 a 2022 debe mostrar lo siguiente:
Mes 1 Mes 2 Mes 3 ……. Mes 12
2020 xxx xxx xxx xxx
2021 xxx xxx xxx xxx
2022 xxx xxx xxx xxx
Una vez configurados los años debe poder cambiarse la vista para en lugar de visualizar cantidad de
ventas, ver el detalle de importe por mes/año. El usuario podrá alternar las vistas las veces que quiera.
Agregar una opción para finalizar el programa.*/

#include <stdio.h>
#include <stdlib.h>
#define ANIO_MIN 2014
#define ANIO_MAX 2023
#define MESES 12

typedef struct ej3
{
    int anio;
    int mes;
    int dia;
    int codigo;
    float importe;
}VENTAS;

FILE* archivo(char[], char[]);
void FILE* archivo(char[], char[]);leeryvalidarint(int*, int, int);
void leeryvalidarfloat(float*, int);
void cargarVentas(int cant[][MESES], float imp[][MESES], int anioDesde, int anioHasta);
void mostrarCantidades(int cant[][MESES], int anioDesde, int anioHasta);
void mostrarImportes(float imp[][MESES], int anioDesde, int anioHasta);

int main()
{
    int anioDesde, anioHasta;
    int opcion;

    printf("ingrese anio desde:%d a %d", ANIO_MIN, ANIO_MAX);
    leeryvalidarint(&anioDesde, ANIO_MIN, ANIO_MAX);
     printf("ingrese anio hasta:%d a %d", ANIO_MIN, ANIO_MAX);
    leeryvalidarint(&anioHasta, anioDesde, ANIO_MAX);

    int totalAnios = anioHasta - anioDesde ;
    int cantVentas[totalAnios][MESES];
    float impVentas[totalAnios][MESES];
    cargarVentas(cantVentas, impVentas, anioDesde, anioHasta);
    mostrarCantidades(cantVentas, anioDesde, anioHasta);

    do
    {
      printf("\n--- OPCIONES DE VISTA ---\n");
      printf("1. Ver Cantidad de ventas\n");
      printf("2. Ver Importe recaudado\n");
      printf("3. Finalizar programa\n");
      printf("Seleccione una opcion: ");
      leeryvalidarint(&opcion, 1, 3);  
      switch (opcion)
        {
            case 1:
                mostrarCantidades(cantVentas, anioDesde, anioHasta);
                break;
            case 2:
                mostrarImportes(impVentas, anioDesde, anioHasta);
                break;
            case 3:
                printf("\nPrograma finalizado.\n");
                break;
        }

    }while(opcion!=3);


}

void leeryvalidarint(int*dato, int min, int max)
{
    scanf("%d", dato);
    while((*dato < min || *dato > max) && *dato != 0)
    {
        printf("Error. Reingrese:");
        scanf("%d", dato);
    }
}

void leeryvalidarfloat(float*dato, int lim)
{
    scanf("%f", dato);
    while(*dato >= lim)
    {
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
}

FILE* archivo(char nombre[], char tipo[])
{
    FILE* fp;
    fp = fopen(nombre,tipo);
    if(fp==NULL)
    {
        printf("error al abrir archivo");
        getchar();
        exit(1);
    }
    return fp;
}

void cargarVentas(int cant[][MESES], float imp[][MESES], int anioDesde, int anioHasta)
{
    filas =  anioHasta - anioDesde + 1;
    int i, j;
    VENTAS aux;
    FILE *fp;
    for(i=0; i < filas; i++)
    {
        for(j=0; j < MESES; j++0)
        {
            cant[i][j] = 0;
            imp[i][j] = 0.0;
        }
    }
    fp= archivo(ARCH_VENTAS, "rb");
    fread(&aux, sizeof(aux), 1, fp)
    while(feod(fp))
    {
        if()
    }
}