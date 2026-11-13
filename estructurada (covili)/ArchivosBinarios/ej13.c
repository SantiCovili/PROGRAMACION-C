/*13. La empresa RED VIAL S.A. desea controlar el flujo vehicular en sus cabinas de peaje a lo largo del mes.
Para ello se debe procesar la información provista por las barreras que se encuentra almacenada en el
archivo barreras.dat que contiene la siguiente información:
• Día (entero)
• Hora (0 a 24)
• Número de barrera (entero)
Dentro del archivo la información se encuentra ordenada por día y hora. Determinar:
a. La cantidad de vehículos por cada hora.
b. La cantidad de vehículos de cada día.
c. Ingresar por teclado los precios del peaje para horario normal y horario pico (de 7 a 11 y de 17 a
19). Con esos valores guardar un archivo con la recaudación de cada día. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 16
typedef struct ej13
{
    int dia;
    int hora;
    int numBarrera;
    
}BARRERAS;

typedef struct ej13
{
    float recaudacion;
}RECAUDACION;


FILE *AbrirArchivo(char nombre[], char tipo[]);
float leeryvalidarFloat(int lim);

int main()
{
    FILE* archBarreras, archRecaudacion;
    BARRERAS auxBarreras;
    RECAUDACION auxRecaudacion;
    int diaAnterior, horaAnterior, cantidadDia, cantidadHora;
    float PrecioPico, PrecioNormal, recaudacionDia;

    printf("Ingrese Precio en hora normal: ");
    PrecioNormal = leeryvalidarFloat(0);
    printf("Ingrese Precio en hora pico: ");
    PrecioPico = leeryvalidarFloat(0);
    archBarreras = AbrirArchivo("BARRERAS.dat", "rb");
    archRecaudacion = AbrirArchivo("recaudacion.dat", "wb");
    fread(&auxBarreras, sizeof(auxBarreras), 1, archBarreras);
    while(feof(archBarreras))
    {
        diaAnterior = auxBarreras.dia;
        cantidadDia=0;
        recaudacionDia=0;
        while(diaAnterior = auxBarreras.dia && feof(archBarreras))
        {
            horaAnterior = auxBarreras.hora;
            cantidadHora=0;
            while(horaAnterior = auxBarreras.hora && diaAnterior = auxBarreras.dia && feof(archBarreras))
            {
                cantidadHora++;
                if((auxBarreras.hora >= 7 && auxBarreras.hora <= 11) || (auxBarreras.hora >= 17 && auxBarreras.hora <= 19))
                {
                    recaudacionDia += PrecioPico;
                }
                else
                {
                    recaudacionDia += PrecioNormal;
                }
                fread(&auxBarreras, sizeof(auxBarreras), 1, archBarreras);
            }
            printf("\nLa cantidad de vehiculos en la hora %d es %d. ", horaAnterior, cantidadHora);
            cantidadDia += cantidadHora;
        }
        auxRecaudacion.recaudacion = recaudacionDia;
        fwrite(&auxRecaudacion, sizeof(auxRecaudacion), 1, archRecaudacion);
        printf("\nLa cantidad de vehiculos en el dia %d es %d.", diaAnterior, cantidadDia);
    }
    fclose(archBarreras);
    fclose(archRecaudacion);
    return 0;
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

float leeryvalidarFloat(int lim)
{
    float num;
    scanf("%f", &num);
    while (num<lim)
    {
        printf("Precio invalido. Reingrese: ");
        scanf("%f", &num);
    }
    return num;
}