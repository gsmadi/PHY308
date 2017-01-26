#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 10

int main(int argc, char *argv[]) {

  FILE *fp;
  double omega = atof(argv[1]); // Frequency
  double B = atof(argv[2]); // Amplitude
  double t = 0.0; // Time
  double x[N], v[N], a[N];

  // Open data file
  fp = fopen( "sho.dat", "w" );

  for (int i = 0; i < N; i++) {
    x[i] = B * cos(omega * t);
    v[i] = -omega * B * sin(omega * t);
    a[i] = -pow(omega, 2.0) * B * cos(omega * t);

    t = t + 0.5;
  }

  t = 0.0;

  for (int i = 0; i < N; i++) {
    fprintf(fp, "%lf %lf %lf %lf\n", t, x[i], v[i], a[i]);
    t += 0.5;
  }

  fclose(fp);

  return 0;
}
