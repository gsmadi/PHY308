#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int shm( double *x, double *v, double *a, int n,
double B, double omega, double t_start, double t_end );

int main(int argc, char *argv[]) {
  int n = 10;
  double omega = atof(argv[1]); // Frequency
  double B = atof(argv[2]); // Amplitude
  double x[n], v[n], a[n];

  shm(x, v, a, n, B, omega, 0.0, 50.0);

  return 0;
}

int shm( double *x, double *v, double *a, int n,
double B, double omega, double t_start, double t_end ) {

  FILE *fp;
  double t = t_start; // Time
  double interval = (double)(t_end/n);
    // Open data file
    fp = fopen( "../data/sho.dat", "w" );


  for (int i = 0; i < n; i++) {
    if (t >= t_end) {
      break;
    }

    x[i] = B * cos(omega * t); // x(t)
    v[i] = -omega * B * sin(omega * t); // v(t)
    a[i] = -pow(omega, 2.0) * B * cos(omega * t); // a(t)

    fprintf(fp, "%lf %lf %lf\n", x[i], v[i], a[i]);

    t += interval;
  }

  fclose(fp);

  return 0;
}
