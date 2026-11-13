/* 2. Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las funciones de
la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio y
apellido) y mostrarlo */

#include <stdio.h>
#include <string.h>
#define TAM 50

void leerTexto(char [], int);
void leeryValidarTexto(char [], int);

int main()
{
  char nombre[TAM];
  char apellido[TAM];
  char Completo[TAM];

  printf("ingrese el nombre:");
  leeryValidarTexto(nombre, TAM);
  printf("ingrese el apellido:");
  leeryValidarTexto(apellido, TAM);
  strcpy(Completo, nombre);
  strcat(Completo, ", ");
  strcat(Completo, apellido);
  printf("El nombre completo es: %s", Completo);
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


void leeryValidarTexto(char texto[], int largo)
{
    leerTexto(texto,largo);
    while(strlen(texto) == 0)
    {
        printf("El texto no puede ser vacio. Reingrese: ");
        leerTexto(texto,largo);
    }

}