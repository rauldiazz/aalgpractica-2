

#include "tiempos.h"
#include "permutaciones.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*****************************************************/
/* Función :craneo_medio_ordenacion Fecha:11/10/2020 */
/*****************************************************/

short tiempo_medio_ordenacion(pfunc_ordena metodo, int n_perms, int N, PTIEMPO ptiempo)
{
  int **per = NULL;
  int i, min = INT_MAX, max = 0, obs = 0;
  double suma = 0, t = 0;
  clock_t c1, c2;

  if (!metodo || n_perms <= 0 || N <= 0 || !ptiempo)
    return ERR;

  per = genera_permutaciones(n_perms, N);
  if (!per)
    return ERR;

  ptiempo->N = N;
  ptiempo->n_elems = n_perms;

  for (i = 0; i < n_perms; i++)
  {
    c1 = clock();
    if (c1 == -1)
      break;

    obs = metodo(per[i], 0, N - 1);
    c2 = clock();
    if (c2 == -1)
      break;

    t += (double)(c2 - c1) * (1000) / CLOCKS_PER_SEC;
    suma += obs;

    if (max < obs)
      max = obs;
    if (min > obs)
      min = obs;
  }
  ptiempo->min_ob = min;
  ptiempo->max_ob = max;

  ptiempo->medio_ob = (double)(suma / n_perms);
  ptiempo->tiempo = (double)(t / n_perms);
  for (i = 0; i < n_perms; i++)
  {
    free(per[i]);
  }
  free(per);
  return OK;
}

/********************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha: 11/13/2020 */
/********************************************************/

short genera_tiempos_ordenacion(pfunc_ordena metodo, char *fichero, int num_min, int num_max, int incr, int n_perms)
{
  PTIEMPO array;
  int n, i, c;
  short flag = OK;

  if (num_min < 0 || num_max < 0 || n_perms < 0 || incr < 0)
    return ERR;
  if (!metodo || !fichero)
    return ERR;
  if (num_min > num_max)
    return ERR;

  n = ((num_max - num_min) / incr + 1);
  array = (PTIEMPO)malloc(n * sizeof(TIEMPO));
  if (!array)
    return ERR;
  for (c = num_min, i = 0; c <= num_max && i < n && flag == OK; i++, c += incr)
  {
    flag = tiempo_medio_ordenacion(metodo, n_perms, c, &array[i]);
  }
  if (flag == ERR)
  {
    free(array);
    return ERR;
  }
  flag = guarda_tabla_tiempos(fichero, array, n);
  if (flag == ERR)
  {
    free(array);
    return ERR;
  }
  free(array);
  return OK;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha: 11/10/2020 */
/***************************************************/

short guarda_tabla_tiempos(char *fichero, PTIEMPO tiempo, int n_tiempos)
{
  FILE *pf = NULL;
  int i = 0;
  short flag = OK;

  if (!tiempo)
    return ERR;
  if (n_tiempos <= 0)
    return ERR;
  if (!fichero)
  {
    printf("Error con el fichero");
    return ERR;
  }

  pf = fopen(fichero, "w");
  if (!pf)
    return ERR;

  for (i = 0; i < n_tiempos && flag >= 0; i++)
  {
    flag = fprintf(pf, "%d  %f %f %d %d\n", tiempo[i].N, tiempo[i].tiempo, tiempo[i].medio_ob, tiempo[i].min_ob, tiempo[i].max_ob);
  }
  if (fclose(pf) != EOF)
    return flag;
  else
  {
    return ERR;
  }
}