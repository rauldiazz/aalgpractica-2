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



short merge(int *tabla, int ip, int iu, int imedio){
    int i, j, k, cont=0;
    int *aux;
    assert(ip >= 0&&iu>=0&&ip<=iu);
    assert(tabla);
    aux = (int *)malloc((iu - ip + 1) * sizeof(aux[0]));
    if (!aux)
        return ERR;

    i = ip;
    j = imedio + 1;
    k = ip;
    while (i <= imedio && j <= iu)
    {
        if (++cont&&tabla[i] < tabla[j])
        {
            aux[k] = tabla[i];
            i++;
        }
        else
        {
            aux[k] = tabla[j];
            j++;
            k++;
        }
    }
    if (i > imedio) {
        while (j <= iu)
        {
            aux[k] = tabla[j];
            j++;
            k++;
        }
    }
    else if (j > iu)
    {                                             
        while (i < imedio)
        {
            aux[k] = tabla[i];
            i++;
            k++;
        }
    }
    for (i = ip, j = 0; i < iu; i++, j++)
        {
            tabla[i] = aux[j];
        }
        free(aux);
        return cont;
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