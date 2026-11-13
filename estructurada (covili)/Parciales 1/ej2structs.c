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
#define TAM 51
#define TAM2 3
typedef struct 
{
    int dni;
    char nombre[TAM];
    int estado;

}PACIENTE;

 void leerTexto(char texto[], int largo);
 void leeryValidarTexto(char texto[], int largo);
 void leeyvalidarIntE2CF(int *dato, int min, int max, int cf);
 void leeryValidarEstado(int *est);
 void ingresarTurnos(PACIENTE pacientes[], int ce);
 int busqueda(PACIENTE pacientes[], int ce, int dni2);
 void ordenarPorDNI(PACIENTE pacientes[], int ce);



int main()
{
  PACIENTE agenda[TAM2];
    int dniLlegada;
    int pos;
    int pacientesNoRegistrados = 0;

    printf("=CARGA DE AGENDA DEL DIA=\n");
    ingresarTurnos(agenda, TAM2);

    printf("\n=== RECEPCION DE PACIENTES ===\n");
    printf("Ingrese DNI del paciente que llega (0 para finalizar): ");
    scanf("%d", &dniLlegada);

    while (dniLlegada != 0)
    {
        
        pos = busqueda(agenda, TAM2, dniLlegada);

        if (pos != -1) 
        {
            agenda[pos].estado = 2; 
            printf("-> Turno encontrado. Estado actualizado a 'Atendido'.\n");
        } 
        else 
        {
            pacientesNoRegistrados++;
            printf("-> El paciente no tiene turno asignado.\n");
        }

        printf("\nIngrese DNI del paciente que llega (0 para finalizar): ");
        scanf("%d", &dniLlegada);
    }

    printf("\n=== INFORMES FINALES ===\n");
   
    printf(" Pacientes que asistieron sin turno: %d\n", pacientesNoRegistrados);

    ordenarPorDNI(agenda, TAM2);

    printf("\n Listado completo de turnos:\n");
    for (int i = 0; i < TAM2; i++)
    {
        printf("DNI: %d | Estado: %d | Nombre: %s\n", agenda[i].dni, agenda[i].estado, agenda[i].nombre);
    }

    return 0;
}



void ingresarTurnos(PACIENTE pacientes[], int ce)
{
    int i;
    PACIENTE aux;
    
    for(i = 0; i < ce; i++)
    {
        printf("- Turno %d -\n", i + 1);
    
        int dniValido = 0;
        while (dniValido == 0)
        {
            printf("Ingrese DNI del paciente: ");
            leeyvalidarIntE2CF(&aux.dni, 10000000, 99999999, 0);

            if (busqueda(pacientes, i, aux.dni) != -1) 
            {
                printf("Error: El DNI ya tiene un turno asignado. Reingrese.\n");
            } 
            else 
            {
                dniValido = 1;
            }
        }

        printf("Ingrese nombre del paciente: ");
        leeryValidarTexto(aux.nombre, TAM); 
        
        printf("Ingrese estado (1 Pendiente, 2 Atendido, 3 Cancelado): ");
        leeryValidarEstado(&aux.estado);

        pacientes[i] = aux; 
    }
}




int busqueda(PACIENTE pacientes[], int ce, int dni2){
    int pos=-1, i=0;
    while (pos==-1 && i<ce)
    {
        if (pacientes[i].dni == dni2)
        {
            pos=i;
        }
        i++;
    }
    return pos;
}


void ordenarPorDNI(PACIENTE pacientes[], int ce)
{
    int i, j;
    PACIENTE aux;
    
    for (i = 0; i < ce - 1; i++)
    {
        for (j = 0; j < ce - i - 1; j++)
        {
            if (pacientes[j].dni > pacientes[j+1].dni)
            {
                aux = pacientes[j];
                pacientes[j] = pacientes[j+1];
                pacientes[j+1] = aux;
            }
        }
    }
}


void leerTexto(char texto[], int largo)
{
   int i=0;
   fflush(stdin);
   fgets(texto,largo,stdin);
   while(texto[i] != '\0')
   {
    if(texto[i] == '\n')
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
        printf("\n Error. Reingrese:");
        leerTexto(texto, largo);
    }
}

void leeyvalidarIntE2CF(int *dato, int min, int max, int cf)
{
    scanf("%d", dato);
    while ((*dato<min || *dato>max) && *dato!=cf)
    {
        printf("Error. Reingrese: ");
        scanf("%d", dato);
    }
}


void leeryValidarEstado(int *est)
{
    fflush(stdin);
    scanf("%d",est);
    while(*est != 1 && *est != 2 && *est != 3)
    {
        printf("Estado invalido. Reingrese (1/2/3): ");
        scanf(" %d",est);
    }
}