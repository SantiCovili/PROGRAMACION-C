/*Ejercicio 2. Se dispone del archivo binario examenes.dat, ordenado por curso, con los siguientes datos por examen rendido:

Curso (entero)
Legajo del alumno (entero)
Nota (float, de 0 a 10)

Se solicita:
a) Para cada curso, informar la cantidad de exámenes rendidos y el promedio de notas. El cálculo del promedio debe hacerse en otra función.
b) Informar el curso con el mejor promedio.
c) Generar un archivo binario resumen.dat con un registro por curso, que contenga el número de curso y su promedio.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int curso;
    int legajo;
    float nota;
}EXAMENES;

typedef struct 
{
    int curso;
    float promedio;
}RESUMEN;

void procesarArchivo();
void nuevoArchivo();
FILE *abrirArchivo(char nombre[],char tipo[]);
float promedio(float notas, int cantE);

int main()
{
    procesarArchivo();
    return 0;
}

void procesarArchivo()
{
    FILE *archExamenes, *archResumen;
    EXAMENES aux;
    RESUMEN aux2;
    int cantE, cursoAnterior, MejorPromedio=-1, cursoMejorPromedio;
    float promedioNotas, totalNotas;
    archExamenes = abrirArchivo("Examenes.dat","rb");
    archResumen = abrirArchivo("Resumen.dat","wb");
    fread(&aux,sizeof(aux),1,archExamenes);
    while(!feof(archExamenes))
    {
        cursoAnterior = aux.curso;
        cantE=0;
        totalNotas=0;
        while(!feof(archExamenes) && cursoAnterior == aux.curso)
        {
            totalNotas += aux.nota;
            cantE++;
            fread(&aux,sizeof(aux),1,archExamenes);
        }
        printf("en el curso %d la cantidad de examenes rendidos fue de: %f\n ",cursoAnterior,totalNotas);
        promedioNotas=promedio(totalNotas,cantE);
        printf("Promedio de notas:%f",promedioNotas);
        aux2.curso = cursoAnterior;
        aux2.promedio = promedioNotas;
        fwrite(&aux2,sizeof(aux2),1,archResumen);
        if(promedioNotas>MejorPromedio)
        {
            cursoMejorPromedio = cursoAnterior;
        }
    }
    printf("el curso con mejor promedio fue: %d",cursoMejorPromedio);
}


float promedio(float notas, int cantE)
{
    int prom;
    prom = notas/cantE;
    return prom;
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