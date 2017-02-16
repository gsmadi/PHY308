#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap( double (*func)(double x), double a, double b, double h ) {
    double sum = 0.0;

    for (double x_i = a + h; x_i < b - h; x_i = x_i + h) {
      sum += func(x_i);
    }


    return (h*(((func(b) + func(a))/2.0) + sum));
}

double func(double x) {
  return (2.0 + cos(2*sqrt(x)));
}

int main( int argc, char *argv[] )
{
    int N = atoi(argv[1]);
    double a = 0.0;
    double b = 2.0;
    double h = (b - a)/(N - 1.0);
    double ans, actual = 3.46;

    ans = trap(func, a, b, h);

    printf("Trapezoidal Rule for N = %d\n", N);
    fprintf( stdout, "Computed = %lf, Actual = %lf, Error = %lf\n", ans, actual, (ans-actual));

    return 0;
}
