#include <stdio.h>
#include <stdlib.h>
#include "sweep.h"

int sweep(double (*func)(double x),double xstart,double xstop,double xinc) {
  double x;

  xstop = xstop + (xinc * 0.5);
  x = xstart;
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
    printf("%.8g %.8g\n",x,(*func)(x));
    x = x + xinc;
  }
  return(0);
}

int sweep2(double (*func)(double x,double y),double xstart,double xstop,double xinc,double ystart,double ystop,double yinc) {
  double x,y;

  xstop = xstop + (xinc * 0.5);
  ystop = ystop + (yinc * 0.5);
  x = xstart;
  while (((xinc > 0.0) && (x < xstop)) || ((xinc < 0.0) && (x > xstop))) {
    y = ystart;
    while (((yinc > 0.0) && (y < ystop)) || ((yinc < 0.0) && (y > ystop))) {
      printf("%.8g %.8g %.8g\n",x,y,(*func)(x,y));
      y = y + yinc;
    }
    putchar('\n');
    x = x + xinc;
  }
  return(0);
}
