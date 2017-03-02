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
double mc(double (*func)(double x), double a, double b, double* mc_error, int N) {
    double sum = 0.0, sum_2 = 0.0, w_i = 1.0, x_i[N];

    // Initialize random number generator
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        x_i[i] = frand(a, b);
        sum += w_i * func(x_i[i]);
        sum_2 += pow(func(x_i[i]), 2);
    }

    *mc_error = sigma_mc(sum, sum_2, (int)(N));

    return ((b - a)*sum/N);
}

double normal_func(double x) {
  return ((1.0 + 0.25*cos(x))/(1 + pow(x, 2)));
}

double flat_func(double y) {
  return (1.0 + 0.25*cos(tan(y)));
}

int main( int argc, char *argv[] )
{
    int N = atoi(argv[1]);
    double a = -10, b = 10, c = atan(a), d = -atan(a);
    double ans, flat_ans;
    double ans_mc_error = 0.0;
    double flat_ans_mc_error = 0.0;

    ans = mc(normal_func, a, b, &ans_mc_error, N);

    flat_ans = mc(flat_func, c, d, &flat_ans_mc_error, N);

    printf("Monte Carlo Integration of function for N = %d\n", N);
    fprintf( stdout, "Normal = %lf, Normal MC Error = %lf, Flat = %lf,Flat MC Error = %lf\n", ans, ans_mc_error, flat_ans, flat_ans_mc_error) ;

    return 0;
}
