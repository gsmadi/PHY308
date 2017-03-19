#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generate random numbers of type double between frmin and frmax
double frand(double frmin, double frmax)
{
    double f = (double)rand() / RAND_MAX;
    return frmin + f * (frmax - frmin);
}

// Monte Carlo Integration
double mc(double a, double b, double c, double M, int N) {
    double x = 0.0, y = 0.0, a_i = 0.0, b_i = 0.0, d_i = 0.0;
    double distance_sum = 0.0;
    int n = 0; // Points inside body

    // Initialize random number generator
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        x = frand(-a, a);
        y = frand(-a, a);

        d_i = (pow(x, 2) + pow(y, 2));
        b_i = (pow(x - c, 2) + pow(y, 2));

        if (d_i <= pow(a, 2) && b_i >= pow(b, 2)) {
          distance_sum += d_i;
          n += 1;
        }

    }

    printf("Points inside body: %d\n", n);
    printf("Sum to n ratio: %lf\n", distance_sum/n);
    return (M*(distance_sum/n));
}

int main( int argc, char *argv[] )
{
    int N = atoi(argv[1]);
    double a = atof(argv[2]);
    double b = atof(argv[3]);
    double c = atof(argv[4]);
    double M = atof(argv[5]);
    double ans = 0.0;

    ans = mc(a, b, c, M, N);

    printf("Moment of inertia of crescent for N = %d\n", N);
    printf("I = %lf\n", ans);

    return 0;
}
