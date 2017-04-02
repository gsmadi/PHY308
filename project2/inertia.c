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

// Moment of Inertia through Monte Carlo Integration
double moment_of_inertia(double a, double b, double c, double M, int N, double *mc_error) {
    FILE *simulation;
    char filename[80] = "";
    double x = 0.0, y = 0.0, b_i = 0.0, d_i = 0.0;
    double distance_sum = 0.0, inertia = 0.0;
    int n = 0; // Points inside body

    // Initialize random number generator
    srand(time(NULL));

    // Set data file name
    sprintf(filename, "./data/inertia-sim-%d.csv", N);

    // Open data file for current L
    simulation = fopen(filename, "w");

    for (int i = 0; i < N; i++) {
        x = frand(-a, a);
        y = frand(-a, a);

        fprintf(simulation, "%lf, %lf\n", x, y);

        d_i = (pow(x, 2) + pow(y, 2));
        b_i = (pow(x - c, 2) + pow(y, 2));

        if (d_i <= pow(a, 2) && b_i >= pow(b, 2)) {

          distance_sum += d_i;
          n += 1;
        }
    }

    inertia = M*(distance_sum/n);

    *mc_error = sigma_mc(inertia, pow(inertia, 2), N);

    return (inertia);
}

int main( int argc, char *argv[] )
{
    FILE *results;
    char filename[80] = "";
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double M = atof(argv[4]);
    double ans = 0.0, std = 0.0;

    // Set data file name
    sprintf(filename, "./data/inertia.csv");

    // Open data file for current L
    results = fopen(filename, "w");

    for (int N = 10; N < 100000000; N *= 10) {
      ans = moment_of_inertia(a, b, c, M, N, &std);

      printf("Moment of inertia of crescent for N = %d\n", N);
      printf("I = %lf +/-%lf\n", ans, std);

      // Save results to file
      fprintf(results, "%d, %lf, %lf\n", N, ans, std);
    }

    // Close results file
    fclose(results);

    return 0;
}
