/*3. Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La carga
finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor. */

#include <stdio.h>
#include <string.h>
#define TAM 50
#define LAR 50

void leeryValidarTexto(char [], int);
void leerTexto(char [], int);
void CargarAlumnos(char [][LAR], int[], int);
int main()
{
  
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

void CargarAlumno(char nombres[][LAR], int dnis[], int max)
{
   int i=0
   char ingreso [LAR]

   printf("ingrese el nombre del alumno");
   leeryValidarTexto(ingreso, LAR)
   while(strcmpi(ingreso != "FIN" && i < LAR))
   {
    
   }

}
