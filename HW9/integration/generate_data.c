#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[]) {
  double x,y,r;

  srand(1);
  x = 0.0;
  while (x < 10.0) {

/*
The following statement will generate a floating point random
number between -0.5 and +0.5:
*/
    r = (((double) rand()) / ((double) RAND_MAX)) - 0.5;

    y = 1.3*x + 0.13 + r;
    printf("%lf %lf\n", x, y);  /* Complete this statement*/

    x += 0.1;
  }
  exit(0);
}
