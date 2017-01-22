#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* program to find the roots of the quadratic equation ax^2 + bx + c      */
/* takes values of a, b, and c from the command line and prints the roots */

int main( int argc, char *argv[] )
{
  /* declare variables */
  float a, b, c;
  float discriminant;
  float p_root, n_root;
  float real, imag;

  if (argc < 4 || argc > 4) {
    printf("Please enter only 3 arguments. You entered %d arguments.\n", (argc - 1));
    return 1;
  }

  /* parse the coeffients from the command line */
  a = atof( argv[1] ); /* first argument is a */
  b = atof( argv[2] ); /* second argument is b */
  c = atof( argv[3] ); /* third argument is c */

  /* solve the quadratic equation */
  discriminant = b*b - 4.0*a*c;
  if ( discriminant > 0.0 )
  {
    /* compute the positive and negative roots */
    p_root = (-b + sqrt( discriminant )) / (2.0*a);
    n_root = (-b - sqrt( discriminant )) / (2.0*a);

    /* print the roots to the screen */
    printf( "positive root = %f\nnegative root = %f\n", p_root, n_root );
  }
  else if ( discriminant < 0.0 )
  {
    /* compute the complex roots */
    real = -b/(2.0*a);
    imag = sqrt(-discriminant)/(2.0*a);
    printf( "roots are %f + %fi and %f - %fi\n", real, imag, real, imag );
  }
  else
  {
    /* compute the one distinct (double) real root */
    printf( "equation has one real root = %f\n", -b/(2.0*a) );
  }

  return 0;
}
