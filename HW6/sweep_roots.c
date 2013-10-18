#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sweep_roots.h"

int newton_raphson(double (*func)(double x),double (*deriv)(double x),double x,int nmax,double tol,double min) {
  double fx,fp,d;
  int n;

  fx = (*func)(x);
  n = 1;
  while (n <= nmax) {
    fp = (*deriv)(x);
    if (fabs(fp) < min) {
      fprintf(stderr,"newton_raphson: Derivative too small\n");
      return(2);
    }
    d =  fx / fp;
    x = x - d;
    if (fabs(d) < tol) break;
    fx = (*func)(x);
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"newton_raphson: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  printf("%.12g\n",x);
  return(0);
}
int sweep_newton_raphson(double (*func)(double x),double (*deriv)(double x),double xstart,double xstop,double xinc,int nmax,double tol,double min) {
  double a,b,fa,fb;
  int retval;

  xstop = xstop + (xinc * 0.5);
  a = xstart;
  fa = (*func)(a);
  b = a + xinc;
  while (((xinc > 0.0) && (b < xstop)) || ((xinc < 0.0) && (b > xstop))) {
    fb = (*func)(b);
    if ((fa * fb) < 0.0) {   /*root bracketed, converge with newton_raphson*/
      if (fabs(fa) < fabs(fb)) {
        retval = newton_raphson(func,deriv,a,nmax,tol,min);
      }
      else {
        retval = newton_raphson(func,deriv,b,nmax,tol,min);
      }
      if (retval > 0) return(retval);
    }
    a = b;
    fa = fb;
    b = b + xinc;
  }
  return(0);
}

int secant(double (*func)(double x),double a,double b,int nmax,double tol) {
  double fa,fb,d,swap;
  int n;

  fa = (*func)(a);
  fb = (*func)(b);
  n = 2;
  while (n <= nmax) {
    if (fabs(fa) > fabs(fb)) {  /*  arrange so |f(b)| > |f(a)|  */
      swap = a;
      a = b;
      b = swap;
      swap = fa;
      fa = fb;
      fb = swap;
    }
    d = ((b - a) / (fb - fa)) * fa;
    if (fabs(d) < tol) break;
    b = a;
    fb = fa;
    a = a - d;
    fa = (*func)(a);
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"secant: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  printf("%.12g\n",a);
  return(0);
}
int sweep_secant(double (*func)(double x),double xstart,double xstop,double xinc,int nmax,double tol) {
  double a,b,fa,fb;
  int retval;

  xstop = xstop + (xinc * 0.5);
  a = xstart;
  fa = (*func)(a);
  b = a + xinc;
  while (((xinc > 0.0) && (b < xstop)) || ((xinc < 0.0) && (b > xstop))) {
    fb = (*func)(b);
    if ((fa * fb) < 0.0) {   /*root bracketed, converge with secant*/
      retval = secant(func,a,b,nmax,tol);
      if (retval > 0) return(retval);
    }
    a = b;
    fa = fb;
    b = b + xinc;
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
  n = 2;
  while (n <= nmax) {
    c = a - (fa * (b - a) / (fb - fa));
    fc = (*func)(c);
    if (fa * fc < 0.0) {
      d = c - b;
      b = c;
      fb = fc;
    }
    else {
      d = c - a;
      a = c;
      fa = fc;
    }
    if (fabs(d) < tol) break;
    n++;
  }
  if (n > nmax) {
    fprintf(stderr,"regula_falsi: Iteration limit of %d reached\n",nmax);
    return(1);
  }
  printf("%.12g\n",c);
  return(0);
}
int sweep_regula_falsi(double (*func)(double x),double xstart,double xstop,double xinc,int nmax,double tol) {
  double a,b,fa,fb;
  int retval;

  xstop = xstop + (xinc * 0.5);
  a = xstart;
  fa = (*func)(a);
  b = a + xinc;
  while (((xinc > 0.0) && (b < xstop)) || ((xinc < 0.0) && (b > xstop))) {
    fb = (*func)(b);
    if ((fa * fb) < 0.0) {   /*root bracketed, converge with regula_falsi*/
      retval = regula_falsi(func,a,b,nmax,tol);
      if (retval > 0) return(retval);
    }
    a = b;
    fa = fb;
    b = b + xinc;
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
  n = 2;
  while (n <= nmax) {
    d = 0.5 * (b - a);
    if (fabs(d) < tol) break;
    c = a + d;
    fc = (*func)(c);
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
  printf("%.12g\n",a);
  return(0);
}
int sweep_bisection(double (*func)(double x),double xstart,double xstop,double xinc,int nmax,double tol) {
  double a,b,fa,fb;
  int retval;

  xstop = xstop + (xinc * 0.5);
  a = xstart;
  fa = (*func)(a);
  b = a + xinc;
  while (((xinc > 0.0) && (b < xstop)) || ((xinc < 0.0) && (b > xstop))) {
    fb = (*func)(b);
    if ((fa * fb) < 0.0) {   /*root bracketed, converge with bisection*/
      retval = bisection(func,a,b,nmax,tol);
      if (retval > 0) return(retval);
    }
    a = b;
    fa = fb;
    b = b + xinc;
  }
  return(0);
}
