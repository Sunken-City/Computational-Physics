#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double y0 = 8.0;

double f(double lambda) {
  double y;
  y =   lambda * cosh() - lambda  + y0;  /* Complete this statement */
  return(y);
}

int main(int argc,char *argv[]) {
  double a,b;

  if (argc != 3) {
    fprintf(stderr,"%s <a> <b>\n",argv[0]);
    exit(1);
  }
  a = atof(argv[1]);
  b = atof(argv[2]);
  bisection(f,a,b,100,1.0e-9);
  exit(0);
}
