/*Una editorial desea gestionar su sistema de stock de libros. Para ello necesita manejar la siguiente información:
Por cada libro:
Código ISBN (entero de 8 dígitos)
Título (50 caracteres máximo)
Autor (40 caracteres máximo)
Cantidad de unidades en stock (entero)
La carga inicial de productos finaliza cuando se ingresa ISBN = 0
Gestión de memoria:
a) Debido a que no se conoce la cantidad total de libros, se debe asignar un arreglo dinámico en memoria.
b) El arreglo debe comenzar con una capacidad inicial de 10 elementos.
c) Cada vez que el arreglo se llene, su capacidad debe aumentarse dinámicamente de 10 en 10.
Al finalizar el mes, se ingresan las ventas con los siguientes datos:
Código ISBN del libro
Cantidad vendida
Se pide hacer un programa que permita ingresar los datos de los libros considerando que se finaliza la carga cuando se ingresa el ISBN 0.
Luego, permitir ingresar las ventas considerando que no se van a ingresar más ventas cuando se ingrese el ISBN 0.
Se debe:
a. Actualizar el stock de cada libro con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado actualizado, informando:
ISBN              TITULO               AUTOR                STOCK ACTUALIZADO

99999999 XXXXXXXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXXXXX        9999*/ 




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 51
#define TAM2 41

typedef struct 
{
    int cod;
    char tit[TAM];
    char aut[TAM2];
    int stock;
} LIBROS;

typedef struct 
{
    int cod;
    int cantV;
} VENTAS;

// Prototipos actualizados para que coincidan exactamente con las funciones
LIBROS ingresarLibros(LIBROS *datos, int *ce);
int busqueda(LIBROS *datos, int cod2, int *ce);
void leerTexto(char texto[], int largo); 
void leeryValidarTexto(char texto[], int largo);
void leeryValidarInt(int *dato, int min); // Cambié "largo" por "min" por legibilidad
void leeryValidarIntE2CF(int *dato, int min, int max, int cf);

// Prototipos de las funciones que faltaban declarar
LIBROS* INGRESO(LIBROS *datos, int *mem, int *cantL);
void ventas(LIBROS *datos, int *ce);
void listado(LIBROS *datos, int *ce);

int main()
{
    LIBROS *datos; // Corregido: era LIBROS, no LIBRO
    int capInicial = 10;
    int cantLibros = 0;
    
    datos = (LIBROS*)malloc(capInicial * sizeof(LIBROS));
    if (datos == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(1);
    }
    
    datos = INGRESO(datos, &capInicial, &cantLibros);
    
    if (cantLibros > 0) 
    {
        ventas(datos, &cantLibros);
        listado(datos, &cantLibros);
    } 
    else 
    {
        printf("\nNo se cargaron libros.\n");
    }

    free(datos);
    return 0;
}

// Función que maneja el bucle de carga y el realloc dinámico
LIBROS* INGRESO(LIBROS *datos, int *mem, int *cantL)
{
    LIBROS aux;
    int seguir = 1;
    
    printf("--- CARGA INICIAL DE LIBROS ---\n");
    while (seguir == 1)
    {
        aux = ingresarLibros(datos, cantL);
        
        if (aux.cod == 0)
        {
            seguir = 0; // Condición de corte en lugar de break
        }
        else
        {
            // Verificamos si hay que redimensionar el vector
            if (*cantL == *mem)
            {
                *mem += 10;
                LIBROS *temp = (LIBROS*)realloc(datos, (*mem) * sizeof(LIBROS));
                if (temp != NULL)
                {
                    datos = temp;
                }
                else
                {
                    printf("Error al reasignar memoria.\n");
                    seguir = 0; // Forzamos salida por falta de memoria
                }
            }
            
            // Si la memoria está ok, guardamos el libro
            if (seguir == 1) 
            {
                *(datos + *cantL) = aux;
                (*cantL)++;
                printf("Libro cargado exitosamente.\n\n");
            }
        }
    }
    return datos;
}

// Carga de un solo libro con sus validaciones
LIBROS ingresarLibros(LIBROS *datos, int *ce) // Corregido: LIBROS *datos
{
    LIBROS aux;
    printf("Ingrese codigo ISBN (0 para finalizar): ");
    leeryValidarIntE2CF(&aux.cod, 10000000, 99999999, 0);
    
    if (aux.cod != 0)
    {
        while (busqueda(datos, aux.cod, ce) != -1)
        {
            printf("Codigo ya ingresado. Reingrese (0 para finalizar): ");
            leeryValidarIntE2CF(&aux.cod, 10000000, 99999999, 0);
        }
        
        // Verificamos de nuevo por si el usuario ingresó 0 al reingresar
        if (aux.cod != 0) 
        {
            printf("Ingrese titulo del libro: ");
            leeryValidarTexto(aux.tit, TAM);
            printf("Ingrese autor del libro: ");
            leeryValidarTexto(aux.aut, TAM2);
            printf("Ingrese cantidad de stock: ");
            leeryValidarInt(&aux.stock, 0);
        }
    }
    return aux;
}

// Función que gestiona las ventas sin break
void ventas(LIBROS *datos, int *ce)
{
    int codVenta = -1;
    int cantVenta;
    int pos;

    printf("\n--- REGISTRO DE VENTAS ---\n");
    while (codVenta != 0)
    {
        printf("Ingrese ISBN del libro a vender (0 para finalizar): ");
        leeryValidarIntE2CF(&codVenta, 10000000, 99999999, 0);

        if (codVenta != 0)
        {
            pos = busqueda(datos, codVenta, ce);
            
            if (pos != -1)
            {
                cantVenta = 0;
                while (cantVenta <= 0 || cantVenta > (datos + pos)->stock)
                {
                    printf("Ingrese cantidad a vender (Stock actual: %d): ", (datos + pos)->stock);
                    leeryValidarInt(&cantVenta, 1);
                    
                    if (cantVenta > (datos + pos)->stock)
                    {
                        printf("Error: No hay suficiente stock.\n");
                    }
                }
                
                // Actualizamos el stock
                (datos + pos)->stock -= cantVenta;
                printf("Venta registrada. Nuevo stock: %d\n\n", (datos + pos)->stock);
            }
            else
            {
                printf("Error: Libro no encontrado.\n\n");
            }
        }
    }
}

// Listado final adaptado a tu struct
void listado(LIBROS *datos, int *ce)
{
    printf("\n--- LISTADO ACTUALIZADO ---\n");
    printf("%-8s %-30s %-30s %s\n", "ISBN", "TITULO", "AUTOR", "STOCK ACTUALIZADO");
    
    int i = 0;
    while (i < *ce)
    {
        // Se llaman a los campos reales del struct (cod, tit, aut, stock)
        printf("%08d %-30s %-30s %10d\n", 
               (datos + i)->cod, 
               (datos + i)->tit, 
               (datos + i)->aut, 
               (datos + i)->stock);
        i++;
    }
}

// Búsqueda secuencial
int busqueda(LIBROS *datos, int cod2, int *ce)
{
    int pos = -1, i = 0;
    while (pos == -1 && i < *ce)
    {
        if ((datos + i)->cod == cod2)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

// Validaciones y lectura de texto tal como las armaste
void leerTexto(char texto[], int largo) 
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

void leeryValidarTexto(char texto[], int largo)
{
    leerTexto(texto, largo);
    while(strlen(texto) == 0)
    {
        printf("Error. Reingrese: ");
        leerTexto(texto, largo);
    }
}

void leeryValidarIntE2CF(int *dato, int min, int max, int cf)
{
    scanf("%d", dato);
    while ((*dato < min || *dato > max) && *dato != cf)
    {
        printf("Error. Reingrese (entre %d y %d, o %d para salir): ", min, max, cf);
        scanf("%d", dato);
    }
}

void leeryValidarInt(int *dato, int min)
{
    scanf("%d", dato);
    while(*dato < min)
    {
        printf("Error. Reingrese un valor mayor o igual a %d: ", min);
        scanf("%d", dato);
    }
}