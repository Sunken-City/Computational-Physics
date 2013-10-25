#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sys_roots.h"
#include "lineq.h"

int sys_newton_raphson(int n,void (*func)(int n,double *x,double *f),void (*jacobian)(int n,double *x,double **coeff),double *init,double *tol,int n_iters) {
  double **a,*d,*xcurrent,*rhs;
  int *rindex,i,i_iter,done;

  a = alloc_matrix(n,n);
  d = malloc(n * sizeof(double));
  xcurrent = malloc(n * sizeof(double));
  rhs = malloc(n * sizeof(double));
  rindex = (int *) malloc(n * sizeof(int));
  i = 0;
  while (i < n) {
    xcurrent[i] = init[i];
    i++;
  }
  i_iter = 0;
  while (i_iter < n_iters) {
    (*jacobian)(n,xcurrent,a);   /*fill current Newton-Raphson A matrix and RHS vector*/
    (*func)(n,xcurrent,rhs);
#if 0
    i = 0;
    while (i < n) {
      printf("row %d: ",i);
      int j;
      j = 0;
      while (j < n) {
        printf("%.12g ",a[i][j]);
        j++;
      }
      printf("%.12g\n",rhs[i]);
      i++;
    }
#endif
    if (gauss_pivotmax(n,a,rhs,d,rindex,1.0e-12)) {
      fprintf(stderr,"Singular Jacobian matrix\n");
      free_matrix(n,a);
      free(d);
      free(xcurrent);
      free(rhs);
      free(rindex);
      return(2);
    }
    done = 1;
    i = 0;   /*test if all x values are within convergence tolerance*/
    while (i < n) {
      xcurrent[i] -= d[rindex[i]];   /*update current x vector*/
      printf("%.12g ",xcurrent[i]);
      if (fabs(d[rindex[i]]) > tol[i]) done = 0;
      i++;
    }
    putchar('\n');
    if (done) break;
    i_iter++;
  }
  free_matrix(n,a);
  free(d);
  free(xcurrent);
  free(rhs);
  free(rindex);
  if (i_iter == n_iters) {
    fprintf(stderr,"sys_newton_raphson: Iteration limit of %d reached\n",n_iters);
    return(1);
  }
  return(0);
}
