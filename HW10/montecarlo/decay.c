#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"

int main(int argc,char *argv[]) 
{
  int time, left, decay, i; 
  double test, lambda;
  
  if (argc != 4) 
  {
    fprintf(stderr,"%s <initial population> <lambda> <seed>\n",argv[0]);
    exit(1);
  }
    
  time = 0;
  left = atoi(argv[1]);
  lambda = atof(argv[2]);
  random_seed(atoi(argv[3]));
  
  while (left > 0)
  {
    decay = 0;
    for (i = 1; i <= left; i++)
    {
      test = random_gen();
      if (test <= lambda)
      {
	decay = decay + 1;
      }
    }
    
    if (decay != 0)
    {
      printf("%d %f\n", time, log(decay));
    }
    left = left - decay;
    time = time + 1;
  }

  exit(0);
}
