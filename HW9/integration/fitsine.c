#include <stdio.h>
#include <stdlib.h>
#include "data_file.h"
#include "lineq.h"

double phi(int,double);

int fitsine(int n,double *a,struct point2d *sample) {
  int i,j,k;
  double **coeff,rhs[7];

  coeff = alloc_matrix(7,7);
  for (j = 0; j < 7; j++) {
    for (k = 0; k < 7; k++) {
      coeff[j][k] = 0.0;
      for (i = 0; i < n; i++) {
        coeff[j][k] += phi(k,sample[i].x) * phi(j,sample[i].x);
      }
    }
    rhs[j] = 0.0;
    for (i = 0; i < n; i++) {
      rhs[j] += sample[i].y * phi(j,sample[i].x);
    }
  }
  if (gauss(7,coeff,rhs,a,1.0e-18)) {
    fprintf(stderr,"Singular coefficient matrix\n");
    free_matrix(7,coeff);
    exit(1);
  }
  free_matrix(7,coeff);
  return(0);
}
