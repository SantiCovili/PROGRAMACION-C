/*Ejercicio 3. Se dispone del archivo binario ventas.dat, ordenado por sucursal, con los siguientes datos por venta:
Sucursal (entero)
Monto (float)
Número de ticket (entero)

Se solicita:
a) Mediante corte de control por sucursal, informar el promedio de monto por sucursal. 
   El cálculo del promedio debe realizarse en otra función.
b) Informar la sucursal con mayor monto de ventas en total (sumando todos los montos de cada sucursal).*/
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
   int sucursal;
   float monto;
   int ticket;
}VENTAS;

void procesarArchivo();
FILE *AbrirArchivo(char nombre[], char tipo[]);
float promedio(int,float);

int main()
{
   procesarArchivo();
   return 0;
}

void procesarArchivo()
{
   FILE *archVentas;
   VENTAS aux;
   int sucursalAnterior, cantV, PrimeraSucursal=1, SucursalMayorMonto;
   float MayorMonto=0, promedioxSucursal, sumaMonto;

   archVentas = AbrirArchivo("ventas.dat","rb");
   fread(&aux,sizeof(aux),1,archVentas);
   while(!feof(archVentas))
   {
      sucursalAnterior = aux.sucursal;
      sumaMonto=0;
      cantV=0;
      while(!feof(archVentas) && aux.sucursal == sucursalAnterior)
      {
         cantV++;
         sumaMonto+=aux.monto;
         fread(&aux,sizeof(aux),1,archVentas);
      }
      promedioxSucursal = promedio(cantV, sumaMonto);
      printf("Sucursal: %d, promedio de ventas:%f\n",sucursalAnterior, promedioxSucursal);
      if(PrimeraSucursal==1 || MayorMonto<sumaMonto)
      {
         MayorMonto = sumaMonto;
         SucursalMayorMonto = sucursalAnterior;
         PrimeraSucursal = 0;
      }
      
   }
   printf("\nla sucursal con mayor monto de ventas en total es: %d", SucursalMayorMonto);
   fclose(archVentas);
   
}

float promedio(int cantV,float sumaMonto)
{
   float promedioxSucursal;
   promedioxSucursal = sumaMonto/cantV;
   return promedioxSucursal;

}

FILE *AbrirArchivo(char nombre[], char tipo[])
{
   FILE*fp;
   fp=fopen(nombre,tipo);
   if(fp==NULL)
   {
      printf("Error.");
      exit(1);
   }
   return fp;
}