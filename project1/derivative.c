#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_LIMIT 0.0000001

float compute_derivative_sine(float point_x, float h);

int main( int argc, char *argv[] )
{
  double actual, computed;
  double h = 5.0;

  while(h > MIN_LIMIT) {
    for (double x = 0.0; x < M_PI; x=x+0.1) {
      actual = cos(x);
      computed = compute_derivative_sine(x, h);

      printf("Computed = %lf; Actual = %lf, h = %lf\n", computed, actual, h);
    }

    h = h - 0.1;
  }

  return 0;
}

float compute_derivative_sine(float point_x, float h) {
  float derivative;

  derivative = (sin(point_x + h) - sin(point_x))/ h;

  return derivative;
}
