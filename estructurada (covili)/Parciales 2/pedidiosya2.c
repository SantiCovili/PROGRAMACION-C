/*
En la empresa “Pedido Ya Mismo” tienen el  archivo Repartos.dat con los siguientes datos:
 • Zona (entero)
 • Descripción (de hasta 50 caracteres)
 • Peso (float) en kilos por pedido
 Sabemos que el archivo está ordenado por zona y necesitamos conocer los siguientes datos:
  a. Las zonas que tengan menos de 15 kg en total.
  b. La zona que haya acumulado el mayor peso total de envíos.
  c. Generar un nuevo archivo binario llamado PesoTotal.dat que contenga un registro por cada zona
   incluyendo la zona y el peso total por zona.*/
#include <stdio.h>
#include <stdlib.h>
#define LIMITE_KILOS 15
#define TAM 51
typedef struct 
{
    int zona;
    char desc[TAM];
    float peso;
}REPARTOS;

typedef struct pedidiosya2
{
    int zona;
    float pesoTotal;
}PESOTOTAL;

void procesarArchivo();
FILE *abrirArchivo(char nombre[], char tipo[]);
void nuevoArchivo();


int main()
{
    procesarArchivo();
    nuevoArchivo();
    return 0;
}

void procesarArchivo()
{
    FILE *archRepartos;
    REPARTOS aux;
    int zonaAnterior, primeraZona=1, zonaMayorPeso;
    float pesoAcumulado, MayorPeso;
    archRepartos = abrirArchivo("Repartos.dat", "rb");
    fread(&aux,sizeof(aux),1,archRepartos);
    while(!feof(archRepartos))
    {
        zonaAnterior = aux.zona;
        pesoAcumulado = 0;
        while(!feof(archRepartos) && aux.zona == zonaAnterior)
        {
            pesoAcumulado +=aux.peso;
            fread(&aux,sizeof(aux),1,archRepartos);
        }
        if(pesoAcumulado < LIMITE_KILOS)
        {
            printf("la zona %d tiene menos de 15kg\n", zonaAnterior);
        }
        if(primeraZona == 1 || MayorPeso<pesoAcumulado)
        {
            MayorPeso = pesoAcumulado;
            zonaMayorPeso = zonaAnterior;
            primeraZona=0;
        }
    }
    printf("la zona %d es la que acumulo mas peso\n", zonaMayorPeso);
    fclose(archRepartos);
}

void nuevoArchivo()
{
    FILE *archRepartos, *archPesoTotal;
    REPARTOS auxRepartos; 
    PESOTOTAL auxPeso;
    int zonaAnterior;
    float pesoAcumulado;
    archRepartos = abrirArchivo("Repartos.dat","rb");
    archPesoTotal = abrirArchivo("PesoTotal.dat", "wb");
    fread(&auxRepartos,sizeof(auxRepartos),1,archRepartos);
    while(!feof(archRepartos))
    {
        zonaAnterior=auxRepartos.zona;
        pesoAcumulado = 0;
        while(!feof(archRepartos) && zonaAnterior==auxRepartos.zona)
        {
            pesoAcumulado+=auxRepartos.peso;
            fread(&auxRepartos,sizeof(auxRepartos),1,archRepartos);
        }
        auxPeso.zona = zonaAnterior;
        auxPeso.pesoTotal = pesoAcumulado;
        fwrite(&auxPeso,sizeof(auxPeso),1,archPesoTotal);
    }
    fclose(archRepartos);
    fclose(archPesoTotal);
}

FILE *abrirArchivo(char nombre[], char tipo[])
{
    FILE *fp;
    fp=fopen(nombre, tipo);
    if(fp==NULL)
    {
        printf("Error, no se pudo abrir el archivo \n");
        exit(1);
    }
    return fp;
}