#include <stdio.h>
#include <stdlib.h>
#include "data_file.h"
#include "interpolate.h"

struct point2d *data;

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc,x;
  int n_points;

  if (argc != 5) {
    fprintf(stderr,"%s <input file> <xstart> <xstop> <xinc>\n",argv[0]);
    exit(1);
  }
  n_points = read_data_file(argv[1],&data);
  fprintf(stderr,"Read %d points from data file %s\n",n_points,argv[1]);
  xstart = atof(argv[2]);
  xstop = atof(argv[3]);
  xinc = atof(argv[4]);
#ifdef NEWTON
  find_newton_coeffs(n_points,data);
#endif
  xstop = xstop + (xinc * 0.5);
  x = xstart;
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
#ifdef LAGRANGE
    printf("%.8g %.8g\n",x,lagrange(n_points,data,x));
#endif
#if NEWTON
    printf("%.8g %.8g\n",x,newton(n_points,data,x));
#endif
    x = x + xinc;
  }
  exit(0);
}
