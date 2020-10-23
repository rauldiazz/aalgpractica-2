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
#include <stdlib.h>
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

int merge(int *tabla, int ip, int iu, int imedio)
{
    int i = ip;
    int j = imedio + 1;
    int k = 0;
    int cont = 0;
    int *aux=NULL;
    assert(ip >= 0 && iu >= 0 && ip <= iu);
    assert(tabla);
    aux = (int*)malloc((iu - ip + 1) * sizeof(int));
    if (!aux)
        return ERR;


    while (i <= imedio && j <= iu)
    {
        if (tabla[i] < tabla[j])
        {
            aux[k] = tabla[i];
            i++;
        }
        else
        {
            aux[k] = tabla[j];
            j++;
        }
        k++;
        cont++;
    }
    if (i > imedio)
    {
        while (j <= iu)
        {
            aux[k] = tabla[j];
            j++;
            k++;
        }
    }
    else if (j > iu)
    {
        while (i <= imedio)
        {
            aux[k] = tabla[i];
            i++;
            k++;
        }
    }
    for (i = ip, j = 0; i <= iu; i++, j++)
    {
        tabla[i] = aux[j];
    }
    free(aux);
    return cont;
}

int mergesort(int *tabla, int ip, int iu)
{
    int cont = 0;
    int num1=0, num2=0, num3=0, m=0;

    assert(ip >= 0 && iu >= 0 && ip <= iu && tabla);

    if (iu == ip)
        return 0;

    else if (ip<iu)
    {
        m = (ip + iu) / 2;
        num1 = mergesort(tabla, ip, m);
        if (num1 != ERR)
            cont += num1;
        num2 = mergesort(tabla, m + 1, iu);
        if (num2 != ERR)
            cont += num2;
        num3 = merge(tabla, ip, iu, m);
        if (num3 != ERR)
            cont += num3;
    }
    return cont;
}
