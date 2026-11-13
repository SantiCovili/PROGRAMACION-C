/*Ej 2:  Un centro odontológico administra una agenda de 40 turnos para un día determinado. Cada turno se representa mediante una estructura con los siguientes datos:
 DNI del Paciente (entero).
Nombre del Paciente (cadena de hasta 50 caracteres).
Estado del Turno (entero: 1 “Pendiente", 2  "Atendido", 3  "Cancelado").
Se deben ingresar los datos de los 40 turnos , Al ingresar el DNI, se debe validar que el paciente no tenga ya un turno asignado en el vector.
Finalizada la carga, se ingresará una secuencia de DNI de pacientes que van llegando a la recepción, terminando con DNI = 0.
Si el DNI existe, se debe cambiar el estado del turno a 2: "Atendido”.
Si el DNI no existe, se lo contabilizara como “Paciente No Registrados".
Informar
a) La cantidad total de pacientes que asistieron, pero no tenían turno.
b) El listado completo de la agenda ordenado de forma ascendente por DNI, mostrando DNI, Nombre y el estado.
Implementar al menos tres funciones: Una para la carga, otra para el ordenamiento y otra para la  búsqueda del código en el vector de estructuras,*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 51
#define TAM2 40

typedef struct 
{
    int dni;
    char nombre[TAM];
    int estado;

}PACIENTE;

void leerTexto(char[],int);
void leeryValidarTexto(char[], int);
void leeryValidarInt(int*);
void leeryValidarInt2(int*, int, int, int);
PACIENTE cargarIngreso(PACIENTE *datos, int *ce);
PACIENTE* INGRESAR(PACIENTE*,int*, int*);
int busqueda(PACIENTE* datos, int cod, int*ce );
void recepcion(PACIENTE*datos, int*ce);
void listado(PACIENTE *datos, int *ce);


int main()
{
    PACIENTE *datos;
    int CapIni=10;
    int cantVec=0;
    datos=(PACIENTE*)malloc(CapIni*sizeof(PACIENTE));
    if(datos==NULL)
    {
        printf("Error.");
        exit (1);
    }
    datos=INGRESAR(datos, &CapIni, &cantVec);
    recepcion(datos, &cantVec);
    listado(datos, &cantVec);

    free(datos);
    return 0;
}


PACIENTE cargarIngreso(PACIENTE* datos, int* ce)
{
    PACIENTE aux;
    printf("ingresar DNI del paciente");
    leeryValidarInt2(&aux.dni, 10000000, 99999999, 0);
    if(aux.dni != 0)
    {
        while(busqueda(datos, aux.dni,ce ) !=-1)
        {
            printf("El DNI ya fue ingresado");
            leeryValidarInt2(&aux.dni, 10000000, 99999999,0);
        }
        if(aux.dni != 0)
        {
                 printf("ingrese nombre del paciente:");
                 leeryValidarTexto(aux.nombre, TAM);
                 printf("ingrese estado (1 pendiente/2 atendido/3 cancelado):");
                 leeryValidarInt(&aux.estado);

        }
    }
    return aux;
}

PACIENTE* INGRESAR(PACIENTE*datos, int *mem, int *ce)
{
    PACIENTE aux;
    int i=0;
    aux = cargarIngreso(datos, ce);
    while(aux.dni != 0)
    {
        if(i==*mem)
        {
            *mem+=10;
            datos=(PACIENTE*)realloc(datos,*mem*sizeof(PACIENTE));
            if (datos==NULL)
            {
                printf("Error.");
                exit(1);
            }

        }
        *(datos + i) = aux;
        i++;
        aux=cargarIngreso(datos,ce);

    }
    *ce=i;
    return datos;
}



void leerTexto(char texto[],int largo)
{
   int i=0; 
   fflush(stdin);
   fgets(texto, largo, stdin);

   while(texto[i]!='\0')
   {
    if(texto[i] =='\n')
    {
        texto[i] = '\0';
    }
    i++;
   }
}

void leeryValidarTexto(char texto[], int largo)
{
    leerTexto(texto, largo);
    while(strlen(texto)==0)
    {
        printf("Error. Reingrese:");
        leerTexto(texto, largo);
    }
}

void leeryValidarInt(int* dato)
{
    fflush(stdin);
    scanf("%d", dato);
    while(*dato != 1 && *dato != 2 && *dato != 3)
    {
        printf("Error, Reingrese:");
        scanf("%d", dato);
    }
}

void leeryValidarInt2(int *dato, int min, int max, int cf)
{
    scanf("%d", dato);
    while ((*dato<min || *dato>max) && *dato!=cf)
    {
        printf("Error. Reingrese: ");
        scanf("%d", dato);
    }
}

int busqueda(PACIENTE* datos, int cod, int*ce)
{
    int pos=-1;
    int i=0;
    while(pos==-1 && i<*ce)
    {
        if((datos+i)->dni==cod)
        {
            pos = 1;
        }
        i++;
    }
    return pos;
}

void recepcion(PACIENTE*datos, int*ce)
 {
    PACIENTE recepcion;
    int pos;
    int noRegistrados=0;
    printf("ingresar DNI del paciente");
    leeryValidarInt2(&recepcion.dni, 10000000, 99999999, 0);
    while(recepcion.dni != 0)
    {
        pos=busqueda(datos, recepcion.dni,ce);
        if(pos!=-1)
        {
            datos[pos]->estado=2;
        }
        else
        {
            noRegistrados++;
        }
        printf("Ingrese DNI del paciente: ");
        leeryValidarInt2(&recepcion.dni, 10000000, 99999999, 0);
    }
    printf("La cantidad de pacientes que asistieron pero no tenian turno son %d", noRegistrados);

 }

 void burbujeo(PACIENTE *datos, int *ce){
    PACIENTE aux;
    int j, cota= *ce-1;
    int desordenado=1;
    while (desordenado)
    {
        desordenado=0;
        for (j=0; j<cota; j++)
        {
            if ((datos+j)->dni > (datos+j+1)->dni)
            {
                aux=*(datos+j);
                *(datos+j)=*(datos+j+1);
                *(datos+j+1)=aux;
                desordenado=j;
            }
        }
        cota=desordenado;
    }
}

void listado(PACIENTE *datos, int *ce)
{
    burbujeo(datos, ce);
    printf("-LISTADO DE TURNOS-\n");
    printf("%8s %-30s %-6s\n", "DNI", "NOMBRE", "ESTADO");
    for (int i = 0; i < *ce; i++)
    {
        printf("%8d %-30s %-6d\n", (datos+i)->dni, (datos+i)->nombre, (datos+i)->estado);
    }
    
}
