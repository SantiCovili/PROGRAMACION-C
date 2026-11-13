void burbujeo(char cod[][TXT],float precio[],int ce)
{
    char AUX[TXT];
    float auxP;
    int j, cota = ce-1;
    int desordenado = 1;

    while(desordenado)
    {
        desordenado = 0;
        for(j=0;j<cota;j++)
        {
            if(strcmpi(cod[j],cod[j+1]) > 0)
            {
                strcpy(AUX,cod[j]);
                strcpy(cod[j],cod[j+1]);
                strcpy(cod[j+1],AUX);
                auxP = precio[j];
                precio[j] = precio[j+1];
                precio[j+1] = auxP;
                desordenado = j;

            }
        }
        cota = desordenado;
    }
}