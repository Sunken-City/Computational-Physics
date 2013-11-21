#include <stdio.h>
#include <stdlib.h>
#include "data_file.h"

int fitlinear(int n,double *a0ptr,double *a1ptr,struct point2d *sample) {
  int i;
  double sumx,sumy,sumxy,sumxsq,denom,nd;

  sumx = 0.0;
  sumy = 0.0;
  sumxy = 0.0;
  sumxsq = 0.0;
  i = 0;
  while (i < n) {
    sumx += sample[i].x;
    sumy += sample[i].y;
    sumxy += sample[i].x * sample[i].y;
    sumxsq += sample[i].x * sample[i].x;
    i++;
  }
  nd = n;
  denom = (nd * sumxsq) - (sumx * sumx);
  *a0ptr = ((sumxsq * sumy) - (sumx * sumxy)) / denom;
  *a1ptr = ((nd * sumxy) - (sumx * sumy)) / denom;
  return(0);
}
