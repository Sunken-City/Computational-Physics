#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "diffeq.h"
#include "constants.h"

/*
  Simple pendulum
  State variable 0 is displacement angle
  State variable 1 is angular velocity
  length = pendulum length in meters
*/

double length, alpha, F, wf;

void pendulum(int n,double t,double y[2],double yp[2]) {
  yp[0] = y[1];
  yp[1] = -(GRAVITATIONAL_ACCEL/length) * sin(y[0]) - (alpha * y[1]) + (F * cos(wf * t));
}

int main(int argc,char *argv[]) {
  double xstop,xinc,y[2];

  if (argc != 9) {
    fprintf(stderr,"%s <length> <init y0> <init y1> <F> <alpha> <wf> <tstop> <tinc>\n",argv[0]);
    exit(1);
  }
  length = atof(argv[1]);
  y[0] = atof(argv[2]);
  y[1] = atof(argv[3]);
  F = atof(argv[4]);
  alpha = atof(argv[5]);
  wf = atof(argv[6]);
  xstop = atof(argv[7]);
  xinc = atof(argv[8]);
  rk4(2,pendulum,0.0,xstop,xinc,y);
  exit(0);
}
