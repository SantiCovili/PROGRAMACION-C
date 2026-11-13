#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void cargaaleatoria(int[],int);
void Mostrar(int[],int);
int Maximo(int[],int);
int Minimo(int[],int);
void mostrarMaximo(int[],int,int);
void mostrarMinimo(int[],int,int);

int main()
{
    int vec[TAM];
    int min,max;
    srand(time(NULL));
    cargaaleatoria(vec,TAM);
    min = Minimo(vec,TAM);
    max = Maximo(vec,TAM);
    mostrarMinimo(vec,TAM,min);
    mostrarMaximo(vec,TAM,max);

    return 0;
}

int Minimo(int v[],int cant)
{
    int i, min=v[0];
    for(i=1;i<cant;i++)
    {
        if(v[i]<min)
            min = v[i];
    }
    return min;


}

int Maximo(int v[],int cant)
{
    int i, max = v[0];
    for(i=0;i<cant;i++)
    {
        if(v[i]>max)
            max = v[i];
    }
    return max;
}

void mostrarMinimo(int v[],int cant,int min)
{
    int i, cont = 0;
    for(i=0;i<cant;i++)
    {
        if(v[i] == min)
            cont ++;
    }
    printf("El menor valor es:%d\n",min);
    printf("Se repite: %d vez/veces\n\n",cont);


}

void mostrarMaximo(int v[],int cant,int max)
{
    int i;
    printf("El mayor valor es:%d\n",max);
    printf("Se encuentra en las posiciones: ");
    for(i=0;i<cant;i++)
    {
        if(v[i] == max)
        {
            printf("%d",i + 1);
        }
    }
    printf("\n");
}


void cargaaleatoria(int v[], int ce)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=100 + rand() % 900;
}
