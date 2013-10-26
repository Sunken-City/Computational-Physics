#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sys_roots.h"
#include "constants.h"

double init[4];
double tol[4] = {1e-12,1e-12,1e-12,1e-12};
double inc[4] = {1e-6,1e-6,1e-6,1e-3};
double m = 0.5110e6;
double hbar = 4.332404e-31;
double x = 1e-9 / 2.0;
double k1, k2, k3;
/*
C function to calculate the system of functions to be solved.
The v array argument is the current system argument vector,
where v[0] = 'x' and v[1] = 'y'. The s array argument is where
this function is to write the two system function values,
s[0] = 'f' and s[1] = 'g'.
*/

void func(int n,double *v,double *s) 
{
  k1 = sqrt((-2.0 * m * v[3]) / hbar);
  k2 = sqrt((2.0 * m * (v[3] + 10.0)) / hbar);
  k3 = sqrt((2.0 * m * (-v[3] - 5.0)) / hbar);
  s[0] = exp(-k1 * x) - (v[1]*cos(k2 * x)) + (v[2]*sin(k2 * x));
  s[1] = (k1 * exp(-k1 * x)) - (k2*v[1]*sin(k2 * x)) - (k2*v[2]*cos(k2 * x));
  s[2] = v[0] * exp(-k3 * x) - (v[1]*cos(k2 * x)) - (v[2]*sin(k2 * x));
  s[3] = (k3 * v[0] * exp(-k3 * x)) - (k2*v[1]*sin(k2 * x)) - (k2*v[2]*cos(k2 * x));
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
  if (argc != 5) {
    fprintf(stderr,"%s <B> <C> <D> <E>\n",argv[0]);
    exit(1);
  }
  init[0] = atof(argv[1]);
  init[1] = atof(argv[2]);
  init[2] = atof(argv[3]);
  init[3] = atof(argv[4]);
  sys_newton_raphson(4,func,jacobian_numerical,init,tol,100);
  exit(0);
}
