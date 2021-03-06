/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *hola
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
  int *aux = NULL;
  assert(ip >= 0 && iu >= 0 && ip <= iu);
  assert(tabla);
  aux = (int *)malloc((iu - ip + 1) * sizeof(int));
  if (!aux)
    return ERR;

  while (i <= imedio && j <= iu)
  {
    if (++cont && tabla[i] < tabla[j])
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
    //cont++;
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
  int num1 = 0, num2 = 0, num3 = 0, m = 0;

  assert(ip >= 0 && iu >= 0 && ip <= iu && tabla);

  if (iu == ip)
    return 0;

  else if (ip < iu)
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

int medio(int *tabla, int ip, int iu, int *pos)
{
  (*pos) = ip;
  return OK;
}

int swap(int *a, int *b)
{
  int aux;
  assert(a && b);
  aux = (*a);
  (*a) = (*b);
  (*b) = aux;
  return OK;
}

int partir(int *tabla, int ip, int iu, int *pos)
{
  int k, i, piv, cont = 0, flag;

  assert(ip >= 0 && iu > ip && pos && tabla);

  flag = medio(tabla, ip, iu, pos);
  piv = (*pos);
  k = tabla[piv];
  swap(&tabla[ip], &tabla[piv]);
  piv = ip;

  for (i = ip + 1; i <= iu; i++, cont++)
  {
    if (tabla[i] < k)
    {
      piv++;
      swap(&tabla[i], &tabla[piv]);
    }
  }
  swap(&tabla[ip], &tabla[piv]);
  (*pos) = piv;
  return cont;
}

/*static int cont2=0;


int quicksort(int *tabla, int ip, int iu)
{

  int m;
  int flag = 0;
  //int cont = 0;

  assert(ip >= 0 && iu >= 0 && tabla);
  if (ip == iu)
    return 1;
 


  if(ip<iu){
    cont2 += partir(tabla, ip, iu, &m);
    if (ip < (m - 1))
    {
      quicksort(tabla, ip, m - 1);
    }
    if ((m + 1) < iu)
    {
      quicksort(tabla, m + 1, iu);
    }
  }

  return cont2;
}*/

int quicksort(int *tabla, int ip, int iu)
{

  int m;
  int flag = 0;
  int cont = 0;

  assert(ip >= 0 && iu >= 0 && tabla);
  if (ip == iu)
    return 0;

  if (ip < iu)
  {
    cont += partir(tabla, ip, iu, &m);
    if (ip < (m - 1))
    {
      cont += quicksort(tabla, ip, m - 1);
    }
    if ((m + 1) < iu)
    {
      cont += quicksort(tabla, m + 1, iu);
    }
  }

  return cont;
}

/*

int quicksortsrc(int *tabla, int ip, int iu){
  int m,ip1,iu1;
  int flag = 0;
  int cont=0;

  //assert(ip >= 0 && iu >= 0 && tabla);
  //if (ip == iu)
  //return 0;




}*/

int quicksortsrc(int *tabla, int ip, int iu)
{

  int pila[iu - ip + 1];
  int cont = 0;

  int top = -1, p;

  assert(tabla && ip >= 0 && iu >= 0);

  pila[++top] = ip;
  pila[++top] = iu;

  if (ip == iu)
    return 0;

  while (top >= 0)
  {

    iu = pila[top--];
    ip = pila[top--];

    cont += partir(tabla, ip, iu, &p);

    if (p - 1 > ip)
    {
      pila[++top] = ip;
      pila[++top] = p - 1;
    }

    if (p + 1 < iu)
    {
      pila[++top] = p + 1;
      pila[++top] = iu;
    }
  }
  return cont;
}