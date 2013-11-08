#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_file.h"
#include "fitlinear.h"
#include "constants.h"

struct point2d *data;
int n_points;
double a[7],frequency;

double phi(int i,double x) {
  if (i == 0) return(1.0);
  if (i == 1) return(sin(2.0 * PI * frequency * x));
  if (i == 2) return(cos(2.0 * PI * frequency * x));
  if (i == 3) return(sin(4.0 * PI * frequency * x));
  if (i == 4) return(cos(4.0 * PI * frequency * x));
  if (i == 5) return(sin(6.0 * PI * frequency * x));
  return(cos(6.0 * PI * frequency * x));
}

int main(int argc,char *argv[]) {
  double xstart,xstop,xinc,x,f;
  int i;

  if (argc != 6) {
    fprintf(stderr,"fitsine_sweep <input file> <frequency> <xstart> <xstop> <xinc>\n");
    exit(1);
  }
  n_points = read_data_file(argv[1],&data);
  fprintf(stderr,"Read %d points from data file %s\n",n_points,argv[1]);
  frequency = atof(argv[2]);
  xstart = atof(argv[3]);
  xstop = atof(argv[4]);
  xinc = atof(argv[5]);
  fitsine(n_points,a,data);
  for (i = 0; i < 7; i++) {
    fprintf(stderr,"a[%d]=%.8g ",i,a[i]);
  }
  putc('\n',stderr);
  xstop = xstop + (xinc * 0.5);
  x = xstart;
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
    f = 0.0;
    for (i = 0; i < 7; i++) {
      f += a[i] * phi(i,x);
    }
    printf("%.8g %.8g\n",x,f);
    x = x + xinc;
  }
  exit(0);
}
