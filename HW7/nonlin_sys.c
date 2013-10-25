#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sys_roots.h"

double init[2];
double tol[2] = {1.0e-6,1.0e-6};

/*
C function to calculate the system of functions to be solved.
The v array argument is the current system argument vector,
where v[0] = 'x' and v[1] = 'y'. The s array argument is where
this function is to write the two system function values,
s[0] = 'f' and s[1] = 'g'.
*/

void func(int n,double *v,double *s) {
  s[0] = ;
  s[1] = ;
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
*/

void jacobian(int n,double *v,double **a) {
  a[0][0] = ;
  a[0][1] = ;
  a[1][0] = ;
  a[1][1] = ;
  return;
}

int main(int argc,char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,"%s <init0> <init1>\n",argv[0]);
    exit(1);
  }
  init[0] = atof(argv[1]);
  init[1] = atof(argv[2]);
  sys_newton_raphson(2,func,jacobian,init,tol,100);
  exit(0);
}
