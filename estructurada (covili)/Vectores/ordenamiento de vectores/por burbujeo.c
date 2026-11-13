#include <stdio.h>
void OrdenBurujeo (int v[],int tam)
{
    int i,j,aux;
    for (i=0; i<tam-1;i++)
    {
        for(j=0;j<tam-1-i;j++)
            if(v[j]>=v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
    }
}