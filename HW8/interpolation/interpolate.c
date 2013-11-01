#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_file.h"
#include "interpolate.h"

/* pointer to divided difference table, div_diff[i][j] = row i, column j*/
double **div_diff = NULL;

double lagrange(int n,struct point2d *sample,double x) {
  double sum,product;
  int i,j;

  sum = 0.0;
  i = 0;
  while (i < n) {
    product = sample[i].y;
    j = 0;
    while (j < n) {
      if (j != i) {
        product *= (x - sample[j].x) / (sample[i].x - sample[j].x);
      }
      j++;
    }
    sum += product;
    i++;
  }
  return(sum);
}

/*
   This function allocates memory for a two dimensional triangular matrix
   of arbitrary size by allocating an array for each of the rows in the
   matrix, and also for an array of pointers to each row. n is the
   number of rows, and there are n columns in the top row for i = 0,
   down to 1 column in the bottom row for i = n-1. The matrix
   elements may be extracted with two subscripts for row and column.
   For example, if the pointer returned by this function is stored in
   the variable double **tri, then tri[i][j] gives the element
   at row index i and column index j.
*/
double **alloc_tri(int n) {
  int i;
  double **tri;

  tri = (double **) malloc(n * sizeof(double *));
  if (tri == NULL) return(NULL);
  i = 0;
  while (i < n) {
    tri[i] = (double *) malloc((n-i) * sizeof(double));
    i++;
  }
  return(tri);
}

/*
   This function frees memory allocated by alloc_tri().
*/
void free_tri(int n,double **tri) {
  int i;
  i = 0;
  while (i < n) {
    if (tri[i]) free(tri[i]);
    i++;
  }
  free(tri);
  return;
}

/*
   This function displays the triangular matrix allocated by alloc_tri()
   to the stderr stream.
*/
void disp_tri(int n,double **tri) {
  int i,j;
  i = 0;
  while (i < n) {
    j = 0;
    while (j < (n-i)) {
      fprintf(stderr,"%.8g ",tri[i][j]);
      j++;
    }
    putc('\n',stderr);
    i++;
  }
  return;
}

int find_newton_coeffs(int n,struct point2d *sample) {
  int i,j;

  if (n < 2) return(-1);
  if (div_diff != NULL) free_tri(n,div_diff);
  div_diff = alloc_tri(n);
  i = 0;  /*initialize first column to be data sample y values*/
  while (i < n) {
    div_diff[i][0] = sample[i].y;
    i++;
  }
  j = 1;  /*calculate second through nth column*/
  while (j < n) {
    i = 0;
    while (i < (n - j)) {
      div_diff[i][j] = (div_diff[i + 1][j - 1] - div_diff[i][j - 1]) / (sample[i + j].x - sample[i].x);
      i++;
    }
    j++;
  }
  disp_tri(n,div_diff);
  return(0);
}

double newton(int n,struct point2d *sample,double x) {
  int j;
  double p;

  if (n < 2) return(0.0);
  if (div_diff == NULL) return(0.0);
  p = div_diff[0][n - 1];
  j = n - 2;
  while (j >= 0) {
    p = (p * (x - sample[j].x)) + div_diff[0][j];
    j--;
  }
  return(p);
}
