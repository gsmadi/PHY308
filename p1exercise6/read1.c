#include <stdio.h>
int main( int argc, char *argv[] )
{
  const int n = 2;
  int i, code, a[n];
  float x[n], y[n];
  FILE *fp;

  // Open file
  fp = fopen( "input2.txt", "r" );
  if ( !fp )
  {
    fprintf( stderr, "unable to open input file\n" );
    return 1;
  }

  // Read file until EOF - End of File
  i = code = 0;
  while( code != EOF && i < n )
  {
    // Read a line and store contents in three distict arrays
    code = fscanf( fp, "%d %f %f\n", a + i, x + i, y + i );
    fprintf( stderr, "read %d elements\n", code );
    ++i;
  }


  // Print read in data
  for ( i = 0; i < n; ++i )
  {
    fprintf( stdout, "%d %f %f\n", a[i], x[i], y[i] );
  }

  return 0;
}
