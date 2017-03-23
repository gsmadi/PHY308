/*





*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOTAL_SPIN_STATES 256 // Total number of spin states in simulation
#define MONTE_CARLO_STEPS 10000 // Number of monte carlo iterations
#define J 1 // Coupling constant (+1 meaning a ferromagnetic material)
#define K_B 1 // Boltzmann constant (J/K_B taken as unity)

/*
   The size of the lattice is given by N = L * L = (TOTAL_SPIN_STATES).
   The simulation shall be executed until N = 256 or L = 32.
*/
int L = 2;
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

double state_hamiltonian(int lattice[], int state) {
    double energy = 0.0;
    int right = 0, left = 0, above = 0, below = 0;
    int location = lattice[state];

    // Right neightbor
    if (state != L) {
        right = lattice[state + 1];
    } else {
        right = lattice[state - (L - 1)];
    }

    // Left neightbor
    if (state != 0) {
        left = lattice[state - 1];
    } else {
        left = lattice[state + (L + 1)];
    }

    // Above neightbor
    if (state < L) {
      above = lattice[state + L*(L - 1)];
    } else {
      above = lattice[state - L];
    }

    // Below neightbor
    if (state >= L*(L - 1)) {
      below = lattice[state - L*(L -1)];
    } else {
      below = lattice[state + 1];
    }

    // State energy
    energy = -J * location * (right + left + above + below);

    return (energy);
}

int total_magnetization(int lattice[]) {
    int n_up = 0, n_down = 0;
    int magnetization = 0;

    for (int i = 0; i <= L; i++) {
        if (lattice[i] == 1) {
          n_up += 1;
        } else {
          n_down += 1;
        }
    }

    magnetization = n_up - n_down;

    return (magnetization);
}

double partition_function(int lattice[], double beta) {
    double Z = 0.0;

    for (int i = 0; i < L; i++) {
        Z += exp(-beta * state_hamiltonian(lattice, i));
    }

    return (Z);
}

double state_probability(int lattice[], double beta, int state) {
    double p = 0.0;
    double state_energy = 0.0;
    double partition = 0.0;

    state_energy = state_hamiltonian(lattice, state);
    partition = partition_function(lattice, beta);

    p = exp(-beta*state_energy) / partition;

    return (p);
}

void print_lattice(int lattice[]) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            if (lattice[j] == 1) {
                printf("1 "); // Spin up
            } else {
                printf("-1 "); // Spin down
            }
        }
        printf("\n");
    }

    printf("\n");
}

void metropolis(int lattice[], double beta) {
    // Choose random location in lattice to select state
    int random_state = 0;
    double random_num = 0.0;
    double state_energy = 0.0;
    double mag = 0.0, mag_absolute = 0.0, magnetic_susceptability = 0.0;
    double mag_total = 0.0, mag_total_squared = 0.0, mag_absolute_total = 0.0;
    double mag_average = 0.0, mag_absolute_average = 0.0, mag_squared_average = 0.0;
    double normalization_constant = (double)(1.0/(L*L*MONTE_CARLO_STEPS));

    // Initialize observable
    mag = total_magnetization(lattice);
    mag_absolute = abs(total_magnetization(lattice));

    // Monter Carlo loop
    for (int i = 0; i < MONTE_CARLO_STEPS; i++) {

        // Metropolis loop
        for (int j = 0; j < L * L; j++) {
            // Choose random location in lattice to select state
            random_state = irand(L);

            // Compute energy of selected state
            state_energy = state_hamiltonian(lattice, random_state);

            if (state_energy <= 0) {
                // Flip spin
                lattice[random_state] = -lattice[random_state];

                // Print lattice update
                //print_lattice(lattice);

                // Store change in observable
                mag += 2*lattice[random_state];
                mag_absolute += abs(lattice[random_state]);
            } else {
                // Decide to flip based on state probability
                random_num = frand(0.0, 0.9999);

                if (random_num < exp(-state_energy/beta)) {
                    // Flip due to heat bath
                    lattice[random_state] = -lattice[random_state];

                    // Print lattice update
                    //print_lattice(lattice);

                    // Store change in observable
                    mag += 2*lattice[random_state];
                    mag_absolute += abs(lattice[random_state]);
                }
            }
        }

        // Add change to observable
        mag_total += mag;
        mag_total_squared += mag * mag;
        mag_absolute_total += sqrt(mag * mag);
    }

    // Average value of observable
    mag_average = mag_total * normalization_constant;
    mag_squared_average = mag_total_squared * normalization_constant;
    mag_absolute_average = mag_absolute_total * normalization_constant;
    magnetic_susceptability = mag_squared_average - pow(mag_average, 2);

    // Save results to file
    fprintf(data_file, "%lf, %lf, %lf, %lf, %lf\n", beta, mag_average,
            mag_squared_average, mag_absolute_average, magnetic_susceptability);

    // Print results to screen
    fprintf(stdout, "beta =  %lf\n", beta);
    fprintf(stdout, "Average magnetization: %lf\n", mag_average);
    fprintf(stdout, "Average magnetization squared: %lf\n", mag_squared_average);
    fprintf(stdout, "Average absolute magnetization: %lf\n", mag_absolute_average);
    fprintf(stdout, "Average magnetic susceptability: %lf\n", magnetic_susceptability);
}


int main(int argc, char const *argv[]) {
    // 1-D representation of 2-D Ising model lattice
    int lattice[TOTAL_SPIN_STATES];

    // Initialize system beta, where beta = J/(K_B*T)
    double beta = 0.1;

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
          lattice[i] = 1;
      }

      // Simulate ising model for different temperatures (beta)
      for (; beta <= 5.0; beta += 0.01) {
          // Update system using Metropolis algorithm
          metropolis(lattice, beta);
      }

      // Close data file
      fclose(data_file);

      // Reinitialize parameters for next simulation
      L *= 2;
      beta = 0.1;
      printf("\n");
    }

    return 0;
}
