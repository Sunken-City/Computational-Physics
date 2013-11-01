#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sweep.h"
#include "constants.h"

double runge(double x) {
  return();  /*Complete this line*/
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
  sweep(runge,xstart,xstop,xinc);
  exit(0);
}
