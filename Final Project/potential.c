#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "sweep.h"
#include "diffeq.h"
#include "sweep_roots.h"

double E;
double a;

double potential(double x) 
{
  if (x < -5e-10 || x > 5e-10)
  {
    return 0.0;
  }
  else
  {
    return -10.0;
  }
}

void schroedinger(int n,double x,double y[2],double yp[2]) 
{
/* Calculate first order derivatives for R-K4 algorithm*/
 yp[0] = y[1];
 yp[1] = 5.1363071e13 * 0.5110e6 * (potential(x) - E) * y[0];
}

double wave_shoot(double energy) 
{
 double k, y[2];
 E = energy;
 k = sqrt(-5.1363071e13 * 0.5110e6 * E);
 y[0] = exp(-k * a);
 y[1] = k * y[0];
 rk4_quiet(2, schroedinger, -a, a, a / 100.0, y);
 //...
 return(y[0]);
}

void wave_shoot_loud(double energy) 
{
 double k, y[2];
 E = energy;
 k = sqrt(-5.1363071e13 * E);
 y[0] = exp(-k * a);
 y[1] = k * y[0];
 rk4(2, schroedinger, -a, a, a / 100.0, y);
 //...
 //return(y[0]);
}

int main(int argc,char *argv[])
{
  a = 1e-9;
//   if (argc != 5)
//   {
//     fprintf(stderr,"%s <lambda> <x0> <tmax> <tstep>\n",argv[0]);
//     exit(1);
//   }
//   lambda = atof(argv[1]);
//   x0 = atof(argv[2]);
//   double tmax = atof(argv[3]);
//   double tstep = atof(argv[4]);
  //sweep(wave_shoot,-10.0,0.0,1e-4);
  sweep_regula_falsi(wave_shoot, -10.0, 0.0, 1e-5, 500, 1e-9);
  //wave_shoot_loud(-8.8138999);
  exit(0);
}