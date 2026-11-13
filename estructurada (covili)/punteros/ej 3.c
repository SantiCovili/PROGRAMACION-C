/*3. Realizar una función que permita ingresar por teclado un valor  codigo entero, un  precio flotante y un  nombre con caracteres. La función
no debe retornar ningún valor. Las variables se declaran y se muestran en el programa principal. */

#include <stdio.h>
#include <string.h>
#define TAM 31

void ingresardatos(int* codigo, char nombre[], float* precio);
void leertexto(char texto[], int largo);
void leeryvalidartexto(char texto[], int largo);
void leeryvalidarint(int* dato, int min);
void leeryvalidarfloat(float* dato, int min);

int main()
{
    int codigo;
    float precio;
    char nombre[TAM];
    ingresardatos(&codigo, nombre, &precio);
    printf("el codigo del producto es:%d\n", codigo);
    printf("el nombre del producto es:%s\n", nombre);
    printf("el precio del producto es:%.2f\n", precio);

}

void ingresardatos(int* codigo, char nombre[], float* precio)
 {   printf("Ingrese codigo del producto:");
    leeryvalidarint(codigo, 0);
    printf("Ingrese nombre del producto:");
    leeryvalidartexto(nombre, TAM);
    printf("Ingrese precio del producto:");
    leeryvalidarfloat(precio, 0);
 }
void leertexto(char texto[], int largo)
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

void leeryvalidartexto(char texto[], int largo)
{
    leertexto(texto,largo);
    while(strlen(texto) == 0)
    {
        printf("Error. Reingrese:");
        leertexto(texto,largo);
    }
}

void leeryvalidarint(int* dato, int min)
{
    scanf("%d", dato);
    while(*dato < min)
    {
        printf("Error. Reingrese:");
        scanf("%d", dato);
    }
}

void leeryvalidarfloat(float* dato, int min)
{
    scanf("%f", dato);
    while(*dato < min)
    {
        printf("Error. Reingrese:");
        scanf("%f", dato);
    }
}
