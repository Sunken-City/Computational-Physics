#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double Me = 5.98e24; //Mass of the earth
double Ms = 2.0e30; //Mass of the sun
double R = 1.5e11; //Radius of earth's orbit

double f(double x) {
  double y;
  y =   (R*R*R*Ms*x*x) + (R*R*R*Me*(R+x)*(R+x)) - ((R+x)*(R+x)*(R+x)*x*x*Ms);
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
  secant(f,a,b,100,1000.0);
  exit(0);
}
