#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char *argv[] )
{
  double x, h;
  double computed, actual;

  x = atof( argv[1] );
  h = atof( argv[2] );

  /* Compute derivative of sine */
  computed = (sin(x + h) - sin(x))/ h;
  actual = cos(x);

  /* print the roots to the screen */
  printf("d(sin x)/dx at x=%lf\n", x);
  printf( "Computed = %lf; Actual = %lf\n", computed, actual);

  return 0;
}
