#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sweep_roots.h"
#include "constants.h"

double f(double I) {
  double y;
  y = -5.0 + (I * 240.0) + (((BOLTZMANN * 300.0)/(CHARGE))*log(I/6.18e-26));
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
