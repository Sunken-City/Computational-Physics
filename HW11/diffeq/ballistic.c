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

double mass,v0,theta,alpha;

void ballistic(int n,double x,double y[4],double yp[4]) {
  double v;
  v = sqrt((y[2] * y[2]) + (y[3] * y[3]));   /*Complete this statement */
  yp[0] = y[2];   /*Complete this statement */
  yp[1] = y[3];   /*Complete this statement */
  yp[2] = -(alpha * v * y[2]) / mass;   /*Complete this statement */
  yp[3] = (-(alpha * v * y[2]) / mass) - GRAVITATIONAL_ACCEL;   /*Complete this statement */
}

int main(int argc,char *argv[]) {
  double xstop,xinc,y[4];
  if (argc != 7) {
    fprintf(stderr,"%s <mass> <launch velocity> <launch angle> <alpha> <tstop> <tinc>\n",argv[0]);
    exit(1);
  }
  mass = atof(argv[1]);
  v0 = atof(argv[2]);
  theta = atof(argv[3]) * DEGTORAD;
  alpha = atof(argv[4]);
  xstop = atof(argv[5]);
  xinc = atof(argv[6]);
  y[0] = 0.0;   /*Complete this statement */
  y[1] = 0.0;   /*Complete this statement */
  y[2] = v0 * cos(theta);   /*Complete this statement */
  y[3] = v0 * sin(theta);   /*Complete this statement */
  rk4(4,ballistic,0.0,xstop,xinc,y);
  exit(0);
}
