#include <stdio.h>
int main( int argc, char *argv[] )
{
  const int n = 3;
  int i, code, a[n];
  float x[n], y[n];
  FILE *fp;

  fp = fopen( "input1.txt", "r" );
  if ( !fp )
  {
    fprintf( stderr, "unable to open input file\n" );
    return 1;
  }

  i = code = 0;
  while( code != EOF && i < n )
  {
    code = fscanf( fp, "%d %f %f\n", a + i, x + i, y + i );
    fprintf( stderr, "read %d elements\n", code );
    ++i;
  }

  

  for ( i = 0; i < n; ++i )
  {
    fprintf( stdout, "%d %f %f\n", a[i], x[i], y[i] );
  }

  return 0;
}
