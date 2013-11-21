#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"
#include "constants.h"

int main(int argc,char *argv[]) {
  double th, xc, yc, dist, prob;
  int n_trials,i_trial,n_hits;
  double R = 1.0;
  double r = 0.1;
  double th0 = PI / 9;
  double w = TWO_PI;

  
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
    th = th0 * sin(w * random_normal_gen(0.0, 0.07));
    xc = R * sin(th);
    yc = -R * cos(th);
    //Distance from the center of the target relative to the target.
    dist = sqrt((xc * xc) + ((yc + R) * (yc + R)));
    //printf("%f %f\n", xc, yc);
    if (dist <= r)
    {
      n_hits++;
    }
    i_trial++;
  }
  prob = ((double) n_hits) / ((double) n_trials);
  printf("%d %d %.8f\n",n_hits, n_trials, prob);
  exit(0);
}
