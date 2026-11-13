/*1. Realizar un programa que genere el archivo “cadenas.txt” que guarde cadenas de caracteres que se ingresan
por teclado hasta ingresar la cadena “FINALIZAR”. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *AbrirArchivo(char nombre[], char tipo[]);

int main()
{
    FILE *ArchCadena;
    char cadena[100];
    ArchCadena = AbrirArchivo("cadenas.txt", "wt");
    printf("ingrese cadena de caracteres - (ingrese FINALIZAR para terminar)");
    fgets(cadena,100,stdin);
    while(strcmp(cadena, "FINALIZAR\n")!=0)
    {
        fputs(cadena,ArchCadena);
        printf("ingrese cadena de caracteres - (ingrese FINALIZAR para terminar)");
        fgets(cadena,100,stdin);
    }
    fclose(ArchCadena);
    return 0;
}

FILE *AbrirArchivo(char nombre[], char tipo[])
{
    FILE *fp;
    fp = fopen(nombre, tipo);
    if(fp == NULL)
    {
        printf("Error al abrir archivo");
        exit(1);
    }
    return fp;
}