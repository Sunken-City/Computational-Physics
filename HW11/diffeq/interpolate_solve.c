#include <stdio.h>
#include <stdlib.h>
#include "data_file.h"
#include "interpolate.h"

struct point2d *data;

int main(int argc,char *argv[]) {
  double value;
  int i_start,n_points;

  if (argc != 3) {
    fprintf(stderr,"%s <input file> <value>\n",argv[0]);
    exit(1);
  }
  n_points = read_data_file(argv[1],&data);
  fprintf(stderr,"Read %d points from data file %s\n",n_points,argv[1]);
  value = atof(argv[2]);
  i_start = 0;
  while (i_start < n_points - 3) {
    if ((data[i_start + 1].y - value) * (data[i_start + 2].y - value) < 0.0) {
#ifdef NEWTON
      find_newton_inverse_coeffs(4,data + i_start);
#endif
#ifdef LAGRANGE
      printf("%.8g %.8g\n",lagrange_inverse(4,data + i_start,value),value);
#endif
#ifdef NEWTON
      printf("%.8g %.8g\n",newton_inverse(4,data + i_start,value),value);
#endif
    }
    i_start++;
  }
  exit(0);
}
