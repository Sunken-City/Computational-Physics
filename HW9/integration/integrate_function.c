#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integrate.h"
#include "constants.h"

double sdev1 = 1.0;
double sdev2 = 0.954499736104;
double sdev3 = 0.997300203937;
double mu = 0.0;

double function(double x) 
{
  double exponent = -1.0 * (pow((x - mu),2.0)/(2.0 * sdev1 * sdev1));
  return((1.0 * exp(exponent))/(sqrt(2.0 * PI * sdev1)));
}

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc;

  if (argc != 4) {
    fprintf(stderr,"%s <xstart> <xstop> <xinc>\n",argv[0]);
    exit(1);
  }
  xstart = atof(argv[1]);
  xstop = atof(argv[2]);
  xinc = atof(argv[3]);
  printf("Trapezoidal rule:\n");
  trapezoidal(function,xstart,xstop,xinc);
  printf("Simpson's rule:\n");
  simpson(function,xstart,xstop,xinc);
  exit(0);
}
