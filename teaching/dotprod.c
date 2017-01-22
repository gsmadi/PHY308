#include <stdio.h>

int main( int argc, char* argv[] )
{
  unsigned int i;
  /* declare two arrays */
  const unsigned int n = 3;
  float x[n], y[n];
  float dotprod;

  /* fill the arrays */
  x[0] = 2.3;
  x[1] = 13.4;
  x[2] = 8.2;

  y[0] = 6.3;
  y[1] = 9.2;
  y[3] = 4.4;

  dotprod = 0;
  for ( i = 0; i < n; ++i )
  {
    dotprod += x[i] * y[i];
    printf( "x[%d] * y[%d] ", i, i );
    if ( i < (n-1) ) printf( "+ " );
  }

  printf( "= %f\n", dotprod );

  return 0;
}
