#include <stdio.h>

int main ( int argc, char *argv[] )
{
  float x, y;

  /* initialize x and print its value */
  x = 1.0e30;
  printf( "The value of x = %e\n", x );
 
  /* compute x squared and print its value */
  y = x * x;
  printf( "The value of x * x = %e\n", y );

  /* divide x by zero and print its value */
  y = x / 0.0;
  printf( "The value of x / 0 = %e\n", y );

  /* divide zero by zero and print its value */
  y = 0.0 / 0.0;
  printf( "The value of 0 / 0 = %e\n", y );

  return 0;
}
