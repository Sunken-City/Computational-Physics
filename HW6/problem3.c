#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lineq.h"
#include "sweep.h"
#include "constants.h"

double x10,x20,x30;
double **a,*rhs,*x;
double w = TWO_PI;

double mass1(double t) 
{
 double y;
 y = (-x[0] * cos(sqrt(2.0) * w * t)) + (x[1] * cos(sqrt(2.0 - sqrt(2.0)) * w * t)) + (x[2] * cos(sqrt(2.0 + sqrt(2.0)) * w * t));
 return(y);
}

double mass2(double t) 
{
 double y;
 y = (sqrt(2.0) * x[1] * cos(sqrt(2.0 - sqrt(2.0)) * w * t)) - (sqrt(2.0) * x[2] * cos(sqrt(2.0 + sqrt(2.0)) * w * t));
 return(y);
}

double mass3(double t) 
{
 double y;
 y = (x[0] * cos(sqrt(2.0) * w * t)) + (x[1] * cos(sqrt(2.0 - sqrt(2.0)) * w * t)) + (x[2] * cos(sqrt(2.0 + sqrt(2.0)) * w * t));
 return(y);
}

int main(int argc,char *argv[]) 
{
  if (argc != 4) 
  {
    fprintf(stderr,"%s <d1> <d2> <d3>\n",argv[0]);
    exit(1);
  }
  x10 = atof(argv[1]);
  x20 = atof(argv[2]);
  x30 = atof(argv[3]);
  
  int n = 3;
  a = alloc_matrix(n,n);
  a[0][0] = -1.0;
  a[0][1] = 1.0;
  a[0][2] = 1.0;
  a[1][0] = 0.0;
  a[1][1] = sqrt(2.0);
  a[1][2] = -1.0 * sqrt(2.0);
  a[2][0] = 1.0;
  a[2][1] = 1.0;
  a[2][2] = 1.0;
 
  rhs = (double *) malloc(n * sizeof(double));
  rhs[0] = x10;
  rhs[1] = x20;
  rhs[2] = x30;
  
  x = (double *) malloc(n * sizeof(double));

 if (gauss(n,a,rhs,x,1.0e-18)) 
 {
  fprintf(stderr,"Singular coefficient matrix\n");
  free_matrix(n,a);
  free(rhs);
  free(x);
  exit(1);
 }
 
 fprintf(stderr,"Mode 1:%.8g Mode 2:%.8g Mode 3:%.8g\n",x[0],x[1],x[2]);
 
 sweep(mass1,0.0,10.0,0.01);
 printf("\n\n");
 sweep(mass2,0.0,10.0,0.01);
 printf("\n\n");
 sweep(mass3,0.0,10.0,0.01);

 exit(0);
}
