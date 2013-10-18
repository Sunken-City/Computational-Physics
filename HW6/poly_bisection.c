#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double f(double x) {
  double y;
  y =   ;  /* Complete this statement */
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
  bisection(f,a,b,100,1.0e-9);
  exit(0);
}
