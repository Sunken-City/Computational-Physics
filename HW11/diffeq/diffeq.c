#include <stdio.h>
#include <stdlib.h>
#include "diffeq.h"

int rk2(int order,void (*func)(int n,double x,double y[],double yp[]),double xstart,double xstop,double xinc,double y[]) {
  double x,xhalfinc,xnext,*ymid;
  double *k1,*k2;   /*Runge-Kutta slope values*/
  int j;

  ymid = (double *) malloc(order * sizeof(double));
  k1 = (double *) malloc(order * sizeof(double));
  k2 = (double *) malloc(order * sizeof(double));
  xstop = xstop + (xinc * 0.5);
  xhalfinc = xinc * 0.5;
  x = xstart;
  while (1) {
    printf("%.8g ",x);   /*output independent variables*/
    for (j = 0; j < order; j++) printf("%.8g ",y[j]);   /*output state value*/
    putchar('\n');
    xnext = x + xinc;
    if (((xinc > 0.0) && (xnext > xstop)) || ((xinc < 0.0) && (xnext < xstop))) break;
    (*func)(order,x,y,k1);   /*calculate RK2 (Improved polygon method) algorithm step*/
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xhalfinc * k1[j]);
    (*func)(order,x + xhalfinc,ymid,k2);
    for (j = 0; j < order; j++) y[j] += xinc * k2[j];
    x = xnext;
  }
  free(ymid);
  free(k1);
  free(k2);
  return(0);
}

int rk4(int order,void (*func)(int n,double x,double y[],double yp[]),double xstart,double xstop,double xinc,double y[]) {
  double x,xhalfinc,xnext,*ymid;
  double *k1,*k2,*k3,*k4;   /*Runge-Kutta slope values*/
  int j;

  ymid = (double *) malloc(order * sizeof(double));
  k1 = (double *) malloc(order * sizeof(double));
  k2 = (double *) malloc(order * sizeof(double));
  k3 = (double *) malloc(order * sizeof(double));
  k4 = (double *) malloc(order * sizeof(double));
  xstop = xstop + (xinc * 0.5);
  xhalfinc = xinc * 0.5;
  x = xstart;
  while (1) {
    printf("%.8g ",x);   /*output independent variables*/
    for (j = 0; j < order; j++) printf("%.8g ",y[j]);   /*output state value*/
    putchar('\n');
    xnext = x + xinc;
    if (((xinc > 0.0) && (xnext > xstop)) || ((xinc < 0.0) && (xnext < xstop))) break;
    (*func)(order,x,y,k1);   /*calculate RK4 algorithm step*/
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xhalfinc * k1[j]);
    (*func)(order,x + xhalfinc,ymid,k2);
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xhalfinc * k2[j]);
    (*func)(order,x + xhalfinc,ymid,k3);
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xinc * k3[j]);
    (*func)(order,x + xinc,ymid,k4);
    for (j = 0; j < order; j++) y[j] += xinc * (k1[j] + (2.0 * k2[j]) + (2.0 * k3[j]) + k4[j]) / 6.0;
    x = xnext;
  }
  free(ymid);
  free(k1);
  free(k2);
  free(k3);
  free(k4);
  return(0);
}

int rk4_quiet(int order,void (*func)(int n,double x,double y[],double yp[]),double xstart,double xstop,double xinc,double y[]) {
  double x,xhalfinc,xnext,*ymid;
  double *k1,*k2,*k3,*k4;   /*Runge-Kutta slope values*/
  int j;

  ymid = (double *) malloc(order * sizeof(double));
  k1 = (double *) malloc(order * sizeof(double));
  k2 = (double *) malloc(order * sizeof(double));
  k3 = (double *) malloc(order * sizeof(double));
  k4 = (double *) malloc(order * sizeof(double));
  xstop = xstop + (xinc * 0.5);
  xhalfinc = xinc * 0.5;
  x = xstart;
  while (1) {
    xnext = x + xinc;
    if (((xinc > 0.0) && (xnext > xstop)) || ((xinc < 0.0) && (xnext < xstop))) break;
    (*func)(order,x,y,k1);   /*calculate RK4 algorithm step*/
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xhalfinc * k1[j]);
    (*func)(order,x + xhalfinc,ymid,k2);
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xhalfinc * k2[j]);
    (*func)(order,x + xhalfinc,ymid,k3);
    for (j = 0; j < order; j++) ymid[j] = y[j] + (xinc * k3[j]);
    (*func)(order,x + xinc,ymid,k4);
    for (j = 0; j < order; j++) y[j] += xinc * (k1[j] + (2.0 * k2[j]) + (2.0 * k3[j]) + k4[j]) / 6.0;
    x = xnext;
  }
  free(ymid);
  free(k1);
  free(k2);
  free(k3);
  free(k4);
  return(0);
}
