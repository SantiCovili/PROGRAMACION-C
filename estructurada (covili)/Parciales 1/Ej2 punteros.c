/*Ej 2. Un taller mecánico necesita un programa para ordenar y mostrar la lista de sus 3 reparaciones del día de menor a mayor costo.
Se solicita en el programa principal (main) Declarar el arreglo, cargar las 3 reparaciones (Código, Descripción y Costo), 
llamar a la función de ordenamiento y mostrar el listado final ordenado.
Escribir una función de tipo void llamada intercambiar que reciba los punteros a dos estructuras de tipo Reparacion 
e intercambie sus valores utilizando una variable auxiliar.
Implementar una función que reciba el arreglo de reparaciones y ordene los elementos en forma ascendente según el costo, 
haciendo uso obligatorio de la función intercambiar. -*/

#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct 
{
   int cod;
   char desc[51];
   float costo;

}REPARACIONES;
 
void leeryvalidarint(int*dato);
void leertexto(char texto[], int largo);
void leeryvalidartexto(char texto[],int largo);
void leeryvalidarfloat(float*dato, int lim);
void burbujeo(REPARACIONES datos[], int ce);
void mostrarreparaciones(REPARACIONES datos[], int ce);
void intercambiar(REPARACIONES*, REPARACIONES*);

int main()
{
   REPARACIONES datos[TAM];
   for (int i = 0; i < TAM; i++)
   {
   printf("ingrese codigo:");
   leeryvalidarint(&datos[i].cod);
   printf("ingrese descripcion:");
   leeryvalidartexto(datos[i].desc, 51);
   printf("ingrese costo:");
   leeryvalidarfloat(&datos[i].costo, 0);
   }
   burbujeo(datos, TAM);
   mostrarreparaciones(datos, TAM); 
 return 0;
}

void mostrarreparaciones(REPARACIONES datos[], int ce)
{
   printf("---3 REPARACIONES DEL DIA---\n\n");
   for(int i=0;i<ce;i++)
   {
      printf("REPARACION %d\n", i+1);
      printf("CODIGO = %d | DESCRIPCION = %s | COSTO = %.2f \n", datos[i].cod, datos[i].desc, datos[i].costo);
   }
   
}



void burbujeo(REPARACIONES datos[], int ce)
{
    int j;
    int cota = ce - 1;
    int desordenado = 1;
    while(desordenado)
    {
        desordenado = 0;
        for(j = 0; j < cota; j++) 
        {
            if(datos[j].costo > datos[j+1].costo)
            {
                intercambiar(&datos[j], &datos[j+1]);
                desordenado = j;
            }
        }
        cota = desordenado;
    }
}

void intercambiar(REPARACIONES*a, REPARACIONES*b)
{
   REPARACIONES aux;
   aux = *a;
   *a = *b;
   *b = aux;
}



void leertexto(char texto[], int largo)
{
   int i=0;
   fflush(stdin);
   fgets(texto, largo, stdin);
   while(texto[i] != '\0')
   {
      if(texto[i] == '\n')
      {
         texto[i] = '\0';
      }
      i++;
   } 
}

void leeryvalidartexto(char texto[],int largo)
{
   leertexto(texto,largo);
   while(strlen(texto)==0)
   {
      printf("Error, Reingrese:");
      leertexto(texto,largo);
   }
}

void leeryvalidarint(int*dato)
{
   scanf("%d", dato);
   while(*dato == 0)
   {
      printf("Error. Reingrese:");
       scanf("%d", dato);
   }
}

void leeryvalidarfloat(float*dato, int lim)
{
   scanf("%f", dato);
   while(*dato < lim)
   {
      printf("Error. Reingrese:");
      scanf("%f", dato);
   }
}