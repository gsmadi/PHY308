#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float quad_solve( float *root_p, float *root_n, float a, float b, float c );
float compute_positive_root(float a, float b, float d);
float compute_negative_root(float a, float b, float d);

int main( int argc, char *argv[] )
{
  float a, b, c;
  float p_root, n_root;

  a = atof( argv[1] );
  b = atof( argv[2] );
  c = atof( argv[3] );

  /* Solve the quadratic equation */
  quad_solve( &p_root, &n_root, a, b, c);

  /* Print the roots to the screen */
  printf( "Positive root = %f\nNegative root = %f\n", p_root, n_root );

  return 0;
}

/* Function to solve quadratic equation */
float quad_solve( float *root_p, float *root_n, float a, float b, float c )
{
  float d = b*b - 4.0*a*c;

  *root_p = compute_positive_root(a, b, d);
  *root_n = compute_negative_root(a, b, d);

  return d;
}

/* Compute roots */
float compute_positive_root(float a, float b, float d) {
  return (-b + sqrt(d)) / (2.0*a);
}

float compute_negative_root(float a, float b, float d) {
  return (-b - sqrt(d)) / (2.0*a);
}
