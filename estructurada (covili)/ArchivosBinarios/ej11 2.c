/*11. Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating
en los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
• Número de canal (entero)
• Programa (texto de 35 caracteres máximo)
• Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
a. Aquellos canales que obtengan menos de 15 puntos en total.
b. El canal más visto.
c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
• Número de canal.
• Promedio. */
#include <stdio.h>
#include <stdlib.h>
#define TAM 36
typedef struct 
{
    int numeroCanal;
    char programa[TAM];
    float rating;
}PROGRAMA;

typedef struct 
{
    int numeroCanal;
    float promedio;
}PROMEDIO;

FILE *AbrirArchivo(char nombre[], char tipo[]);

int main()
{
    FILE *archPrograma, *archPromedio;
    PROGRAMA auxprograma;
    PROMEDIO auxpromedio;
    archPrograma = AbrirArchivo("Rating.dat", "rb");
    archPromedio = AbrirArchivo("Promedio.dat", "wb");
    int canalAnterior, programa, canalMasVisto=0, primerCanal=1;
    float SumaRating, mayorRating=0;
    fread(&auxprograma, auxprograma, 1 , archPrograma);
    while(!feof(archPrograma))
    {
        canalAnterior = auxprograma.canal;
        programa=0;
        SumaRating=0;
        while(!feof(archPrograma) && canalAnterior = auxprograma.canal)
        {
            programa ++;
            SumaRating += auxprograma.rating;
            fread(&auxprograma, sizeof(auxprograma),1,archRating);
        }
        if(sumaRating < 15)
        {
            printf("\nEl canal %d tiene menos de 15 puntos de rating. ", canalAnterior);
        }
        if (PrimerCanal==1 || SumaRating > MayorRating)
        {
            mayorRating = SumaRating;
            canalMasVisto = canalAnterior;
            primerCanal = 0;
        }
        if(programa>0)
        {
            auxpromedio.promedio = SumaRating/programa;
        }
        else
        {
            auxpromedio.promedio=0;
        }
        fwrite(&auxpromedio, sizeof(auxpromedio), 1, archPromedio);
    }
    fclose(archRating);
    fclose(archPromedio);
    printf("\nEl canal mas visto es el %d. ", CanalMasVisto);
    return 0;
}

FILE *AbrirArchivo(char nombre[], char tipo[])
{
    FILE *fp;
    fp=fopen(nombre, tipo);
    if(fp==NULL)
    {
        printf("Error, no se pudo abrir el archivo \n");
        exit(1);
    }
    return(fp);
}
