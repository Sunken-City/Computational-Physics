#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"
#include "constants.h"

int main(int argc,char *argv[]) {
  int i, j, m;
  double x, per;
  
  int n = 5000;
  int iprt = 1000;
  
  m = 0;
  
  if (argc != 2) 
  {
    fprintf(stderr,"%s <seed>\n",argv[0]);
    exit(1);
  }
  
  fprintf(stderr,"i:   per:\n");
  
  random_seed(atoi(argv[1]));
  
  for (i = 1; i <= n; i++)
  {
    x = 1.0;
    
    for (j = 1; j <= 7; j++)
    {
	x = x + cos(PI * random_gen());
	if (x <= 0.0)
	{
	  break; 
	}
	if (x >= 5.0)
	{
	  m = m + 1;
	  break;
	}
    }
    
    if (i % iprt == 0)
    {
      per = (100.0 * ((double)m / (double)i));
      printf("%d %lf\n", i, per);
    }
    
  }
  exit(0);
}
