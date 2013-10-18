#include <stdio.h>
#include <stdlib.h>
#include "lineq.h"

int main(int argc,char *argv[]) {
  double b0,b1,b2,b3,b4,b5;
  if (argc != 7) 
  {
    fprintf(stderr,"%s <b5> <b4> <b3> <b2> <b1> <b0>\n",argv[0]);
    exit(1);
  }
  b5 = atof(argv[1]);
  b4 = atof(argv[2]);
  b3 = atof(argv[3]);
  b2 = atof(argv[4]);
  b1 = atof(argv[5]);
  b0 = atof(argv[6]);
  
  double **a,*rhs,*x;
  int n = 6;
  a = alloc_matrix(n,n);
  int i = 0;
  int j = 0;
  //Initialize all values to zero
  for(; i < 6; i++)
  {
    for(; j < 6; j++)
    {
      a[i][j] = 0.0;
    }
  }
  
  //Initialize the first set of 1's
  for(i = 1; i < 6; i++)
  {
    a[i-1][i] = 1.0;
  }
  
  //Initialize the second set of 1's
  for(i = 0; i < 5; i++)
  {
    a[i+1][i] = 1.0;
  }
  
  //Initialize the terms on the diagonal
  a[0][0] = -2.0;
  a[1][1] = -2.5;
  a[2][2] = -2.5;
  a[3][3] = -2.5;
  a[4][4] = -2.5;
  a[5][5] = -1.5;
  
  
  rhs = (double *) malloc(n * sizeof(double));
  rhs[0] = -0.5 * b0 * 5.0;
  rhs[1] = -0.5 * b1 * 5.0;
  rhs[2] = -0.5 * b2 * 5.0;
  rhs[3] = -0.5 * b3 * 5.0;
  rhs[4] = -0.5 * b4 * 5.0;
  rhs[5] = -0.5 * b5 * 5.0;
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
  
  /* code to check the values in the array
  for(i = 0; i < 6; i++)
  {
    for(j = 0; j < 6; j++)
    {
      printf("%g", a[i][j]);
    }
    printf("\n");
  }*/
  exit(0);
}
