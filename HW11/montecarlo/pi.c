#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"

int main(int argc,char *argv[]) {
  double x,y,pi;
  int n_trials,i_trial,n_hits;

  if (argc != 3) {
    fprintf(stderr,"%s <N trials> <seed>\n",argv[0]);
    exit(1);
  }
  n_trials = atoi(argv[1]);
  random_seed(atoi(argv[2]));
  i_trial = 0;
  n_hits = 0;
  while (i_trial < n_trials) {
/*
   Add statements here to generate two random coordinates
   within the square in the double precision variables x and y,
   and increment the integer variable n_hits if x and y
   represent a point within the unit circle
   Hint: save computation time by NOT calling the sqrt() function!
*/
    x = 2.0*(random_gen() - 0.5);
    y = 2.0*(random_gen() - 0.5);
    if (x*x + y*y <= 1) n_hits++;
    i_trial++;
  }
  pi = 4.0 * ((double) n_hits) / ((double) n_trials);
  printf("%.8f\n",pi);
  exit(0);
}
