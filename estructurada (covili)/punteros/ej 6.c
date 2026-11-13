//#Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
//Realizar una función que retorne un puntero al mayor valor del vector.
//Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra. en c 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10 // Tamaño del vector

// Prototipo de la función
int* buscarMayor(int *vector, int tam);

int main() {
    int numeros[TAM];
    int *pMayor = NULL;

    // Inicializar la semilla para los números aleatorios
    srand(time(NULL));

    printf("Vector generado:\n");
    for (int i = 0; i < TAM; i++) {
        // Generar números aleatorios de hasta 3 cifras (0 a 999)
        numeros[i] = rand() % 1000; 
        printf("[%d]: %d\n", i, numeros[i]);
    }

    // Obtener el puntero al mayor elemento
    pMayor = buscarMayor(numeros, TAM);

    // Calcular la posición restando las direcciones de memoria (aritmética de punteros)
    int posicion = pMayor - numeros;

    printf("\n--- Resultados ---\n");
    // Mostramos el valor desreferenciando el puntero con *
    printf("El mayor valor es: %d\n", *pMayor); 
    printf("Se encuentra en la posicion: %d\n", posicion);

    return 0;
}

// Función que retorna un puntero al mayor valor
int* buscarMayor(int *vector, int tam) {
    // Asumimos que el primer elemento es el mayor inicialmente
    int *max = vector; 

    for (int i = 1; i < tam; i++) {
        // Comparamos el valor actual con el valor apuntado por max
        if (vector[i] > *max) {
            max = &vector[i]; // Guardamos la dirección de memoria del nuevo mayor
        }
    }

    return max; // Retornamos el puntero
}