#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integrate.h"
#include "constants.h"

double x;
double y;
double z;
double R = 0.1; //meters
double H = 1.0; //meters
double N = 100.0; //Turns in the coil
double a;
double I = 1.0; //Amps


double function(double th) 
{
  double rx = x - (R * cos(th));
  double ry = y - (R * sin(th));
  double rz = z - (a * th);
  double dlx = -R * sin(th);
  double dly = R * cos(th);
  //double dlz = a;
  double crossZ = (dlx * ry) - (rx * dly);
  double r3 = pow(sqrt((rx * rx) + (ry * ry) + (rz * rz)), 3.0);
  return ((1e-7)*((crossZ * I) / r3)); //Z component
}

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc;

  if (argc != 4) {
    fprintf(stderr,"%s <x> <y> <z>\n",argv[0]);
    exit(1);
  }
  x = atof(argv[1]);
  y = atof(argv[2]);
  z = atof(argv[3]);
  xstart = -PI * N;
  xstop = PI * N;
  xinc = (TWO_PI * N) / 2000.0;
  a = H / (N * TWO_PI);
  printf("Trapezoidal rule:\n");
  trapezoidal(function,xstart,xstop,xinc);
  printf("Simpson's rule:\n");
  simpson(function,xstart,xstop,xinc);
  exit(0);
}

