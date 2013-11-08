#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_file.h"
#include "interpolate.h"
#include "sweep.h"
#include "constants.h"

struct point2d *data;
double theta_i = 30.0;
int n_points;

double prism(double lambda) 
{
  double theta1, theta2, theta3, theta4, theta_o, n;
  theta1 = theta_i + 30.0;
  n = newton(n_points,data,lambda);
  theta2 = asin((1.0/n)*sin(theta1 * DEGTORAD)) * RADTODEG;
  theta3 = 60.0 - theta2;
  theta4 = asin(n*sin(theta3 * DEGTORAD)) * RADTODEG;
  theta_o = theta4 - 30.0;
  
  return(theta_o);
}

int main(int argc,char *argv[]) 
{
  if (argc != 5) 
  {
    fprintf(stderr,"%s <input file> <xstart> <xstop> <xinc>\n",argv[0]);
    exit(1);
  }
  n_points = read_data_file(argv[1],&data);
  double lstart = atof(argv[2]);
  double lstop = atof(argv[3]);
  double lstep = atof(argv[4]);
  find_newton_coeffs(n_points,data);
  sweep(prism,lstart,lstop,lstep);
  exit(0);
}