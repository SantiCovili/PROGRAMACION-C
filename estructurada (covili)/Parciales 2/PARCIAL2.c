/*
Una empresa distribuidora de energia electrica posee un archivo binario llamado "consumo.dat". Cada registro almacena la lectura de un medidor 
con el siguiente formato:
-Zona Geografica (int)
-Numero de Cliente (int)
-Consumo en kWh (float)

El archivo está ordenado por el campo Zona Geografica. 
Se solicita diseñar unn programa en C que lea el archivo secuencialmente y aplique Corte de Control para informar:
1- El consumo promedio de kWh por cada Zona Geografica.
2- Cual fue la Zona Geografica que registro el mayor consumo total de energia.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int zona;
    int Cliente;
    float Consumo;
}CONSUMO;

FILE *AbrirArchivo(char nombre[], char tipo[]);
void procesarArchivo();

int main()
{
    procesarArchivo();
    return 0;
}

void procesarArchivo()
{
    FILE *archConsumo;
    CONSUMO aux;
    int zonaAnterior, cliente, zonaMayorConsumo;
    float sumaConsumo, mayorConsumo=-1, promedio;
    archConsumo = AbrirArchivo("consumo.dat","rb");
    fread(&aux,sizeof(aux),1,archConsumo);
    while(!feof(archConsumo))
    {
        zonaAnterior = aux.zona;
        sumaConsumo=0;
        cliente=0;
        while(!feof(archConsumo) && zonaAnterior == aux.zona)
        {
            sumaConsumo += aux.Consumo;
            cliente++;
            fread(&aux,sizeof(aux),1,archConsumo);
        }
        promedio = sumaConsumo/cliente;
        printf("En la zona %d el consumo promedio de kWh es: %f",zonaAnterior,promedio);
        if(sumaConsumo<mayorConsumo)
        {
            mayorConsumo = sumaConsumo;
            zonaMayorConsumo = zonaAnterior;
        }
    }
    printf("la Zona Geografica que registro el mayor consumo total de energia: %d",zonaMayorConsumo);
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
