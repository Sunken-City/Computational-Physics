#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sweep_roots.h"

double f(double x) {
  double y;
  y =   ;  /* Complete this statement */
  return(y);
}

double fp(double x) {
  double yp;
  yp =   ;  /* Complete this statement */
  return(yp);
}

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc;

  if (argc != 4) {
    fprintf(stderr,"%s <xstart> <xstop> <xinc>\n",argv[0]);
    exit(1);
  }
  xstart = atof(argv[1]);
  xstop = atof(argv[2]);
  xinc = atof(argv[3]);
  sweep_newton_raphson(f,fp,xstart,xstop,xinc,100,1.0e-9,1.0e-30);
  exit(0);
}
