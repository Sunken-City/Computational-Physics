#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

double M;

double f(double e) {
  double y;
  y =   ;  /* Complete this statement */
  return(y);
}

double fp(double e) {
  double yp;
  yp =   ;   /* Complete this statement */
  return(yp);
}

int main(int argc,char *argv[]) {
  double e;

  if (argc != 2) {
    fprintf(stderr,"%s <e>\n",argv[0]);
    exit(1);
  }
  e = atof(argv[1]);
  newton_raphson(f,fp,e,100,1.0e-9,1.0e-30);
  exit(0);
}
