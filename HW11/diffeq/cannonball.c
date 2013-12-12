#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "diffeq.h"
#include "constants.h"

/*
  Ballistic flight with air drag
  State variable 0 is x component of position
  State variable 1 is y component of position
  State variable 2 is x component of velocity
  State variable 3 is y component of velocity
  mass = projectile mass
  v0 = launch speed
  theta = launch angle
  alpha = drag coefficient, as in drag force = alpha * speed^2
*/
double e0 = 8.854e-12;

double R;
double mass = 4.0 * 1.67262178e-27;

void ballistic(int n,double x,double y[4],double yp[4]) {
  double q2;
  double r2 = (y[0] * y[0]) + (y[1] * y[1]);
  double r = sqrt(r2);
  double r3 = r2 * r;
  if (r > R)
  {
    q2 = 79.0 * CHARGE;
  }
  else
  {
    q2 = 79.0 * CHARGE * ((r*r*r)/(R*R*R));
  }
  yp[0] = y[2];   /*Complete this statement */
  yp[1] = y[3];   /*Complete this statement */
  yp[2] = ((1.0/(FOUR_PI * e0)) * ((2.0 * CHARGE * q2 * y[0]) / r3)) / mass;
  yp[3] = (1.0/(FOUR_PI * e0)) * ((2.0 * CHARGE * q2 * y[1]) / r3) / mass;   /*Complete this statement */
}

int main(int argc,char *argv[]) {
  double xstop,xinc,y[4];
  if (argc != 4) {
    fprintf(stderr,"%s <R> <tstop> <tinc>\n",argv[0]);
    exit(1);
  }
  R = atof(argv[1]);
  xstop = atof(argv[2]);
  xinc = atof(argv[3]);
  y[0] = -10.0 * R;
  y[1] = 0.5 * R;
  y[2] = 2e7;
  y[3] = 0.0;
  rk4(4,ballistic,0.0,xstop,xinc,y);
  exit(0);
}
