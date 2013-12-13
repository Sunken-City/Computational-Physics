#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "sweep.h"
#include "diffeq.h"
#include "sweep_roots.h"

/*21 triangular potential wells each with a width at the top of 0.6nm,
spacing between centers of 0.625nm, and a depth of 21eV.*/

double E;
double a;
double period;

double potential(double x) 
{
  if (x < -6.5625e-9 || x > 6.5625e-9)
  {
    return 0.0;
  }
  else
  {
    double xprime = (x - period * round(x / period));// - period / 2.0;
    double slope = 7e10;
    // (x > period && x < period + 0.025e-9)
    if (xprime > 0.3e-9 || xprime < -0.3e-9)
    {
      return 0.0;
    }
    if (xprime > 0.0)
      return xprime * slope -21.0;
    else
      return xprime * -slope -21.0;
    //return -fabs(xprime * slope);
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
 rk4_quiet(2, schroedinger, -6.5625e-9 - a/2.0, 6.5625e-9 + a/2.0, a / 100.0, y);
 //...
 return(y[0]);
}
/*Function for making the actual waveform
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
}*/

int main(int argc,char *argv[])
{
  a = 0.6e-9;
  period = 0.625e-9;
  //Part 1:
  //sweep(potential, -1e-8, 1e-8, 1e-12);
  //Part 2:
  //sweep(wave_shoot,-21.0,0.0,1e-4);
  //Part 3:
  sweep_regula_falsi(wave_shoot, -5.0, 0.0, 1e-5, 500, 1e-9);
  //wave_shoot_loud(-8.8138999);
  exit(0);
}