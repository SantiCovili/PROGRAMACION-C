/*7. Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
 La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad faltante
Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
cantidad. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 51

typedef struct ej7
{
    int cod;
    char desc[TAM];
    int stock;
} PRODUCTOS;

typedef struct 
{
    int codigo;
    int faltante;
} FALTANTES;

FILE *archivo(char[], char[]);
void cargarVentas();
void registrarFaltantes(int, int);
void leeryvalidarint(int*, int);
void mostrarFaltantes();
void mostrarStock();

int main()
{
    FILE *fp;
    fp = archivo("Stock.dat","ab");
    fclose(fp); // MUY IMPORTANTE: cerrar el archivo antes de que otras funciones lo abran

    printf("Stock inicial:\n");
    mostrarStock();
    
    cargarVentas();
    
    printf("\nStock final:\n");
    mostrarStock();
    
    printf("\nFaltantes:\n");
    mostrarFaltantes();

    return 0;
}

void cargarVentas()
{
    int codigo;
    int cantidad;
    int faltante;
    int encontrado;

    FILE *fp;
    PRODUCTOS aux;
    
    fp = archivo("Stock.dat", "r+b");
    
    printf("\nIngrese codigo de articulo (0 para finalizar): ");
    leeryvalidarint(&codigo, 0);
    
    while (codigo != 0) 
    {
        printf("Ingrese la cantidad vendida: ");
        leeryvalidarint(&cantidad, 1);
        
        encontrado = 0;
        rewind(fp);
        fread(&aux, sizeof(aux), 1, fp);
        
        while(!feof(fp) && !encontrado)
        {
            if(aux.cod == codigo)
            {
                encontrado = 1; // Faltaba el punto y coma
            }
            else
            {
                fread(&aux, sizeof(aux), 1, fp);
            }
        }
        
        if(!encontrado)
        {
            printf("Articulo no encontrado.\n");
        }
        else
        {
            if(cantidad <= aux.stock)
            {
                aux.stock -= cantidad;
                printf("Venta realizada.\n");
            }
            else
            {
                faltante = cantidad - aux.stock; // Sintaxis corregida
                aux.stock = 0;
                printf("Stock insuficiente. Faltan %d unidades.\n", faltante);
                registrarFaltantes(codigo, faltante);
            }
            // Mover el puntero hacia atrás para sobreescribir el registro actualizado
            fseek(fp, -(long)sizeof(aux), SEEK_CUR);
            fwrite(&aux, sizeof(aux), 1, fp);
            fflush(fp);
        }
        printf("\nIngrese codigo de articulo (0 para finalizar): ");
        leeryvalidarint(&codigo, 0);
    }
    fclose(fp);
}

void registrarFaltantes(int codigo, int faltante) // Agregado el void
{
    FALTANTES aux;
    FILE *fp;
    int encontrado = 0;
    
    // Abrimos con fopen directo para manejar el caso donde el archivo aun no existe
    fp = fopen("faltantes.dat", "r+b");
    if(fp == NULL) {
        fp = fopen("faltantes.dat", "w+b"); // Si no existe, lo creamos
    }
    if(fp == NULL) {
        printf("Error fatal al crear faltantes.dat\n");
        return;
    }

    fread(&aux, sizeof(aux), 1, fp);
    while(!feof(fp) && !encontrado)
    {
        if(aux.codigo == codigo)
        {
            encontrado = 1;
        }
        else
        {
            fread(&aux, sizeof(aux), 1, fp);
        }
    }
    
    if(!encontrado)
    {
        // No estaba en el archivo, lo agregamos al final
        aux.codigo = codigo;
        aux.faltante = faltante;
        fseek(fp, 0, SEEK_END);
        fwrite(&aux, sizeof(aux), 1, fp);
    }
    else
    {
        // Ya existía, sumamos la cantidad y sobreescribimos
        aux.faltante += faltante;
        fseek(fp, -(long)sizeof(aux), SEEK_CUR);
        fwrite(&aux, sizeof(aux), 1, fp);
    }
    fclose(fp);
}

void leeryvalidarint(int *dato, int lim)
{
    scanf("%d", dato);
    while(*dato < lim)
    {
        printf("Error. Reingrese: ");
        scanf("%d", dato);
    }
}

// Agregado el nombre de los parametros y corregida la declaración del FILE
FILE *archivo(char nombre[], char tipo[])
{
    FILE *fp; 
    fp = fopen(nombre, tipo);
    if(fp == NULL)
    {
        printf("Error. No se pudo abrir el archivo %s.\n", nombre);
        getchar();
        exit(1);
    }
    return fp;
}

void mostrarStock()
{
    PRODUCTOS aux;
    FILE *fp;
    
    fp = fopen("Stock.dat", "rb");
    if(fp == NULL) return; // Validación por si está vacío
    
    fread(&aux, sizeof(aux), 1, fp);
    while(!feof(fp))
    {
        printf("Codigo: %d - %s - Stock: %d\n", aux.cod, aux.desc, aux.stock);
        fread(&aux, sizeof(aux), 1, fp);
    }
    fclose(fp);
}

void mostrarFaltantes()
{
    FALTANTES aux;
    FILE *fp;
    
    fp = fopen("faltantes.dat", "rb");
    if(fp == NULL) return; // Validación por si aún no hay faltantes
    
    fread(&aux, sizeof(aux), 1, fp);
    while(!feof(fp))
    {
        printf("Codigo: %d - Faltantes: %d\n", aux.codigo, aux.faltante);
        fread(&aux, sizeof(aux), 1, fp);
    }
    fclose(fp);
}