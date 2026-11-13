#include <stdio.h>
void OrdenSeleccion (int v[],int tam) 
{
    int i,pmin,aux;
    for(i=0;i<tam-1;i++)
    {
        pmin = PosMinimo(v,i,tam);
        if(pmin != i)
        {
            aux = v[i];
            v[i] = v[pmin];
            v[pmin] = aux;
        }
    }
}
int PosMinimo (int v[],int ini, int tam)
{
    int i, posMin;
    posMin = ini;
    for (i=ini+1;i<tam;i++)
        if (v[i]<v[posMin])
            posMin = i;
    return posMin;
    
}
int main() {
    // 2. vect de ejemplo desordenado
    int vect[] = {64, 25, 12, 22, 11};
    
    // 3. Calculamos la cantidad de elementos (el tamaño)
    int tam = sizeof(vect) / sizeof(vect[0]);

    // 4. Imprimimos el arreglo original
    printf("vector original: \n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vect[i]);
    }
    printf("\n"); // Salto de línea para que quede prolijo

    // 5. Llamamos a tu función para que haga la magia
    OrdenSeleccion(vect, tam);

    // 6. Imprimimos el arreglo ya ordenado
    printf("vector ordenado: \n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vect[i]);
    }
    printf("\n");

    return 0; // Indica que el programa terminó correctamente
}