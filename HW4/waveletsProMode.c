#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "sweep.h"

double D0 = -15.0; //Distance from source to aperture
double D1 = 15.0; //Distance from aperture to screen
double W = 1.0; //Width of aperture
double x01; //Location of point source
double x02; //Location of second point source
double lambda; //Wavelength

double wavelets(double x)
{
  double intensity;
  double d01; //Path length from source 1 to aperture
  double d02; //Path length from source 1 to aperture
  double d1; //Path length from aperture to screen
  double phi1; //Phase shift for the problem
  double phi2; //Phase shift for the problem
  double realTotal = 0.0; //Sum of the real components
  double imagTotal = 0.0; //Sum of the imaginary components
  double x1 = -W/2.0;
  int i = 0;
  for (; i < 1000; i++)
  {
    x1 += 0.001;
    d01 = sqrt(pow(D0, 2.0) + pow(x1 - x01, 2.0));
    d02 = sqrt(pow(D0, 2.0) + pow(x1 - x02, 2.0));
    d1 = sqrt(pow(D1, 2.0) + pow(x1 - x, 2.0));
    phi1 = (TWO_PI * (d01 + d1)) / lambda;
    phi2 = (TWO_PI * (d02 + d1)) / lambda;
    realTotal += cos(phi1) + cos(phi2);
    imagTotal += sin(phi1) + sin(phi2);
  }
  intensity = pow(realTotal, 2.0) + pow(imagTotal, 2.0);
  return(intensity);
}

int main(int argc,char *argv[])
{

  if (argc != 6)
  {
    fprintf(stderr,"%s <lambda> <x01> <x02> <tmax> <tstep>\n",argv[0]);
    exit(1);
  }
  lambda = atof(argv[1]);
  x01 = atof(argv[2]);
  x02 = atof(argv[3]);
  double tmax = atof(argv[4]);
  double tstep = atof(argv[5]);
  sweep(wavelets,-10.0,tmax,tstep);
  exit(0);
}