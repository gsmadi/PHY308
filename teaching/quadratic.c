#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* program to find the roots of the quadratic equation ax^2 + bx + c      */
/* takes values of a, b, and c from the command line and prints the roots */

int main( int argc, char *argv[] )
{
  /* declare variables */
  float a, b, c;
  float discriminant, p_root, n_root;

  /* parse the coeffients from the command line */
  a = atof( argv[1] ); /* first argument is a */
  b = atof( argv[2] ); /* second argument is b */
  c = atof( argv[3] ); /* third argument is c */

  /* solve the quadratic equation */
  discriminant = b*b - 4.0*a*c;
  p_root = (-b + sqrt( discriminant )) / (2.0*a);
  n_root = (-b - sqrt( discriminant )) / (2.0*a);

  /* print the roots to the screen */
  printf( "positive root = %f\nnegative root = %f\n", p_root, n_root );

  return 0;
}
