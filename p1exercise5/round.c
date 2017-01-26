#include <stdio.h>

int main ( int argc, char* argv[] )
{
  int i, n;
  double x, y;
  double z = 0.3333;

  /* add z to itself one million times */
  n = 1000000;
  x = 0.0;
  for ( i = 0; i < n; i++ )
  {
    x += z;
  }

  /* multiply z by one million */
  y = z * (double) n;

  printf( "x = %f, y = %f, x - y = %f\n", x, y, x - y );

  return 0;
}
