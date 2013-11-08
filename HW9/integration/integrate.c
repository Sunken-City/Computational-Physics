#include <stdio.h>
#include <stdlib.h>
#include "integrate.h"
#include "data_file.h"

int trapezoidal(double (*func)(double x),double xstart,double xstop,double xinc) {
  double x,integral;

  x = xstart;
  integral = 0.5 * xinc * (*func)(x);
  x = x + xinc;
  xstop = xstop - (xinc * 0.5);
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
    integral += xinc * (*func)(x);
    x = x + xinc;
  }
  integral += 0.5 * xinc * (*func)(x);
  printf("%.12g\n",integral);
  return(0);
}

int simpson(double (*func)(double x),double xstart,double xstop,double xinc) {
  double x,integral;
  int state;

  x = xstart;
  integral = xinc * (*func)(x) / 3.0;
  x = x + xinc;
  xstop = xstop - (xinc * 0.5);
  state = 0;
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
    if (state == 0) {
      integral += 4.0 * xinc * (*func)(x) / 3.0;
      state = 1;
    }
    else {
      integral += 2.0 * xinc * (*func)(x) / 3.0;
      state = 0;
    }
    x = x + xinc;
  }
  if (state != 1) {
    fprintf(stderr,"Warning: Odd number of integration segments\n");
  }
  integral += xinc * (*func)(x) / 3.0;
  printf("%.12g\n",integral);
  return(0);
}

int trapezoidal_data(int n,struct point2d *sample) {
  double integral;
  int i;

  integral = 0.0;
  i = 1;
  while (i < n) {
    integral += 0.5 * (sample[i].y + sample[i-1].y) * (sample[i].x - sample[i-1].x);
    i++;
  }
  printf("%.12g\n",integral);
  return(0);
}
