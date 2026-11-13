    /*. Los datos de los alumnos de una comisión de Computación Transversal son:
    • Número de DNI (entero)
    • Nombre y Apellido (80 caracteres)
    • Nota1, Nota2 (entero)
    • Nota Promedio (real, calculado según Nota1 y Nota2)
    a. Declarar un tipo de dato que contenga la información del alumno.
    b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
    información de grabación finaliza con DNI cero.
    c. Leer los datos del archivo, mediante la Función LECTURA.*/


    #include <stdio.h>
    #include <string.h>
    #define TAM 81
    typedef struct ej1
    {
        int DNI;
        char nomyape[TAM];
        int nota1;
        int nota2;
        float notapromedio;
    }ALUMNOS;

    void leertexto(char texto[], int largo);
    void leeryvalidartexto(char texto[], int largo);
    void leerentero(int* datos);
    void leeryvalidarDNI(int* datos);
    float promedio(int n1, int n2);
    void LECTURA(void);

    int main()
    {
        ALUMNOS alumnos;
        FILE *arch;
        arch = fopen("ALUMNOS.dat", "wb");
        if(arch == NULL)
        {
            printf("error al leer el archivo");
        }
        printf("ingrese el DNI del alumno");
        leeryvalidarDNI(&alumnos.DNI);
        while(alumnos.DNI !=0)
        {
            printf("ingrese el nombre del alumno");
            leeryvalidartexto(alumnos.nomyape, TAM);
            
            printf("ingrese la nota 1 del alumno");
            leerentero(&alumnos.nota1);
            printf("ingrese la nota 2 del alumno");
            leerentero(&alumnos.nota2);
            alumnos.notapromedio = promedio(alumnos.nota1, alumnos.nota2);
            fwrite(&alumnos, sizeof(ALUMNOS), 1, arch);
            printf("ingrese el DNI del alumno");
            leeryvalidarDNI(&alumnos.DNI);
            
        }
        fclose(arch);
        LECTURA();
        return 0;
    }

    void leertexto(char texto[], int largo)
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

    void leeryvalidartexto(char texto[], int largo)
    {
    leertexto(texto, largo);
    while(strlen(texto)==0) 
    {
        printf("Error. Reingrese:");
        leertexto(texto, largo);
    }
    }



    void leeryvalidarDNI(int* datos)
    {
    scanf("%d", datos);
    while (*datos != 0 && (*datos < 1000000 || *datos > 99999999))
    {
        printf("Error. Reingrese:");
        scanf("%d", datos);
    }
    }

   void leerentero(int* datos)
    {
    fflush(stdin);
    scanf(" %d", datos);
    while(*datos < 1 || *datos > 10) 
    {
        printf("Error. Reingrese:");
        scanf(" %d", datos);
    }
    }

    float promedio(int n1, int n2)
    {
        float prom;
        prom = (n1 + n2)/2.0 ;
        return prom;
    }

    void LECTURA(void)
{
    ALUMNOS alumnos;
    FILE *arch;

    arch = fopen("ALUMNOS.dat", "rb");
    if (arch == NULL)
    {
        printf("error al leer el archivo\n");
    }
    else
    {
        printf("\n--- LISTADO DE ALUMNOS ---\n");
        fread(&alumnos, sizeof(ALUMNOS), 1, arch);
        while (!feof(arch))
        {
            printf("DNI: %d | Nombre: %s | Nota 1: %d | Nota 2: %d | Promedio: %.2f\n",
                   alumnos.DNI, alumnos.nomyape, alumnos.nota1, alumnos.nota2, alumnos.notapromedio);
            fread(&alumnos, sizeof(ALUMNOS), 1, arch);
        }
        fclose(arch);
    }
}