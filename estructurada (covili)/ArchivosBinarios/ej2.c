/*2. Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados. 
*/

#include <stdio.h>
#define TAM 81
#define  ARCH_ALUMNOS "ALUMNOS.dat"
#define ARCH_PROM "PROMOCIONADOS.dat"
#define ARCH_CURSADO "CURSANDO.dat"
#define ARCH_REPRO "REPROBADOS.dat"

typedef struct
{
    int DNI;
    char nomyape[TAM];
    int nota1;
    int nota2;
    float notapromedio;
} ALUMNOS;
FILE *archivo(char[], char[]);
void clasificar();
void mostrar( char[]);

int main()
{
    clasificar();
    
    printf("\n--- ARCHIVO PROMOCIONADOS ---\n");
    mostrar(ARCH_PROM);

    printf("\n--- ARCHIVO CURSADOS ---\n");
    mostrar(ARCH_CURSADO);

    printf("\n--- ARCHIVO REPROBADOS ---\n");
    mostrar(ARCH_REPRO);
    return 0;

}

void clasificar(void)
{
    ALUMNOS aux;
    FILE *fpAlumnos,*fpPromocionados,*fpCursado,*fpReprobados;
    fpAlumnos=archivo(ARCH_ALUMNOS,"rb");
    fpPromocionados=archivo(ARCH_PROM,"wb");
    fpCursado=archivo(ARCH_CURSADO,"wb");
    fpReprobados=archivo(ARCH_REPRO,"wb");
    fread(&aux, sizeof(aux),1,fpAlumnos);
    while(!feof(fpAlumnos))
    {
        if(aux.nota1 >= 7 && aux.nota2 >= 7)
        {
            fwrite(&aux, sizeof(aux),1,fpPromocionados);
        }
        else if(aux.nota1 >= 4 && aux.nota2 >= 4)
        {
            fwrite(&aux, sizeof(aux),1,fpCursado);
        }
        else
        {
            fwrite(&aux, sizeof(aux),1,fpReprobados);
        }
    }
    fclose(fpAlumnos);
    fclose(fpPromocionados);
    fclose(fpCursado);
    fclose(fpReprobados);
}

void mostrar(char nombreArchivo[])
{
    ALUMNOS aux;
    FILE *fp;
    fp=archivo(nomyape,"rb");
    fread(&aux,sizeof(aux),1,fp);
    while(!feof(fp))
    {
        printf("DNI: %d de %s con notas %d y %d y promedio %.2f\n",aux.DNI,aux.nomyape,aux.nota1,aux.nota2,aux.notapromedio);
        fread(&aux,sizeof(aux),1,fp);
    }
    fclose(fp)
}

FILE *archivo(char nombre[],char tipo)
{
    FILE *fp;
    fp=fopen(nombre,tipo);
    if(fp=NULL)
    {
        printf("Error al abrir archivo");
        getchar();
        exit(1);
    }
    return fp;
}
