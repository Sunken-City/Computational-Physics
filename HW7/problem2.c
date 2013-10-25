#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sys_roots.h"

double init[6];
double tol[6] = {1.0e-6,1.0e-6,1.0e-6,1.0e-6,1.0e-6,1.0e-6};
double inc[6] = {1.0e-3,1.0e-3,1.0e-3,1.0e-3,1.0e-3,1.0e-3};
double W1 = 100.0;
double W2 = 175.0;
double L = 30.0;
double L1 = 12.0;
double L2 = 8.0;
double L3 = 15.0;

/*
C function to calculate the system of functions to be solved.
The v array argument is the current system argument vector,
where v[0] = 'x' and v[1] = 'y'. The s array argument is where
this function is to write the two system function values,
s[0] = 'f' and s[1] = 'g'.
*/

void func(int n,double *v,double *s) {
  s[0] = v[1]*cos(v[4]) - v[0]*cos(v[3]);
  s[1] = v[0]*sin(v[3]) - v[1]*sin(v[4]) - W1;
  s[2] = v[2]*cos(v[5]) - v[1]*cos(v[4]);
  s[3] = v[2]*sin(v[5]) + v[1]*sin(v[4]) - W2;
  s[4] = L1*cos(v[3]) + L2*cos(v[4]) + L3*cos(v[5]) - L;
  s[5] = -L1*sin(v[3]) - L2*sin(v[4]) + L3*sin(v[5]);
  return;
}

/*
C function to calculate the Jacobian of the system of functions to be solved.
The v array argument is the current system argument vector,
where v[0] = 'x' and v[1] = 'y'. The a matrix argument is where
this function is to write the four partial derivitive values,
a[0][0] = partial f / partial x
a[0][1] = partial f / partial y
a[1][0] = partial g / partial x
a[1][1] = partial g / partial y
The partial derivatives are found by numerical differentiation.
*/

void jacobian_numerical(int n,double *x,double **a) {
 double *f1,*f2,*xtest;
 int i,j;
 f1 = (double *) malloc(n * sizeof(double));
 f2 = (double *) malloc(n * sizeof(double));
 xtest = (double *) malloc(n * sizeof(double));
 for (j = 0; j < n; j++) {
    /* initialize xtest vector */
    for (i = 0; i < n; i++) {
    xtest[i] = x[i];
    }
    /* find partial derivative with respect to x[j] */
    xtest[j] = x[j] - inc[j];
    func(n,xtest,f1);
    xtest[j] = x[j] + inc[j];
    func(n,xtest,f2);
    for (i = 0; i < n; i++) {
    a[i][j] = (f2[i] - f1[i]) / (2.0 * inc[j]);
    }
 }
 free(f1);
 free(f2);
 free(xtest);
 return;
} 

int main(int argc,char *argv[]) {
  if (argc != 7) {
    fprintf(stderr,"%s <T1> <T2> <T3> <Th1> <Th2> <Th3>\n",argv[0]);
    exit(1);
  }
  init[0] = atof(argv[1]);
  init[1] = atof(argv[2]);
  sys_newton_raphson(6,func,jacobian_numerical,init,tol,100);
  exit(0);
}
