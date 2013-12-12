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

double ms = 1.99e30;
double mj = 1.90e27;
double r1 = 7.78e11;
double r2 = 9.725e11;

void ballistic(int n,double x,double y[12],double yp[12]) {
  //sqrt( (rjx-rix) ^2 + (rjy-riy)^2) )
  //The notation here is Object i, Object j, power
  double vsj1x = (y[4] - y[0]);
  double vsj1y = (y[5] - y[1]);
  double sj1sq = (vsj1x * vsj1x) + (vsj1y * vsj1y);//((y[4] - y[0]) * (y[4] - y[0])) + ((y[5] - y[1]) * (y[5] - y[1]));
  double sj1 = sqrt(sj1sq);
  double sj1cu = sj1sq * sj1;
  
  double vsj2x = (y[8] - y[0]);
  double vsj2y = (y[9] - y[1]);
  double sj2sq = (vsj2x * vsj2x) + (vsj2y * vsj2y);//((y[8] - y[0]) * (y[8] - y[0])) + ((y[9] - y[1]) * (y[9] - y[1]));
  double sj2 = sqrt(sj2sq);
  double sj2cu = sj2sq * sj2;
  
  double vj1sx = (y[0] - y[4]);
  double vj1sy = (y[1] - y[5]);
  double j1ssq = (vj1sx * vj1sx) + (vj1sy * vj1sy);//double j1ssq = ((y[0] - y[4]) * (y[0] - y[4])) + ((y[1] - y[5]) * (y[1] - y[5]));
  double j1s = sqrt(j1ssq);
  double j1scu = j1ssq * j1s;
  
  double vj1j2x = (y[8] - y[4]);
  double vj1j2y = (y[9] - y[5]);
  double j1j2sq = (vj1j2x * vj1j2x) + (vj1j2y * vj1j2y);//double j1j2sq = ((y[8] - y[4]) * (y[8] - y[4])) + ((y[9] - y[5]) * (y[9] - y[5]));
  double j1j2 = sqrt(j1j2sq);
  double j1j2cu = j1j2sq * j1j2;
  
  double vj2sx = (y[0] - y[8]);
  double vj2sy = (y[1] - y[9]);
  double j2ssq = (vj2sx * vj2sx) + (vj2sy * vj2sy);//double j2ssq = ((y[0] - y[8]) * (y[0] - y[8])) + ((y[1] - y[9]) * (y[1] - y[9]));
  double j2s = sqrt(j2ssq);
  double j2scu = j2ssq * j2s;
  
  double vj2j1x = (y[4] - y[8]);
  double vj2j1y = (y[5] - y[9]);
  double j2j1sq = (vj2j1x * vj2j1x) + (vj2j1y * vj2j1y);//double j2j1sq = ((y[4] - y[8]) * (y[4] - y[8])) + ((y[5] - y[9]) * (y[5] - y[9]));
  double j2j1 = sqrt(j2j1sq);
  double j2j1cu = j2j1sq * j2j1;
  //Sun
  yp[0] = y[2];   /*Complete this statement */
  yp[1] = y[3];   /*Complete this statement */
  yp[2] = GRAVITY * (((mj * vsj1x) / (sj1cu)) + (((mj * vsj2x) / (sj2cu))));
  yp[3] = GRAVITY * (((mj * vsj1y) / (sj1cu)) + (((mj * vsj2y) / (sj2cu))));
  //J1
  yp[4] = y[6];   //x
  yp[5] = y[7];   //y
  yp[6] = GRAVITY * (((ms * vj1sx) / (j1scu)) + (((mj * vj1j2x) / (j1j2cu))));
  yp[7] = GRAVITY * (((ms * vj1sy) / (j1scu)) + (((mj * vj1j2y) / (j1j2cu))));
  //J2
  yp[8] = y[10];   /*Complete this statement */
  yp[9] = y[11];   /*Complete this statement */
  yp[10] = GRAVITY * (((ms * vj2sx) / (j2scu)) + (((mj * vj2j1x) / (j2j1cu))));
  yp[11] = GRAVITY * (((ms * vj2sy) / (j2scu)) + (((mj * vj2j1y) / (j2j1cu))));
}

int main(int argc,char *argv[]) {
  double xstop,xinc,y[12];
  if (argc != 3) {
    fprintf(stderr,"%s <tstop> <tinc>\n",argv[0]);
    exit(1);
  }
  xstop = atof(argv[1]);
  xinc = atof(argv[2]);
  
  //double T1 = sqrt((4.0 * PI * PI * r1 * r1 * r1)/(GRAVITY * ms));
  //double T2 = sqrt((4.0 * PI * PI * r2 * r2 * r2)/(GRAVITY * ms));
  
  //Sun
  y[0] = 0.0;   /*Complete this statement */
  y[1] = 0.0;   /*Complete this statement */
  y[2] = 0.0;   /*Complete this statement */
  y[3] = 0.0;   /*Complete this statement */
  //Jupiter 1
  y[4] = r1;   /*Complete this statement */
  y[5] = 0.0;   /*Complete this statement */
  y[6] = 0.0;   /*Complete this statement */
  y[7] = 1.0 / sqrt(r1 / (GRAVITY * ms));  //(TWO_PI * r1) / T1;   //Y Velocity
  //Jupiter 2
  y[8] = -r2;   /*Complete this statement */
  y[9] = 0.0;   /*Complete this statement */
  y[10] = 0.0;   /*Complete this statement */
  y[11] = -1.0 / sqrt(r2 / (GRAVITY * ms));//-(TWO_PI * r2) / T2;   //Y velocity
  rk4(12,ballistic,0.0,xstop,xinc,y);
  exit(0);
}
