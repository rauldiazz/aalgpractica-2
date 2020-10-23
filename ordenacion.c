/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */
#include <assert.h>
#include "ordenacion.h"

/***************************************************/
/* Funcion: InsertSort    Fecha:  08/07/2020       */
/***************************************************/

int InsertSort(int *tabla, int ip, int iu)
{
  int a, i, j, cont = 0;
  if (!tabla || ip < 0 || iu < 0)
    return -1;
  for (i = ip + 1; i <= iu; i++)
  {

    a = tabla[i];
    j = i - 1;

    while (j >= ip && ++cont && tabla[j] > a)
    {
      tabla[j + 1] = tabla[j];
      j--;
    }

    tabla[j + 1] = a;
  }
  return cont;
}

int InsertSortInv(int *tabla, int ip, int iu)
{
  int a, i, j, cont = 0;
  if (!tabla || ip < 0 || iu < 0)
    return -1;
  for (i = ip + 1; i <= iu; i++)
  {

    a = tabla[i];
    j = i - 1;
    while (j >= ip && ++cont && tabla[j] < a)
    {
      tabla[j + 1] = tabla[j];
      j--;
    }

    tabla[j + 1] = a;
  }
  return cont;
}



short Combinar(int *t, int p, int m, int u){
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
    if (i > m) {
        while (j <= u)
        {
            aux[k] = t[j];
            j++;
            k++;
        }
    }
    else if (j > u)
    {                                             
        while (i < m)
        {
            aux[k] = t[i];
            i++;
            k++;
        }
    }
    for (i = p, j = 0; i < u; i++, j++)
        {
            t[i] = aux[j];
        }
        free(aux);
        return OK;
    }




int mergesort(int* tabla, int ip, int iu){
    int cont=0;
    int num1,num2,num3,m;

    assert(ip>=0&&iu>=0&&ip<=iu&&tabla);

    if(iu==ip) return 0;

    else{
        m=(ip+iu)/2;
        num1=mergesort(tabla,ip,m);
        if(num1!=ERR) cont +=num1;
        num2=mergesort(tabla, m+1,iu);
        if(num2!=ERR) cont+=num2;
        num3=merge(tabla,ip,iu,m);
        if(num3!=ERR) cont+=num3;
    }
    return cont;
}