#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"

int main(int argc,char *argv[]) {
  double x,y,dx,dy,radius;
  int n_steps,i_step;
  FILE *position,*distance;

  if (argc != 3) {
    fprintf(stderr,"%s <N steps> <seed>\n",argv[0]);
    exit(1);
  }
  position = fopen("walk_position.dat","w");
  distance = fopen("walk_distance.dat","w");
  n_steps = atoi(argv[1]);
  random_seed(atoi(argv[2]));
  fprintf(position,"0 0\n");
  fprintf(distance,"0 0\n");
  i_step = 0;
  x = 0.0;
  y = 0.0;
  while (i_step < n_steps) {

/* Complete the statements below */
    dx =  2.0*(random_gen() - 0.5);
    dy =  2.0*(random_gen() - 0.5);
    radius = sqrt((dx * dx) + (dy * dy));
    if (radius > 1.0) continue;
    dx = dx / radius;
    dy = dy / radius;

    x += dx;
    y += dy;
    fprintf(position,"%.8f %.8f\n",x,y);
    fprintf(distance,"%d %.8f\n",i_step + 1,sqrt((x*x) + (y*y)));
    i_step++;
  }
  fclose(position);
  fclose(distance);
  exit(0);
}
