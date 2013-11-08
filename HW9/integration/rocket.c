#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integrate.h"
#include "constants.h"

double function(double m) 
{
  double vrel = 2000.0 / (1.0 + exp((100.0 - m) / 200.0)); //Subtract the mass of the rocket from the total mass
  return -vrel / m; //Final velocity
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
