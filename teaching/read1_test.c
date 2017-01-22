#include <stdio.h>
int main( int argc, char *argv[] )
{
  const int n = 4;
  int i, code, a[n];
  float x[n], y[n];
  FILE *fp;

  fp = fopen( "input2.txt", "r" );
  if ( !fp )
  {
    fprintf( stderr, "unable to open input file\n" );
    return 1;
  }

  /*i = code = 0;
  while( code != EOF && i < n )
  {
    code = fscanf( fp, "%d %f %f\n", a + i, x + i, y + i );
    fprintf( stderr, "read %d elements\n", code );
    ++i;
    }*/
  int j=0;

  i = code = 0;
  for(i=0; i<n; i++)
    {
      code=fscanf(fp, "%d %f %f\n", a + i, x + i, y + i);
      fprintf( stderr, "read %d elements\n", code );
      if(code == EOF)
	{
	  i=n;
	  j--;
	}
      j++;
    }

  for ( i = 0; i < j; ++i )
  {
    fprintf( stdout, "%d %f %f\n", a[i], x[i], y[i] );
  }

  return 0;
}
