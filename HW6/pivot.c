#include <stdio.h>
#include <stdlib.h>
#include "lineq.h"

int main(int argc,char *argv[]) {
  double **a,*rhs,*x,d;
  int i,n,*rindex;

  n = 2;
  d = ;   /* Complete this statement */
  a = alloc_matrix(n,n);
  rhs = (double *) malloc(n * sizeof(double));
/*
   Use 'naive' Gaussian elimination
*/
  a[0][0] = ;   /* Complete these statements */
  a[0][1] = ;
  a[1][0] = ;
  a[1][1] = ;
  rhs[0] = ;
  rhs[1] = ;
  x = (double *) malloc(n * sizeof(double));
  if (gauss(n,a,rhs,x,1.0e-18)) {
    fprintf(stderr,"Singular coefficient matrix\n");
    free_matrix(n,a);
    free(rhs);
    free(x);
    exit(1);
  }
  printf("Gaussian elimination without pivoting:\n");
  i = 0;
  while (i < n) {
    printf("%.12g\n",x[i]);
    i++;
  }
/*
   Use Gaussian elimination with scaled partial pivoting
*/
  a[0][0] = ;   /* Complete these statements */
  a[0][1] = ;
  a[1][0] = ;
  a[1][1] = ;
  rhs[0] = ;
  rhs[1] = ;
  rindex = (int *) malloc(n * sizeof(int));
  if (gauss_pivotmax(n,a,rhs,x,rindex,1.0e-18)) {
    fprintf(stderr,"Singular coefficient matrix\n");
    free_matrix(n,a);
    free(rhs);
    free(x);
    free(rindex);
    exit(1);
  }
  printf("Gaussian elimination with scaled partial pivoting:\n");
  i = 0;
  while (i < n) {
    printf("%.12g\n",x[rindex[i]]);
    i++;
  }
  free(x);
  free_matrix(n,a);
  free(rhs);
  free(rindex);
  exit(0);
}
