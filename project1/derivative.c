#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_LIMIT 0.001
#define DELTA_H 0.01

float compute_derivative_sine(float point_x, float h);

int main( int argc, char *argv[] )
{
  FILE *fp;
  float actual, computed, error;
  float h = 5.0;
  float x = 0.0;
  // Open data file
  fp = fopen( "errors_0.dat", "w" );

  while(h > MIN_LIMIT) {
    //for (float x = 0.0; x < M_PI; x=x+(M_PI/16)) {
      actual = cos(x);
      computed = compute_derivative_sine(x, h);
      error = computed - actual;

      fprintf(fp, "%lf %lf\n", h, fabs(error));
    //}

    h = h - DELTA_H;
  }

  fclose(fp);

  return 0;
}

float compute_derivative_sine(float point_x, float h) {
  float derivative;

  derivative = (sin(point_x + h) - sin(point_x))/ h;

  return derivative;
}
