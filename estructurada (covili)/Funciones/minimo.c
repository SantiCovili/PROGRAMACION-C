int buscarMinimo(int cantUV[], int ce){
    int min=cantUV[0];
    for (int i = 1; i < ce; i++)
    {
        if (cantUV[i]<min)
        {
            min=cantUV[i];
        }

    }
    return min;
}