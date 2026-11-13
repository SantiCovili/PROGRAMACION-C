#include <stdio.h>
void OrdenBurbujeOptimizado( int v[],int tam)
{
    int i,desordenado,aux,limite=tam-1;
    do
    {
        desordenado = 0;
        for(i=0; i<limite;i++)
        {
            if(v[i]>v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                desordenado = i;
            }
        }
        limite = desordenado;
    } while(desordenado);
} //se usa do whule para recorrer el vector ya que si no ser realizaron cambios
// quiere decir que ya estba ordenado y no se hace falta volver a recorrerlo

//para los siguiente ciclos el limite sera la posicion del ultimo intercambio
// ya que si al recorrer una vez no se hacen cambios luego de dicha posicion
// es porque el resto del vector ya esta ordenado