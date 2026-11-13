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
typedef struct ej11
{
    int canal;
    char programa[TAM];
    float rating;
}RATING;

typedef struct 
{
    int numeroCanal;
    float PromedioRating;
}PROMEDIO;

void procesarArchivo();
FILE *AbrirArchivo(char nombre[], char tipo[]);


int main()
{
    procesarArchivo();
    return 0; 

}

void procesarArchivo()
{
    FILE *archRating, *archPromedio;
    RATING auxRating;
    PROMEDIO auxPromedio;
    int canalAnterior, canalMasVisto, programas;
    float promedio,sumaRating, mayorRating=-1;
    archRating = AbrirArchivo("Rating.dat","rb");
    archPromedio = AbrirArchivo("Promedios.dat","wb");
    fread(&auxRating,sizeof(auxRating),1,archRating);
    while(!feof(archRating))
    {
        canalAnterior=auxRating.canal;
        sumaRating=0;
        programas=0;
        while(!feof(archRating) && canalAnterior==auxRating.canal)
        {
            sumaRating += auxRating.rating;
            programas++;
            fread(&auxRating,sizeof(auxRating),1,archRating);
        }
        if(sumaRating>15)
        {
            printf("El canal %d tiene mas de 15 puntos de rating", canalAnterior);
        }
        if(mayorRating<sumaRating)
        {
            mayorRating = sumaRating;
            canalMasVisto = canalAnterior;
        }
        promedio = sumaRating/programas;
        auxPromedio.numeroCanal = canalAnterior;
        auxPromedio.PromedioRating = promedio;
        fwrite(&auxPromedio, sizeof(auxPromedio),1,archPromedio);
    }
    printf("el canal mas visto es:%d",canalMasVisto);
    fclose(archRating);
    fclose(archPromedio);
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
