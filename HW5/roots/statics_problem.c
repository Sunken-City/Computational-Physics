#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double y_0 = 8.0; //Height off of the ground
double y_1 = 20.0; //Height of the towers
double x1 = 30.0; //Location of the right tower relative to the left tower

double f(double lambda) {
  double y;
  y =   (lambda * cosh(x1 / lambda)) - lambda  + y_0 - y_1;
  return(y);
}

int main(int argc,char *argv[]) {
  double a,b;

  if (argc != 3) {
    fprintf(stderr,"%s <a> <b>\n",argv[0]);
    exit(1);
  }
  a = atof(argv[1]);
  b = atof(argv[2]);
  bisection(f,a,b,100,1.0e-7);
  exit(0);
}
