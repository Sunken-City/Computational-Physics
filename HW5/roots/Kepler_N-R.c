#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double M;
double e;

double f(double E) {
  double f;
  f =   E - e*sin(E) - M;  /* Complete this statement */
  return(f);
}

double fp(double E) {
  double fp;
  fp =   1 - e*cos(E);   /* Complete this statement */
  return(fp);
}

int main(int argc,char *argv[]) {


  if (argc != 3) {
    fprintf(stderr,"%s <e> <M>\n",argv[0]);
    exit(1);
  }
  e = atof(argv[1]);
  M = atof(argv[2]);
  newton_raphson(f,fp,M,100,1.0e-9,1.0e-30);
  exit(0);
}
