/*2) Un palíndromo es una palabra o frase cuyas letras se leen de la misma manera de izquierda a derecha que de derecha a izquierda (por ejemplo: ANA, NEUQUEN, RECONOCER, OSO

Se solicita realizar un programa en C que permita el ingreso continuo de palabras por teclado. El ingreso finaliza cuando el usuario escribe la palabra "FIN" (en mayúsculas).

Desarrollar una función esPalindromo que retorne 1 si la palabra es palíndromo o 0 si no lo es.
La función debe ser independiente de mayúsculas y minúsculas (tratar 'A' y 'a' como iguales)
Para cada ingreso (excepto "FIN"), mostrar si la palabra es o no un palíndromo*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esPalindromo(char palabra[]);
void leertexto(char texto[], int largo);
void leeryvalidartexto(char texto[], int largo);

int main()
{
    char palabra[50];
    printf("ingrese una palabra:");
    leeryvalidartexto(palabra, 50);
    while(strcmpi(palabra, "FIN")!=0)
    {
        if (esPalindromo(palabra) == 1) {
            printf(" '%s' ES UN PALINDROMO.\n", palabra);
        } 
        else 
        {
            printf(" '%s' NO ES UN PALINDROMO.\n", palabra);
        }
    printf("ingrese una palabra:");
    leeryvalidartexto(palabra, 50);

    }

 return 0;
}

int esPalindromo(char palabra[])
{
    int flag = 1;
    int inicio = 0;
    int fin = strlen(palabra) - 1;
    while(inicio<fin)
    {
        if(toupper(palabra[inicio]) != toupper(palabra[fin]))
        {
            flag = 0;
        }
    inicio++;
    fin--;
    }
 return flag;
}

void leeryvalidartexto(char texto[], int largo)
{
    leertexto(texto,largo);
    while(strlen(texto) == 0)
    {
        printf("El texto no puede ser vacio. Reingrese: ");
        leertexto(texto,largo);
    }

}

void leertexto(char texto[], int largo)
{
    int i = 0;
    fflush(stdin);
    fgets(texto, largo, stdin);
    while (texto[i] != '\0') 
    {
        if (texto[i] == '\n') 
        {
            texto[i] = '\0';
        }
        i++;
    }
}

