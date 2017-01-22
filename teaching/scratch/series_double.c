#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* compute n! using a recursive function (a function that calls itself) */
double factorial( double n )
{
  if ( n < 2.0 )
    return 1.0;
  else
    return n * factorial( n - 1.0 );
}

int main ( int argc, char* argv [] )
{
  /* counter for the power series expansion of exp(x) */
  long unsigned int i;
  /* maximum number of terms to include in the power series */
  long unsigned int i_max = 2000;

  /* value of x which we compute the exponential of */
  double x = 2.0;

  /* result of the power series expansion and the true value of exp(x) */
  double y = 0;
  double y_true = exp( x );

  /* the desired accuracy for the power series */
  double h = 1.0e-8;
  double h_measured;

  /* compute power series expansion of exp(x) including at most 100 terms */
  for ( i = 0; i < i_max; ++i )
  {
    /* notice how we case i to a double in the pow and factorial functions */
    y += pow( x, (double) i ) / factorial((double) i);

    /* calculate the difference between the two values */
    h_measured = fabs( y - y_true );

    fprintf( stdout, "%ld %e %e %e\n", i, y, y_true, h_measured );

    /* if the measured accuracy is less than the desired accuracy, break */
    /*  out of the for loop and stop adding terms to the power series    */
    if ( h_measured < h ) break;
  }

  if ( i == i_max - 1 )
  {
    fprintf( stderr, 
        "Error: could not reach desired accuracy after %ld iterations\n", i );
    return 1;
  }

  return 0;
}
