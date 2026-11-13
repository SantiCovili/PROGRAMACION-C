/*2. Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

  int num1;
  int num2;
  int result;
  int *p1=&num1;
  int *p2=&num2;

  printf("ingrese un numero entero:");
  scanf("%d", &num1);
  printf("ingrese un numero entero:");
  scanf("%d", &num2);

 result = *p1 + *p2  ;
 printf("la suma de %d y %d es %d ",*p1,*p2, result);
 
 return 0;

}