#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "diffeq.h"

/*
  Damped harmonic oscillator
  State variable 0 is displacement
  State variable 1 is velocity
*/

double Q,w0,F,wf;

void harmonic_osc(int n,double x,double y[2],double yp[2]) {
  yp[0] = ;   /*Complete this statement */
  yp[1] = ;   /*Complete this statement */
}

int main(int argc,char *argv[]) {
  double xstop,xinc,y[2];

  if (argc != 9) {
    fprintf(stderr,"%s <w0> <Q> <wf> <F> <init y0> <init y1> <tstop> <tinc>\n",argv[0]);
    exit(1);
  }
  w0 = atof(argv[1]);
  Q = atof(argv[2]);
  wf = atof(argv[3]);
  F = atof(argv[4]);
  y[0] = atof(argv[5]);
  y[1] = atof(argv[6]);
  xstop = atof(argv[7]);
  xinc = atof(argv[8]);
  rk4(2,harmonic_osc,0.0,xstop,xinc,y);
  exit(0);
}
