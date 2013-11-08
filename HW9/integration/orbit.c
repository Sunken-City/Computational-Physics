#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integrate.h"
#include "constants.h"

double e;
double a;

double function(double x) 
{
  double E = (sqrt(1.0 - ((e * e)*(sin(x) * sin(x)))));
  return 4.0 * a * E; //Circumference
}

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc;

  if (argc != 6) {
    fprintf(stderr,"%s <e> <Semi-Major axis> <xstart> <xstop> <xinc>\n",argv[0]);
    exit(1);
  }
  e = atof(argv[1]);
  a = atof(argv[2]);
  xstart = atof(argv[3]);
  xstop = atof(argv[4]);
  xinc = atof(argv[5]);
  printf("Trapezoidal rule:\n");
  trapezoidal(function,xstart,xstop,xinc);
  printf("Simpson's rule:\n");
  simpson(function,xstart,xstop,xinc);
  exit(0);
}
