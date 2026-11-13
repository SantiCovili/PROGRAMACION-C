/*1) Se solicita realizar un programa en C para validar el formato de las patentes registradas en un sistema de tránsito. 
El programa debe permitir el ingreso continuo de patentes por teclado hasta que se ingrese la palabra "FIN" (en mayúsculas) como condición de fin.

Una patente se considera válida si responde estrictamente a uno de los dos formatos vigentes:
Formato Tradicional: 3 letras seguidas de 3 números (Ejemplo: AAA999).
Formato Mercosur: 2 letras, 3 números y 2 letras   (Ejemplo: AA999AA)*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void leertexto(char texto[], int largo);
void leeryvalidartexto(char texto[],int largo);
int validarpatentes(char patente[]);
void listadopatentes(char patente[][31], int ce);

int main()
{
    int ce=0;
    int i;
    char patente[31];
    char lista_patentes[100][31];
    printf("ingresar patente:");
    leeryvalidartexto(patente, 31);
    while(strcmpi(patente, "FIN")!=0)
       {
            if(validarpatentes(patente)== 1)
            {
                printf("PATENTE VALIDA\n");
                strcpy(lista_patentes[ce], patente);
                ce++;
            }
                else
            {
                printf("PATENTE NO VALIDA\n");
            }
               
                
                printf("ingresar patente:");
                leeryvalidartexto(patente, 31);
        }
    listadopatentes(lista_patentes, ce);
    return 0;
}


void leertexto(char texto[], int largo)
{
    int i=0;
    fflush(stdin);
    fgets(texto,largo,stdin);
    while(texto[i]!='\0')
    {
        if(texto[i]=='\n')
        {
            texto[i]='\0';
        }
        i++;
    }
}

void leeryvalidartexto(char texto[],int largo)
{
    leertexto(texto,largo);
    while(strlen(texto)!=7 && strlen(texto)!=6 && strlen(texto)!=3)
    {
        printf("Error. Reingrese:");
        leertexto(texto,largo);
    }
}

int validarpatentes(char patente[])
{
    int flag = 0;
    if (strlen(patente)==6)
    {
        if(isalpha(patente[0]) && isalpha(patente[1])&& isalpha(patente[2])&& isdigit(patente[3])&& isdigit(patente[4])&& isdigit(patente[5]))
        {
            flag = 1;
        }
    }  
    else if(strlen(patente)==7)
    {
        if(isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6]))
        {
            flag = 1;
        }

    }
    return flag;
}   

void listadopatentes(char lista[][31], int ce)
{
    printf("----LISTADO DE PATENTES---\n\n");
    for(int i=0; i<ce; i++)
    {
        printf("la patente %d ingresada es: %s", i+1, lista[i]);
    }
}