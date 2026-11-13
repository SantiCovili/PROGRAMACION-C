/* Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta de
productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de los
datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada venta
se ingresa el código de producto y cantidad de unidades vendidas terminando con una cantidad igual a 0. Se
solicita:
a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto. */

#include <stdio.h>
#include <string.h>
#define MAX 51
#define TEXTO 4
int IngresarProductos(char[][TEXTO], float[], int);
void leeryValidarCodigo(char[], int);
void leerCodigo(char[], int);

int main()
{
    return 0;
}

int IngresarProducto(char[][TEXTO], float[], int){


}



void leeryValidarCodigo(char codigo[], int largo)
{
    leerCodigo(codigo,largo);
    while(strlen(codigo) != 3)
    {
        printf("El texto no puede ser vacio. Reingrese: ");
        leerTexto(codigo,largo);
    }

}

void leerCodigo(char codigo[], int largo)
{
    int i=0;
    fflush(stdin);
    fgets(codigo,largo,stdin);
    while(codigo[i] != '\0')
    {
        if(codigo[i] == '\n')
        {
            codigo[i] = '\0';
        }
        i++;
    }
}