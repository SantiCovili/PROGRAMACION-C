#include <stdio.h>
void Ordenar (int vo[],int vi[], int ce)
{
    int i,j,aux;
    for(i=0;i<ce-1;i++)
        for(j=0;j<ce-1-i;j++)
            if(vo[j] < vo[j+1])
            {
                aux = vo[j];
                vo[j] = vo[j+1];
                vo[j+1] = aux;

                aux = vi[j];
                vi[j] = vi[j+1];
                vi[j+1] = aux;
            }
}