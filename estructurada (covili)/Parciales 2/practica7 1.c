/*Ejercicio 1. El banco “Del Plata” tiene el archivo binario cuentas.dat con los siguientes datos por cuenta:
Número de cuenta (entero)
Titular (hasta 40 caracteres)
Tipo (carácter: ‘C’ cuenta corriente, ‘A’ caja de ahorro)
Saldo (float)
Cantidad de movimientos (entero)

Se solicita:
a) Ingresar por teclado un monto fijo de cargo de mantenimiento (mayor a 0) y descontarlo del saldo de todas las cuentas corrientes (‘C’). 
La modificación debe hacerse sobre el propio archivo, mientras se lee.
b) Copiar a otro archivo, descubiertos.dat, el registro completo de las cuentas cuyo saldo haya quedado negativo después del cargo.
c) Informar, mediante una función, la cantidad de registros de descubiertos.dat.*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 41

typedef struct 
{
    int numCuenta;
    char titular[TAM];
    char tipo;
    float saldo;
    int cantMov;

}BANCO;

void procesarArchivo();
FILE *AbrirArchivo(char nombre[],char tipo[]);
void leeryvalidarmonto(float*,int);
int cantidadRegistros(FILE *arch, int tam);



int main()
{
    procesarArchivo();
    return 0;
}

void procesarArchivo()
{
    FILE *archBanco, *archDescubiertos;
    BANCO aux;
    int cantR;
    float  monto;
    archBanco = AbrirArchivo("cuentas.dat","r+b");
    archDescubiertos = AbrirArchivo("descubiertos.dat","wb");
    printf("ingresar monto fijo de cargo de mantenimiento:"); 
    leeryvalidarmonto(&monto,0);
    fread(&aux,sizeof(aux),1,archBanco);
    while(!feof(archBanco))
    {
        while(!feof(archBanco))
        {
            if(aux.tipo == 'C')
            {
                aux.saldo -= monto;
                fseek(archBanco,-(long)sizeof(aux),SEEK_CUR);
                fwrite(&aux,sizeof(aux),1,archBanco);
                fflush(archBanco);
            }
            fread(&aux,sizeof(aux),1,archBanco);
        }
        if(aux.saldo < 0)
        {
            fwrite(&aux,sizeof(aux),1,archDescubiertos);
        }
    }
    cantR = cantidadRegistros(archDescubiertos, sizeof(aux));
    printf("Cantidad de registros:%d",cantR);
    fclose(archBanco);
    fclose(archDescubiertos);
}

void leeryvalidarmonto(float*dato,int lim)
{
    scanf("%f", dato);
    while(*dato<=lim)
    {
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
}

int cantidadRegistros(FILE *arch, int tam)
{
    int cant;
    fseek(arch,0,SEEK_END);
    cant=ftell(arch)/tam;
    return cant;    
}

FILE *abrirArchivo(char nombre[],char tipo[])
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