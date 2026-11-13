/*Ej 1. Realizar un programa en “C” que contenga una función llamada registrarMedicion que permita cargar por teclado los datos de un reporte meteorológico:

Número de estación meteorológica (entero).
Temperatura registrada en °C (flotante).
Categoría del clima: 'S' para soleado, 'N' para nublado, 'L' para lluvioso (carácter).
La función no debe retornar ningún valor. Las tres variables deben estar declaradas en el main, ser modificadas dentro de la 
función y ser mostradas en la pantalla únicamente desde el main.*/

#include <stdio.h>


void leeryvalidarint(int *dato, int largo);
void leeryvalidarFloat(float *dato, int min, int max);
void leeryValidarCategoria(char *dato);
void regisrarMedicion(int* num, float* temp, char* cat);

int main()
{
    int num;
    float temp;
    char cat;
    regisrarMedicion(&num, &temp, &cat);
    printf("-----REPORTE----:\n");
     printf("El numero de estacion es %d\n", num);
    printf("La temperatura es %.2f°C\n", temp);
    printf("La categoria es %c\n", cat);
    
   
    return 0;
}

void regisrarMedicion(int* num, float* temp, char* cat)
{
    printf("ingrese Número de estacion meteorologica:");
    leeryvalidarint(num, 1);
    printf("Temperatura registrada en °C:");
    leeryvalidarFloat(temp, -50,50);
    printf("Ingrese categoria del clima:");
    leeryValidarCategoria(cat);

}

void leeryvalidarint(int *dato, int largo)
{
    scanf("%d", dato);
    while(*dato<largo)
    {
        printf("Error. Reingrese:");
        scanf("%d", dato);
    }
  
}

void leeryvalidarFloat(float *dato, int min, int max)
{
    scanf("%f", dato);
    while(*dato<min || *dato>max)
    {
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
  
}

void leeryValidarCategoria(char *dato)
{
    fflush(stdin);
    scanf(" %c",dato);
    while(*dato != 'S' && *dato != 'N' && *dato != 'L')
    {
        printf("Categoria invalida. Reingrese (S/N/L): ");
        scanf(" %c",dato);
    }
}