#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generate random numbers of type double between frmin and frmax
double frand(double frmin, double frmax)
{
    double f = (double)rand() / RAND_MAX;
    return frmin + f * (frmax - frmin);
}

// Monte Carlo Error
double sigma_mc(double sum, double sum_2, double N) {
    double mc_error = 0.0;

    mc_error = sqrt(((sum_2/N) - pow(sum/N, 2))/N);

    return (mc_error); // sigma_mc = sigma / sqrt(N)
}

// Monte Carlo Integration
double mc( double (*func)(double x), double a, double b, int N ) {
    double sum = 0.0, sum_2 = 0.0, w_i = 1.0, x_i[N], mc_error = 0.0;

    // Initialize random number generator
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        x_i[i] = frand(a, b);
        sum += w_i * func(x_i[i]);
        sum_2 += pow(func(x_i[i]), 2);
    }

    mc_error = sigma_mc(sum, sum_2, (int)(N));
    printf("Monte Carlo Error for N = %d, sigma_mc = %lf\n", N, mc_error);

    return ((b - a)*sum/N);
}

double func(double x) {
  return (2.0 + cos(2*sqrt(x)));
}

int main( int argc, char *argv[] )
{
    int N = atoi(argv[1]);
    double a = 0.0;
    double b = 2.0;
    double ans, actual = 3.46;

    ans = mc(func, a, b, N);

    printf("Monte Carlo Integration for N = %d\n", N);
    fprintf( stdout, "Computed = %lf, Actual = %lf, Error = %lf\n", ans, actual, (ans-actual));

    return 0;
}
