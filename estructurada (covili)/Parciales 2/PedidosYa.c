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

typedef struct
{
    int zona;
    float pesoTotal;
    
}REGISTRO;

void modificarArchivo();
FILE *AbrirArchivo(char nombre[], char tipo[]);


int main()
{
    modificarArchivo();
    return 0;
}

void modificarArchivo()
{
    FILE *archRepartos, *archPesoTotal;
    REPARTOS auxRepartos;
    REGISTRO auxRegistro;
    int zonaAnterior, primeraZona=1, zonaMayorPeso;
    float pesoAcumuladoZona, mayorPeso=0;
    archRepartos = AbrirArchivo("Repartos.dat","rb");
    archPesoTotal = AbrirArchivo("PesoTotal.dat","wb");
    fread(&auxRepartos, sizeof(auxRepartos), 1 , archRepartos);
    while(!feof(archRepartos))
    {
        zonaAnterior = auxRepartos.zona;
        pesoAcumuladoZona=0;
        while(!feof(archRepartos) && zonaAnterior == auxRepartos.zona)
        {
            pesoAcumuladoZona += auxRepartos.peso;
            fread(&auxRepartos,sizeof(auxRepartos),1,archRepartos);       
        }
        
        if(pesoAcumuladoZona < LIMITE_KILOS)
        {
            printf("Zona %d con %.2f kg\n", zonaAnterior,pesoAcumuladoZona);
        }
       
        if(primeraZona==1 || pesoAcumuladoZona > mayorPeso)
        {
            mayorPeso = pesoAcumuladoZona;
            zonaMayorPeso = zonaAnterior;
            primeraZona = 0;
        }
        auxRegistro.zona=zonaAnterior;
        auxRegistro.pesoTotal=pesoAcumuladoZona;
        fwrite(&auxRegistro,sizeof(auxRegistro),1,archPesoTotal);
    }
    printf("La zona %d es la que mayor peso tiene con %.2f\n",zonaMayorPeso,mayorPeso);
    fclose(archRepartos);
    fclose(archPesoTotal);
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
    return fp;
}
