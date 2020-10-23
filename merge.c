

short Combinar(int *t, int p, int m, int u)
{
    int i, j, k;
    int *aux;
    assert(i >= 0);
    assert(t);
    aux = (int *)malloc((u - p + 1) * sizeof(aux[0]));
    if (!aux)
        return ERR;

    i = p;
    j = m + 1;
    k = p;

    while (i <= m && j <= u)
    {
        if (t[i] < t[j])
        {
            aux[k] = t[i];
            i++;
        }
        else
        {
            aux[k] = t[j];
            j++;
            k++;
        }
    }
    if (i > m) // copiar resto de tabla derecha
        while (j <= u)
        {
            aux[k] = t[j];
            j++;
            k++;
        }
    else if (j > u)
    { // copiar resto de tabla izquierda
        while (i < m)
        {
            aux[k] = t[i];
            i++;
            k++;
        }
    for (i = p, j = 0; i < u; i++, j++)
        {
            t[i] = aux[j];
        }
        free(aux);
        return t;
    }