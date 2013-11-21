#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"
#include "constants.h"

struct charge 
{
 double x,y,z,q; 
};

struct vector
{
  double x,y,z;
};

int main(int argc,char *argv[]) {
  double x,y,z,Rsamp;
  double r1_1, r1_2, r1_3, r2_1, r2_2, r2_3;
  int n_trials,i_trial;
  
  double charge = 0.0;
  
  if (argc != 3) {
    fprintf(stderr,"%s <N trials> <seed>\n",argv[0]);
    exit(1);
  }
  n_trials = atoi(argv[1]);
  random_seed(atoi(argv[2]));
  i_trial = 0;
  
  struct charge p1, p2, p3;
  
  p1.x = 0.25;
  p1.y = 0.25;
  p1.z = 0.25;
  p1.q = 1.0;
  
  p2.x = -0.5;
  p2.y = 0.5;
  p2.z = -0.25;
  p2.q = 2.0;
  
  p3.x = 0.5;
  p3.y = -0.25;
  p3.z = 0.0;
  p3.q = 3.0;
  
  struct vector e1, e2, e3, ef;
 
  double surface = 1.0 / (double)n_trials;
  
  while (i_trial < n_trials) 
  {
    x = 2.0*(random_gen() - 0.5);
    y = 2.0*(random_gen() - 0.5);
    z = 2.0*(random_gen() - 0.5);
    Rsamp = sqrt((x*x) + (y*y) + (z*z));
    if (Rsamp > 1)
    {
     continue;
    }
    x = x / Rsamp;
    y = y / Rsamp;
    z = z / Rsamp;
    
    r2_1 = ((x - p1.x) * (x - p1.x)) + ((y - p1.y) * (y - p1.y)) + ((z - p1.z) * (z - p1.z));
    r2_2 = ((x - p2.x) * (x - p2.x)) + ((y - p2.y) * (y - p2.y)) + ((z - p2.z) * (z - p2.z));
    r2_3 = ((x - p3.x) * (x - p3.x)) + ((y - p3.y) * (y - p3.y)) + ((z - p3.z) * (z - p3.z));
    
    r1_1 = sqrt(r2_1);
    r1_2 = sqrt(r2_2);
    r1_3 = sqrt(r2_3);
    
    double coefficient = ((p1.q / (r2_1 * r1_1)));
    e1.x = coefficient * (x - p1.x);
    e1.y = coefficient * (y - p1.y);
    e1.z = coefficient * (z - p1.z);
    
    coefficient = ((p2.q / (r2_2 * r1_2)));
    e2.x = coefficient * (x - p2.x);
    e2.y = coefficient * (y - p2.y);
    e2.z = coefficient * (z - p2.z);
    
    coefficient = ((p3.q / (r2_3 * r1_3)));
    e3.x = coefficient * (x - p3.x);
    e3.y = coefficient * (y - p3.y);
    e3.z = coefficient * (z - p3.z);
    
    ef.x = e1.x + e2.x + e3.x;
    ef.y = e1.y + e2.y + e3.y;
    ef.z = e1.z + e2.z + e3.z;
    
    charge += ((ef.x * x) + (ef.y * y) + (ef.z * z));
    
    i_trial++;
  }
  charge = charge * surface;
  printf("%.8f\n", charge);
  exit(0);
}
