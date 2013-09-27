#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "sweep.h"

double D0 = -15.0; //Distance from source to aperture
double D1 = 15.0; //Distance from aperture to screen
double W = 1.0; //Width of aperture
double x0; //Location of point source
double lambda; //Wavelength

double wavelets(double x)
{
  double intensity;
  double d0; //Path length from source to aperture
  double d1; //Path length from aperture to screen
  double phi; //Phase shift for the problem
  double realTotal = 0.0; //Sum of the real components
  double imagTotal = 0.0; //Sum of the imaginary components
  double x1 = -W/2.0;
  for (int i = 0; i < 1000; i++)
  {
    x1 += 0.001;
    d0 = sqrt(pow(D0, 2.0) + pow(x1 - x0, 2.0));
    d1 = sqrt(pow(D1, 2.0) + pow(x1 - x, 2.0));
    phi = (TWO_PI * (d0 + d1)) / lambda;
    realTotal = cos(phi);
    imagTotal = sin(phi);
  }
  intensity = sqrt(pow(realTotal, 2.0) + pow(imagTotal, 2.0));
  return(intensity);
}

int main(int argc,char *argv[])
{

  if (argc != 5)
  {
    fprintf(stderr,"%s <lambda> <x0> <tmax> <tstep>\n",argv[0]);
    exit(1);
  }
  lambda = atof(argv[1]);
  x0 = atof(argv[2]);
  double tmax = atof(argv[3]);
  double tstep = atof(argv[4]);
  sweep(wavelets,-10.0,tmax,tstep);
  exit(0);
}