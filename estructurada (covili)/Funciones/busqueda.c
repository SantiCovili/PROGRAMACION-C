int busqueda(char cod[][TXT], char codV[], int ce)
{
    int pos = -1, flag = 0, i=0;
    while(flag==0 && i<ce)
    {
        if(strcmpi(codV,cod[i]) == 0)
        {
            flag = 1;
            pos = i;
        }
        i++;
    }
    return pos;
}