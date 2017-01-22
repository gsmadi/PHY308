#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* program to evaluate the polynomial x^3 + 2x^2 - 120x + 11/3  */
/* for a value of x given by the user on the command line.      */

int main ( int argc, char *argv[] )
{
  /* declare variables */
  float x; /* the indepdendent variable x */
  float poly; /* the value of the polynomial at x */
  FILE *fp; /* a pointer to the output file */

  /* parse the command line argument */
  x = atof( argv[1] );

  /* subsitute in polynomial */
  poly = pow(x,3.0) + 2.0*pow(x,2.0) - 120.0*x + 11.0/3.0;

  /* create a new file called output.txt */
  fp = fopen( "output.txt", "w" );

  /* write the output to the file */
  fprintf( fp, "For x = %f the value of the polynomial is %f\n", 
    x, poly );

  /* close the output file */
  fclose( fp );

  /* exit the program with return code zero */
  return 0; 
}
