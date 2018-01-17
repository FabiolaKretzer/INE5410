/******************************************************************************
* FILE: omp_bug6.c
* DESCRIPTION:
*   Another OpenMP program with a bug.
* AUTHOR: Blaise Barney  6/05
* LAST REVISED: 06/30/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define VECLEN 100

float a[VECLEN], b[VECLEN];

float dotprod ()
{
  int i,tid;
  float sum;

#pragma omp parallel shared(sum) firstprivate(i) shared(a,b)
#pragma omp for reduction(+:sum)
  for (i=0; i < VECLEN; i++)    {
      sum = sum + (a[i]*b[i]);
      printf("  tid= %d i=%d\n",tid,i);
    }
}


int main (int argc, char *argv[]) {
  int i;
  float sum;

  for (i=0; i < VECLEN; i++)
    a[i] = b[i] = 1.0 * i;
  sum = 0.0;

  dotprod();

  printf("Sum = %f\n",sum);

}
