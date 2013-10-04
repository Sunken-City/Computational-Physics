#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

int newton_raphson(double (*func)(double x),double (*deriv)(double x),double x,int nmax,double tol,double min) {
  double fx,fp,d;
  int n;

  fx = (*func)(x);
  printf("0 %.16g %.16g\n",x,fx);
  n = 1;
  while (n <= nmax) {
    fp = (*deriv)(x);
    if (fabs(fp) < min) {
      fprintf(stderr,"newton_raphson: Derivative too small\n");
      return(2);
    }
    d =  fx / fp;
    x = x - d;
    fx = (*func)(x);
    printf("%d %.16g %.16g\n",n,x,fx);
    if (fabs(d) < tol) break;
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"newton_raphson: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  return(0);
}

int regula_falsi(double (*func)(double x),double a,double b,int nmax,double tol) {
  double fa,fb,c,fc,d;
  int n;

  fa = (*func)(a);
  fb = (*func)(b);
  if (fa * fb > 0.0) {
    fprintf(stderr,"regula_falsi: Root not bracketed by initial points\n");
    return(2);
  }
  printf("0 %.16g %.16g\n",b,fb);
  printf("1 %.16g %.16g\n",a,fa);
  n = 2;
  while (n <= nmax) {
    d = ((b - a) / (fb - fa)) * fa;
    if (fabs(d) < tol) break;
    c = a - d;
    fc = (*func)(c);
    printf("%d %.16g %.16g\n",n,c,fc);
    if (fa * fc < 0.0) {
      b = c;
      fb = fc;
    }
    else {
      a = c;
      fa = fc;
    }
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"regula_falsi: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  return(0);
}

int bisection(double (*func)(double x),double a,double b,int nmax,double tol) {
  double fa,fb,c,fc,d;
  int n;

  fa = (*func)(a);
  fb = (*func)(b);
  if (fa * fb > 0.0) {
    fprintf(stderr,"bisection: Root not bracketed by initial points\n");
    return(2);
  }
  printf("0 %.16g %.16g\n",b,fb);
  printf("1 %.16g %.16g\n",a,fa);
  n = 2;
  while (n <= nmax) {
    d = 0.5 * (b - a);
    if (fabs(d) < tol) break;
    c = a + d;
    fc = (*func)(c);
    printf("%d %.16g %.16g\n",n,c,fc);
    if (fa * fc < 0.0) {
      b = c;
      fb = fc;
    }
    else {
      a = c;
      fa = fc;
    }
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"bisection: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  return(0);
}

int secant(double (*func)(double x),double a,double b,int nmax,double tol) 
{
  double fa,fb,d,swap;
  int n;

  fa = (*func)(a);
  fb = (*func)(b);
  if (fabs(fa) > fabs(fb)) 
  {
    swap = a;
    a = b;
    b = swap;
    swap = fa;
    fa = fb;
    fb = swap;
  }
  printf("0 %.16g %.16g\n",b,fb);
  printf("1 %.16g %.16g\n",a,fa);
  n = 2;
  while (n <= nmax) 
  {
    if (fabs(fa) > fabs(fb)) 
    {
      swap = a;
      a = b;
      b = swap;
      swap = fa;
      fa = fb;
      fb = swap;
    }
    d = ((b - a) / (fb - fa)) * fa;
    b = a;
    fb = fa;
    
    if (fabs(d) < tol) break;
    a = a - d;
    fa = (*func)(a);
    printf("%d %.16g %.16g\n",n,a,fa);
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"secant: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  return(0);
}
