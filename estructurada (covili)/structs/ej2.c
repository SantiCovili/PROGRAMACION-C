/*2. Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes de
sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES IMPORTE TOTAL
            VENDIDAS          VENDIDO
XXXXXXX XXXX $XXXXX,XX */

#include <stdio.h>
#include <string.h>
#define TAM 50
typedef struct
{
   char codigo[6];
   float precio;
   char descripcion[31];
   int CUV;
   float ITV;
}PRODUCTOS;



void leerTexto(char[], int);
void leeryValidarTexto(char[], int);
PRODUCTOS ingresarProductos(PRODUCTOS[], int);
int cargarProductos(PRODUCTOS[], int);
int busqueda(PRODUCTOS[], char[], int);


int main()
{
 PRODUCTOS producto [TAM]
 int cantProductos = ingresoProductos(productos, TAM);
}

PRODUCTOS ingresarProductos(PRODUCTOS productos[], int i)
{
    PRODUCTOS prod;
    printf("ingrese la descripcion del producto:");
    leeryValidarTexto(prod.descripcion, 31);
    if(strcmpi(prod.descripcion, "FIN")!=0)
    {
        printf("ingrese codigo de producto:");
        leeryValidarTexto(prod.codigo, 6);
        while(busqueda(productos[],i,prod.codigo)!=-1)
        {
            printf("El codigo ya fue ingresado. Reingrese: ");
            leeryValidarTexto(prod.codigo, 6);
        }
        prod.precio = leeryValidaFloat("ingrese el precio:");

        prod.CUV = leeryValidarInt("ingrese cantidad de unidades vendidas el mes anterior:");

        prod.ITV = leeryValidaFloat("ingrese ingreso total de ventas del mes anterior");
    }
    return prod
}

int cargarProductos(PRODUCTOS productos[], int cp)
{
    int i = 0;
    PRODUCTOS prod;
    prod = ingresarProductos(productos, i);
    while(strcmpi(prod.descripcion != "FIN") && i < ce )
    {
        productos[i] = prod;
        i++;
        prod = ingresarProductos(productos, i);
    }
    
    return i;

}



leeryValidarInt(char* mensaje)
{
    float valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    while (valor <= 0) {
        printf("Error. Valor fuera de rango. Reingrese: ");
        scanf("%d", &valor);
    }
    return valor;
}

leeryValidaFloat(char* mensaje)
{
    float valor;
    printf("%s", mensaje);
    scanf("%f", &valor);
    while (valor <= 0) {
        printf("Error. Valor fuera de rango. Reingrese: ");
        scanf("%f", &valor);
    }
    return valor;
}


void leerTexto(char texto[], int largo)
{
    int = 0
    fflush(stdin);
    fgets(texto,largo,stdin);
    while(texto[i] != '\0')
    {
        if(texto[i]=='\n')
        {
          texto[i]='\0';  
        }
        i++
    }
}

void leeryValidarTexto(char texto[], int largo)
{
    leerTexto(texto, largo);
    while(strlen(texto)==0)
    {
        printf("El texto no puede ser vacio. Reingrese:");
        leerTexto(texto, largo);
    }


}

 int busqueda(PRODUCTOS productos[], char buscado[], int cp)
 {
     int p = -1, i = 0;
     while (i < cp && p == -1)
     {
         if (strcmp(productos[i].codigo, buscado) == 0)
         {
             indice = i;
        }
         i++;
     }
     return p
}