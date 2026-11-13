/*El ministerio de transporte requiere un programa que permita validar si una patente es válida. 
Realizar un programa en C que permita verificar si la patente es válida o no hasta que se ingrese la patente "FIN". 
Formatos posibles: AAA999 ó AA999AA*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void leerTexto(char[], int);
void leeryValidarTexto(char[],int);
int validarPatente(char patente[]);

int main()
{
    char patente[20];
    printf("ingrese la patente:");
    leeryValidarTexto(patente, 20);
    while(strcmp(patente, "FIN")!=0)
    {
        if(validarPatente(patente)==1)
        {
            printf("LA PATENTE %s ES VALIDA\n", patente);
        }
        else
        {
            printf("LA PATENTE %s NO ES VALIDA\n", patente);
        }
        printf("ingrese la patente:");
        leeryValidarTexto(patente, 20);
    }
    
    return 0;
}


int validarPatente(char patente[])
{
    int flag = 0;
    int larg = strlen(patente);
    if(larg == 6)
    {
      if(isalpha(patente[0]) && isalpha(patente[1]) && isalpha(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) 
      && isdigit(patente[5]))
      {
        flag = 1;
      }
      
    }
    else if(larg == 7) 
    {
        if (isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6])) 
        {
            flag = 1;
        }

    }

    

    return flag; 

}

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

void leeryValidarTexto(char texto[],int largo)
{
    leerTexto(texto, largo);
    while(strlen(texto)!=7 && strlen(texto)!=6 && strlen(texto)!=3)
    {
        printf("\n Error. Reingrese:");
        leerTexto(texto, largo);
    }
}
