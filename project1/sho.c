#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 10

int shm( double *x, double *v, double *a, int n,
double B, double omega, double t_start, double t_end );

int main(int argc, char *argv[]) {
  double omega = atof(argv[1]); // Frequency
  double B = atof(argv[2]); // Amplitude
  double x[N], v[N], a[N];

  //shm(&x, &v, &a, )


  return 0;
}

int shm( double *x, double *v, double *a, int n,
double B, double omega, double t_start, double t_end ) {

    FILE *fp;
    double t = t_start; // Time

    // Open data file
    fp = fopen( "sho.dat", "w" );


  for (int i = 0; i < N; i++) {
    if (t >= t_end) {
      break;
    }

    x[i] = B * cos(omega * t); // x(t)
    v[i] = -omega * B * sin(omega * t); // v(t)
    a[i] = -pow(omega, 2.0) * B * cos(omega * t); // a(t)

    fprintf(fp, "%lf %lf %lf %lf\n", t, x[i], v[i], a[i]);

    t += n;
  }

  fclose(fp);

  return 0;
}
