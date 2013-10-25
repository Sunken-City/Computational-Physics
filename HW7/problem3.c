#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sys_roots.h"

double init[2];
double tol[2] = {1.0e-6,1.0e-6};
double inc[2] = {1.0e-3,1.0e-3};

/*
C function to calculate the system of functions to be solved.
The v array argument is the current system argument vector,
where v[0] = 'x' and v[1] = 'y'. The s array argument is where
this function is to write the two system function values,
s[0] = 'f' and s[1] = 'g'.
*/

void func(int n,double *v,double *s) {
  s[0] = (4.0 * tanh(v[0])) - v[1];
  s[1] = pow((1.0 + exp(cos(v[0]))),1.5) - v[1];
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

void jacobian_numerical(int n,double *v,double **a) {
  double f1[2],f2[2],vtest[2];

  vtest[0] = v[0] - inc[0];
  vtest[1] = v[1];
  func(n,vtest,f1);
  vtest[0] = v[0] + inc[0];
  func(n,vtest,f2);
  a[0][0] = (f2[0] - f1[0]) / (2.0 * inc[0]);
  a[1][0] = (f2[1] - f1[1]) / (2.0 * inc[0]);
  vtest[0] = v[0];
  vtest[1] = v[1] - inc[1];
  func(n,vtest,f1);
  vtest[1] = v[1] + inc[1];
  func(n,vtest,f2);
  a[0][1] = (f2[0] - f1[0]) / (2.0 * inc[1]);
  a[1][1] = (f2[1] - f1[1]) / (2.0 * inc[1]);
  return;
}

int main(int argc,char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,"%s <init0> <init1>\n",argv[0]);
    exit(1);
  }
  init[0] = atof(argv[1]);
  init[1] = atof(argv[2]);
  sys_newton_raphson(2,func,jacobian_numerical,init,tol,100);
  exit(0);
}
