#include <stdio.h>
#include <stdlib.h>
#include "lineq.h"

int main(int argc,char *argv[]) {
  double **a,*rhs,*x;
  int i,n;

  n = 2;
  a = alloc_matrix(n,n);
/* Complete these statements to initialize the coefficient matrix */
  a[0][0] = 4.0;
  a[0][1] = 3.0;
  a[0][2] = 2.0;
  a[0][3] = 1.0;
  a[1][0] = 3.0;
  a[1][1] = 2.0;
  a[1][2] = 1.0;
  a[1][3] = 4.0;
  a[2][0] = 2.0;
  a[2][1] = 1.0;
  a[2][2] = 4.0;
  a[2][3] = 3.0;
  a[3][0] = 1.0;
  a[3][1] = 0.5;
  a[3][2] = 2.0;
  a[3][3] = 1.5;
  rhs = (double *) malloc(n * sizeof(double));
/* Complete these statements to initialize the RHS vector */
  rhs[0] = -7;
  rhs[1] = 1;
  rhs[2] = 5;
  rhs[3] = 2.5;
  x = (double *) malloc(n * sizeof(double));
  if (gauss(n,a,rhs,x,1.0e-18)) {
    fprintf(stderr,"Singular coefficient matrix\n");
    free_matrix(n,a);
    free(rhs);
    free(x);
    exit(1);
  }
  i = 0;
  while (i < n) {
    printf("%.8g\n",x[i]);
    i++;
  }
  free(x);
  free_matrix(n,a);
  free(rhs);
  exit(0);
}
