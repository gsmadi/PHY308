#include <stdio.h>
#include <limits.h>

int main ( int argc, char *argv[] )
{
  int i;

  /* the largest integer is stored in the macro MAX_INT */
  /* which is defined in the header file limits.h       */
  i = INT_MAX;
  printf( "The largest integer is %d\n", i );

  i = i + 10;
  printf( "The value of INT_MAX + 10 = %d\n", i );

  return 0;
}
