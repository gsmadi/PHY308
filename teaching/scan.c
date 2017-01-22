#include <stdio.h>

int main( int argc, char *argv[] )
{
  int i;
  float x;

  printf( "enter an integer: " );
  fscanf( stdin, "%d", &i );
  printf( "you entered %d\n", i );

  printf( "enter a float: " );
  fscanf( stdin, "%f", &x );
  printf( "you entered %f\n", x );

  return 0;
}
