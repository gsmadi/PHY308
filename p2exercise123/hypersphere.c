#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generate random numbers of type double between frmin and frmax
double frand(double frmin, double frmax)
{
    double f = (double)rand() / RAND_MAX;
    return frmin + f * (frmax - frmin);
}

// Hypersphere volume approximation
double nball_volume(int dim, double r, unsigned long N) {
    double volume = 0.0, x_i[dim][N];
    int in_nball = 0, in_hypercube = 0;
    double condition = 0.0;
    
    // Initialize random number generator
    srand(time(NULL));

    // Initialize random value array
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < N; j++) {
            x_i[i][j] = frand(0.0, r);
        }
    }

    // Compute volume of nball
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < dim; j++) {
            // Compute condition
            condition += pow(x_i[j][i], 2);
        }

        if (condition <= pow(r, 2)) {
          // Random point in nball
          in_nball += 1;
        }

        in_hypercube += 1;

        condition = 0.0; // Initialize condition for next iteration
    }
    printf("inside = %d, outside = %d\n", in_nball, in_hypercube);

    volume = (in_nball / (double)(in_hypercube));

    return (volume*pow(2*r, dim));
}

int main( int argc, char *argv[] )
{
    unsigned long	N = atoi(argv[1]);
    int dim = atoi(argv[2]);
    double r = atof(argv[3]);
    double ans = 0.0;
    //double actual = M_PI * pow(r, 2); Circle
    //double actual = (4.0/3.0) * M_PI * pow(r, 3); Sphere
    double actual = pow(M_PI, 5) * pow(r, 10) / 120.0;

    ans = nball_volume(dim, r, N);

    printf("nball dimension %d volume for N = %lu\n", dim, N);
    fprintf( stdout, "Computed = %lf, Actual = %lf, Error = %lf\n", ans, actual, (ans-actual));

    return 0;
}
