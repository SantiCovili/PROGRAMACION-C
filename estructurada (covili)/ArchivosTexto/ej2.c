/*2. Realizar un programa que lea el contenido del archivo “cadenas.txt” creado en el punto anterior. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *AbrirArchivo(char nombre[], char tipo[]);

int main()
{
    FILE *ArchCadenas;
    char cadena[101];
    ArchCadenas = AbrirArchivo("cadenas.txt", "rt");
    fgets(cadena, sizeof(cadena), ArchCadenas);
    while(!feof(ArchCadenas))
    {
        printf("%s",cadena);
        fgets(cadena, sizeof(cadena), ArchCadenas);
    }
    fclose(ArchCadenas);
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