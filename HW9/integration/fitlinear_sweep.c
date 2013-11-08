#include <stdio.h>
#include <stdlib.h>
#include "data_file.h"
#include "fitlinear.h"

struct point2d *data;
int n_points;
double a0,a1;

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc,x;

  if (argc != 5) {
    fprintf(stderr,"fitlinear_sweep <input file> <xstart> <xstop> <xinc>\n");
    exit(1);
  }
  n_points = read_data_file(argv[1],&data);
  fprintf(stderr,"Read %d points from data file %s\n",n_points,argv[1]);
  xstart = atof(argv[2]);
  xstop = atof(argv[3]);
  xinc = atof(argv[4]);
  fitlinear(n_points,&a0,&a1,data);
  fprintf(stderr,"Fit: a0=%.8g a1=%.8g\n",a0,a1);
  xstop = xstop + (xinc * 0.5);
  x = xstart;
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
    printf("%.8g %.8g\n",x,a0 + (a1 * x));
    x = x + xinc;
  }
  exit(0);
}
