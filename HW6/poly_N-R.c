#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double f(double x) {
  double y;
  y =   ;  /* Complete this statement */
  return(y);
}

double fp(double x) {
  double yp;
  yp =   ;   /* Complete this statement */
  return(yp);
}

int main(int argc,char *argv[]) {
  double x0;

  if (argc != 2) {
    fprintf(stderr,"%s <x0>\n",argv[0]);
    exit(1);
  }
  x0 = atof(argv[1]);
  newton_raphson(f,fp,x0,100,1.0e-9,1.0e-30);
  exit(0);
}
