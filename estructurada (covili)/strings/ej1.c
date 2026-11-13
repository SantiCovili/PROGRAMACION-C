/*1. Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio.
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo. */


#include <stdio.h>
#include <string.h>
#define TAM 500


void leeryValidarTexto(char[], int);
void leerTexto(char texto[], int largo);

int main() 
{
 char frase [TAM];
 int CantPalabras = 0;
 int flag = 0;

 printf("Ingrese una frase de hasta 500 caracteres:");
 leerTexto(frase, TAM);
 int i=0;

 while (i<TAM && frase[i]!='\0')
 {
  if (frase[i] != ' ') 
    {
    if (flag == 0)
      {
        CantPalabras++;
        flag = 1;
      }
    }
  else 
    {
    flag = 0;
    }
   i++;
  
 }
 printf("La cantidad de palabras son: %d", CantPalabras);
 return 0;
}

 
   void leerTexto(char texto[], int largo)
{
    int i=0;
    fflush(stdin);
    fgets(texto,largo,stdin);
    while(texto[i] != '\0')
    {
        if(texto[i] == '\n')
        {
            texto[i] = '\0';
        }
        i++;
    }
}

