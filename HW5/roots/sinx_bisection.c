#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sweep_roots.h"

double f(double x) {
  double y;
  y =   ;  /* Complete this statement */
  return(y);
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
  sweep_bisection(f,xstart,xstop,xinc,100,1.0e-9);
  exit(0);
}
