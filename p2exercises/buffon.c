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

// Simulation
double mc(double t, double l, double* error, int N) {
    double estimate = 0.0, x = 0.0, theta = 0.0;
    double estimate_sum = 0.0, estimate_sum_squared = 0.0;
    int n = 0;

    // Initialize random number generator
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        x = frand(0.0, t/2.0);
        theta = frand(0.0, M_PI*0.5);

        if (x <= (0.5*l)*sin(theta)) {
          n += 1;

          estimate = (2*l*N)/(n*t);
          estimate_sum += estimate;
          estimate_sum_squared += pow(estimate, 2);
        }
    }

    *error = sigma_mc(estimate_sum, estimate_sum_squared, N);

    //error = mc_error();

    return (estimate);
}



int main( int argc, char *argv[] )
{
    int N = 0;
    int t = atoi(argv[1]);
    double l = atof(argv[2]);
    double pi_estimate = 0.0, error = 0.0;

    for (N = 1; N <= 10000000; N = N * 10) {
      pi_estimate = mc(t, l, &error, N);

      printf("Simulation for %d needle throws\n", N);
      printf("Estimated value of pi: %lf, Monte Carlo Error: %lf\n", pi_estimate, error);
      printf("\n");
    }

    return 0;
}
