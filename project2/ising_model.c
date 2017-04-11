/*





*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define TOTAL_SPIN_STATES 4096 // Total number of spin states in simulation
#define MONTE_CARLO_STEPS 100000 // Number of monte carlo iterations
#define J 1 // Coupling constant (+1 meaning a ferromagnetic material)
#define K_B 1 // Boltzmann constant (J/K_B taken as unity)

/*
   The size of the lattice is given by N = L * L = (TOTAL_SPIN_STATES).
   The simulation shall be executed until N = 256 or L =16.
*/
int L = 4;
FILE *data_file;

// Generate random numbers of type double between frmin and frmax
double frand(double frmin, double frmax) {
    double f = (double)rand() / RAND_MAX;

    return frmin + f * (frmax - frmin);
}

// Generate random numbers of type int between 0 and irmax
int irand(int irmax) {
    int f = rand() % irmax;

    return f;
}

// Print lattice configuration to console
void print_lattice(int lattice[]) {
    for (int i = 0; i < L*L; ++i) {
        if (lattice[i] == 1) {
            printf("+ "); // Spin up
        } else {
            printf("- "); // Spin down
        }

        if (i != L*L && (i + 1) % L == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

// Save lattice configuration to file
void save_lattice(int lattice[], double T) {
    FILE *lattice_file;
    char filename[80] = "";

    // Set data file name
    sprintf(filename, "./data/lattice-%d-%lf.csv", L, T);

    // Open data file for current L
    lattice_file = fopen(filename, "w");

    for (int i = 0; i < L*L; ++i) {
        if (lattice[i] == 1) {
            fprintf(lattice_file, "1 "); // Spin up
        } else {
            fprintf(lattice_file, "-1 "); // Spin up
        }

        if (i != L*L && (i + 1) % L == 0) {
            fprintf(lattice_file, "\n");
        }
    }

    fclose(lattice_file);

    printf("\n\n");
}

double hamiltonian(int lattice[], int state) {
    double energy = 0.0;
    int right = 0, left = 0, above = 0, below = 0;
    int location = lattice[state];

    // Right neightbor
    if ((state  + 1) % L != 0) {
        right = lattice[state + 1];
    } else {
        right = lattice[state - (L - 1)];
    }

    // Left neightbor
    if (state % L != 0) {
        left = lattice[state - 1];
    } else {
        left = lattice[state + (L - 1)];
    }

    // Above neightbor
    if (state < L) {
      above = lattice[state + L*(L - 1)];
    } else {
      above = lattice[state - L];
    }

    // Below neightbor
    if (state >= L*(L - 1)) {
      below = lattice[state - L*(L - 1)];
    } else {
      below = lattice[state + L];
    }

    // State energy
    energy = -J * location * (right + left + above + below);

    return (energy);
}

// Compute lattice magnetization (sum of all spins)
int total_magnetization(int lattice[]) {
    int magnetization = 0;

    for (int i = 0; i < L*L; i++) {
        magnetization += lattice[i];
    }

    return (magnetization);
}

void metropolis(int lattice[], double T) {
    int N = L*L;
    int random_state = 0;
    double random_num = 0.0;
    double delta_E = 0.0;
    double mag = 0.0, magnetic_susceptability = 0.0;
    double mag_total = 0.0, mag_total_squared = 0.0, mag_absolute_total = 0.0;
    double mag_average = 0.0, mag_absolute_average = 0.0;
    double mag_squared_average = 0.0, mag_squared_average_per_spin = 0.0;
    double normalization_constant = (double)(1.0/(N*MONTE_CARLO_STEPS));

    // Initialize observable
    mag = total_magnetization(lattice);

    // Monter Carlo loop
    for (int i = 0; i < MONTE_CARLO_STEPS; i++) {
        // Metropolis loop
        for (int j = 0; j < N; j++) {
            // Choose random location in lattice to select state
            random_state = irand(N);

            // Compute energy change of flipping random position
            delta_E = -2*hamiltonian(lattice, random_state);

            if (delta_E <= 0.0) {
                // Flip spin
                lattice[random_state] = -lattice[random_state];

                // Store change in observable
                // Flip due to heat bath
                mag += 2*lattice[random_state];
            } else {
                // Decide to flip randomly
                random_num = frand(0.0, 1.0);

                if (random_num < exp(-delta_E/(K_B*T))) {
                    lattice[random_state] = -lattice[random_state];

                    // Store change in observable
                    mag += 2*lattice[random_state];
                }
            }
        }

        // Add change to observable
        mag_total += mag;
        mag_total_squared += mag * mag;
        mag_absolute_total += sqrt(mag * mag);
    }

    // Average value of observables
    mag_average = (mag_total * normalization_constant);
    mag_squared_average = (mag_total_squared * normalization_constant);
    mag_squared_average_per_spin = mag_squared_average * (1.0/N);
    mag_absolute_average = (mag_absolute_total * normalization_constant);
    magnetic_susceptability = (mag_squared_average - (N*mag_absolute_average*mag_absolute_average)) / (K_B*T);

    // Save results to file
    fprintf(data_file, "%lf, %lf, %lf, %lf, %lf\n", T, mag_average,
            mag_squared_average_per_spin, mag_absolute_average, magnetic_susceptability);
}


int main(int argc, char const *argv[]) {
    // 1-D representation of 2-D Ising model lattice
    int lattice[TOTAL_SPIN_STATES];

    char filename[80] = "";

    // Run simulation for lattice
    while (L <= sqrt(TOTAL_SPIN_STATES)) {

      printf("Running Ising model simulation for L = %d\n", L);

      // Set data file name
      sprintf(filename, "./data/simulation_l_%d.csv", L);

      // Open data file for current L
      data_file = fopen(filename, "w");

      // Initialize lattice
      for (int i = 0; i < TOTAL_SPIN_STATES; i++) {
          if (frand(0.0, 1.0) <= 0.5) {
              lattice[i] = 1;
          } else {
              lattice[i] = -1;
          }
      }

      // Simulate ising model for different temperatures
      for (double T = 5.0; T >= 0.1; T -= 0.01) {
          // Update system using Metropolis algorithm
          metropolis(lattice, T);
      }

      // Close data file
      fclose(data_file);

      // Reinitialize parameters for next simulation
      L *= 2;
      printf("\n");
    }

    return 0;
}
