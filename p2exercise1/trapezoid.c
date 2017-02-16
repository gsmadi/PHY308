#include <stdio.h>
#include <math.h>

#define N 4

double trap( double (*func)(double x), double a, double b, double h ) {
    double sum = 0.0;

    for (double x_i = a + h; x_i < b - h; x_i = x_i + h) {
      sum += func(x_i);
      printf("Sum = %lf, x = %lf\n", sum, x_i);
    }


    return (h*(((func(b) + func(a))/2.0) + sum));
}

double func(double x) {
  return (2.0 + cos(2*sqrt(x)));
}

int main( int argc, char *argv[] )
{
    double a = 0.0;
    double b = 2.0;
    double h = (b - a)/(N - 1.0);
    double ans, actual = 3.46;

    ans = trap(func, a, b, h);

    printf("N = %d, h = %lf\n", N, h);

    fprintf( stdout, "Computed = %lf, Actual = %lf, Error = %lf\n", ans, actual, (ans-actual));

    return 0;
}
