#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simp( double (*func)(double x), double a, double b, double h) {
    double sum = 0.0, w_i = 0.0;
    int i = 0;

    for (double x_i = a + h; floorf(x_i*100)/100 <= b - h; x_i = x_i + h) {
        if (i % 2 == 0) {
            w_i = 4.0/3.0;
        } else {
            w_i = 2.0/3.0;
        }
        sum += w_i * func(x_i);
        i++;
    }

    return h*(((func(b) + func(a))/3.0) + sum);
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
    double actual_error = 0.0;

    ans = simp(func, a, b, h);

    actual_error = (1.0/90.0)*pow((b-a)/2.0, 5)*(16.0/105.0);

    printf("Simpson's Rule for N = %d\n", N);
    fprintf( stdout, "Computed = %lf, Actual = %lf, Error = %lf, Error bound = %lf\n", ans, actual, fabs(ans-actual), actual_error);

    return 0;
}
