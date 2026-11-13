/*1. De una persona se conoce los siguientes datos:
• Número de Legajo (int, entre 1 y 10.000)
• Apellido (string, 15 caracteres)
• Nombre (string, 15 caracteres)
• Altura (float, mayor de 0)
• Sexo (char, F o M)
• Día de Nacimiento (int, entre 1 y 31
• Mes de Nacimiento (int, ente 1 y 12)
• Año de Nacimiento (int, ente 1950 y 2019)

Se solicita realizar los siguientes procesos:
a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
anteriormente y llamarla PERSONA.
b. Mostrar los datos de la Estructura de Datos del punto a.
c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura
de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
utilizarla en una nueva Estructurad de Datos llamada PERSONA2.
d. Mostrar los datos de la Estructura de Datos del punto c.
e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos
al programa principal (main).
f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
ser hasta 36 materias) y llamarla PERSONA3.
g. Crear una FUNCION que realice el punto f.
h. Mostrar los datos de la Lista creada en el punto f.
i. Crear una FUNCION que realice el punto h.*/

#include <stdio.h>
#include <string.h>
#define TAM 16
#define TAM2 37

typedef struct 
{
  int numLegajo;
  char apellido[TAM];
  char nombre[TAM];
  float altura;
  char sexo;
  int dia;
  int mes;
  int anio;
}PERSONA;

typedef struct
{
    char nombre[TAM];
    char apellido[TAM];
}nombreCompleto;

typedef struct
{
    int dia;
    int mes;
    int anio;
}FECHA;

typedef struct 
{
    int numLegajo;
    nombreCompleto NomyApe;
    float altura;
    char sexo;
    FECHA fechaNacimiento;

}PERSONA2;

typedef struct 
{
    int numLegajo;
    nombreCompleto NomyApe;
    float altura;
    char sexo;
    FECHA fechaNacimiento;
    int cantMaterias;
    int materiasAprob[TAM2];

}PERSONA3;





void leerTexto(char texto[], int largo);
void leeryValidarTexto(char texto[], int largo);
int leerEnteroRango(int min, int max, const char* mensaje);
float leerFloatPositivo(const char* mensaje);
char leerSexo(const char* mensaje);
PERSONA cargarPersona1();
PERSONA2 cargarPersona2();
PERSONA3 cargarPersona3 ();


int main()
{
    PERSONA p1;
    p1 = cargarPersona1();
    printf("datos de la persona 1:\n");
    printf("legajo:%d  nombre:%s  apellido:%s  altura:%f  sexo:%c  dia:%d  mes:%d  anio:%d", p1.numLegajo, p1.nombre, p1.apellido, p1.altura, p1.sexo, p1.dia, p1.mes, p1.anio);
    PERSONA2 p2;
    p2 = cargarPersona2();
    printf("datos de la persona 2:\n");
    printf("legajo:%d  nombre completo:%s %s  altura:%.2f  sexo:%c Fecha de nacimiento: %d %d %d", p2.numLegajo, p2.NomyApe.nombre, p2.NomyApe.apellido, p2.altura, p2.sexo, p2.fechaNacimiento.dia, p2.fechaNacimiento.mes, p2.fechaNacimiento.anio);
    PERSONA3 p3;
    int i;
    p3 = cargarPersona3();
    printf("legajo:%d  nombre completo:%s %s  altura:%.2f  sexo:%c Fecha de nacimiento: %d %d %d", p2.numLegajo, p2.NomyApe.nombre, p2.NomyApe.apellido, p2.altura, p2.sexo, p2.fechaNacimiento.dia, p2.fechaNacimiento.mes, p2.fechaNacimiento.anio);
    printf("Materias aprobadas: %d",p3.cantMaterias);
    if(p3.cantMaterias==0)
    {
        printf("no se ingresaron materias");
    }
    else
    {
      for(i=0; i<p3.cantMaterias; i++)
      {
        printf("Codigo de materia: %d\n", p3.materiasAprob[i]);
      }  
    }

 
    return 0;
}

PERSONA cargarPersona1()
{
  PERSONA p1;
    p1.numLegajo = leerEnteroRango(1, 10000, "ingrese legajo:");

    printf("ingrese nombre:");
    leeryValidarTexto(p1.nombre, TAM);

    printf("ingrese apellido:");
    leeryValidarTexto(p1.apellido, TAM);

    p1.altura = leerFloatPositivo("ingrese altura:");

    p1.sexo = leerSexo("ingrese sexo:");

    p1.dia = leerEnteroRango(1, 31, "ingrese dia:");

    p1.mes = leerEnteroRango(1, 12, "ingrese mes:");

    p1.anio = leerEnteroRango(1950, 2019, "ingrese anio:");

    return p1;
}

PERSONA2 cargarPersona2()
{
  PERSONA2 p2;
    p2.numLegajo = leerEnteroRango(1, 10000, "\ningrese legajo:");

    printf("ingrese nombre:");
    leeryValidarTexto(p2.NomyApe.nombre, TAM);

    printf("ingrese apellido:");
    leeryValidarTexto(p2.NomyApe.apellido, TAM);

    p2.altura = leerFloatPositivo("ingrese altura:");

    p2.sexo = leerSexo("ingrese sexo:");

    p2.fechaNacimiento.dia = leerEnteroRango(1, 31, "ingrese dia:");

    p2.fechaNacimiento.mes = leerEnteroRango(1, 12, "ingrese mes:");

    p2.fechaNacimiento.anio = leerEnteroRango(1950, 2019, "ingrese anio:");

    return p2;
}

PERSONA3 cargarPersona3()
{
  int i;
  PERSONA3 p3;
    p3.numLegajo = leerEnteroRango(1, 10000, "\ningrese legajo:");

    printf("ingrese nombre:");
    leeryValidarTexto(p3.NomyApe.nombre, TAM);

    printf("ingrese apellido:");
    leeryValidarTexto(p3.NomyApe.apellido, TAM);

    p3.altura = leerFloatPositivo("ingrese altura:");

    p3.sexo = leerSexo("ingrese sexo:");

    p3.fechaNacimiento.dia = leerEnteroRango(1, 31, "ingrese dia:");

    p3.fechaNacimiento.mes = leerEnteroRango(1, 12, "ingrese mes:");

    p3.fechaNacimiento.anio = leerEnteroRango(1950, 2019, "ingrese anio:");

    p3.cantMaterias = leerEnteroRango(0, 36, "ingrese cantidad de materias:");

    for(i=0; i<TAM2; i++)
    {
        printf("ingrese el codigo de la materia %d:", i+1);
        scanf("%d",&p3.materiasAprob[i]);
    }

    return p3;
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
    leerTexto(texto,largo);
    while(strlen(texto) == 0)
    {
        printf("El texto no puede ser vacio. Reingrese: ");
        leerTexto(texto,largo);
    }

}

int leerEnteroRango(int min, int max, const char* mensaje)
 {
    int valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Error. Valor fuera de rango. Reingrese: ");
        scanf("%d", &valor);
    }
    return valor;
}

float leerFloatPositivo(const char* mensaje)
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

char leerSexo(const char* mensaje)
 {
    char sexo;
    printf("%s", mensaje);
    fflush(stdin);
    scanf(" %c", &sexo);
    while (sexo != 'F' && sexo != 'M') {
        printf("Error. Debe ser F o M  (Mayuscula). Reingrese:");
        scanf(" %c", &sexo);
    }
    return sexo;
}