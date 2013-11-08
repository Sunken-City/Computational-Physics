#include <stdio.h>
#include <stdlib.h>
#include "random.h"

static unsigned long int random_state = 1;

void random_seed(unsigned long int seed) {
  random_state = seed;
  return;
}

double random_gen(void) {
  unsigned long long int temp_state;

  temp_state = random_state;
  temp_state = (16807ULL * temp_state) % 2147483647ULL;
  random_state = temp_state;
  return(((double) random_state) * 4.6566128752459e-10);
}

double random_normal_gen(double mu,double sigma) {
  int i;
  double sum;
  
  sum = random_gen();
  for (i = 1; i < 12; i++) sum += random_gen();
  sum -= 6.0;
  return (mu + (sigma * sum));
}
