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

// Hypersphere volume approximation
double nball_volume(int dim, double r, int N, double *mc_error) {
    FILE *simulation;
    char filename[80] = "";
    double volume = 0.0, ratio = 0.0, x_i[dim];
    int in_nball = 0;
    double condition = 0.0;
    double volume_sum = 0.0, volume_sum_squared = 0.0;

    // Initialize random number generator
    srand(time(NULL));

    if (dim == 2 || dim == 3) {
      // Set data file name
      sprintf(filename, "./data/hypersim-%d-%d.csv", dim, N);

      // Open data file for current L
      simulation = fopen(filename, "w");
    }

    // Compute volume of nball
    for (int i = 1; i <= N; i++) {

        for (int j = 0; j < dim; j++) {
            // Compute condition
            x_i[j] = frand(0.0, r);

            if (dim == 2 || dim == 3) {
              fprintf(simulation, "%lf ", x_i[j]);
            }
            condition += pow(x_i[j], 2);
        }

        if (dim == 2 || dim == 3) {
          fprintf(simulation, "\n");
        }

        if (condition <= pow(r, 2)) {
          // Random point in nball
          in_nball += 1;
        }

        condition = 0.0; // Initialize condition for next iteration
    }

    // Ratio of points inside nball to all points generated
    ratio = (in_nball / (double)(N));

    volume = ratio*pow(2*r, dim);

    volume_sum += volume;
    volume_sum_squared += pow(volume, 2);

    *mc_error = sigma_mc(volume_sum, volume_sum_squared, N);

    if (dim == 2 || dim == 3) {
      fclose(simulation);
    }

    return (volume);
}

int main(int argc, char *argv[]) {
    FILE *results;
    char filename[80] = "";
    double r = atof(argv[1]);
    double ans = 0.0, std = 0.0, percentage_error = 0.0;
    double actual_circle = M_PI * pow(r, 2); // Circle
    double actual_sphere = (4.0/3.0) * M_PI * pow(r, 3); // Sphere
    double actual_ten_dim = pow(M_PI, 5) * pow(r, 10) / 120.0; // V_10 - 10 dimensions
    int dim = 2;

    while (dim <= 10) {
      // Set data file name
      sprintf(filename, "./data/hypersphere-%d.csv", dim);

      // Open data file for current L
      results = fopen(filename, "w");

      for (int N = 10; N < 1000000000; N = N * 10) {
          printf("Hypersphere volume of dimension %d for N = %d\n", dim, N);

          ans = nball_volume(dim, r, N, &std);

          printf("Computed = %lf +/- %lf\n\n", ans, std);

          // Save results to file
          fprintf(results, "%d, %lf, %lf\n", N, ans, std);
      }

      // Close results file
      fclose(results);

      // Run computation for dim - 2, 3 and 10
      if (dim == 2) {
        percentage_error = 100*fabs(ans - actual_circle)/actual_circle;

        printf("Best %c Error = %lf\n", 37, percentage_error);
        dim = 3;
      } else if (dim == 3) {
        percentage_error = 100*fabs(ans - actual_sphere)/actual_sphere;

        printf("Best %c Error = %lf\n", 37, percentage_error);

        dim = 10;
      } else {
        percentage_error = 100*fabs(ans - actual_ten_dim)/actual_ten_dim;

        printf("Best %c Error = %lf\n", 37, percentage_error);

        dim = 11;
      }
    }


    return 0;
}
