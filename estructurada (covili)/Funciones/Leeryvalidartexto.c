void leeryValidarTexto(char texto[], int largo)
{
    leerTexto(texto,largo);
    while(strlen(texto) != 3)
    {
        printf("El texto no puede ser vacio. Reingrese: ");
        leerTexto(texto,largo);
    }

}