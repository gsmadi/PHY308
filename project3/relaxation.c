#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_LAT_SIZE 500

double MIN_DELTA = 0.000001;
int L = 100; // Lattice size

int compare_double(double a, double b, double e) {
  double diff = fabs(b - a);

  if (diff < e) {
    return 1;
  } else {
    return 0;
  }
}

double update_temp(double lattice[], int location, double f) {
  double right = 0.0, left = 0.0, above = 0.0, below = 0.0, center = 0.0;
  double temp = 0.0;

  // Center
  center = lattice[location];

  // Right neighbor
  if ((location  + 1) % L != 0) {
      right = lattice[location + 1];
  }

  // Left neightbor
  if (location % L != 0) {
      left = lattice[location - 1];
  }

  // Above neighbor
  if (location < L) {
    above = 0.0;
  } else {
    above = lattice[location - L];
  }

  // Below neighbor
  if (location >= L*(L - 1)) {
    below = 0.0;
  } else {
    below = lattice[location + L];
  }

  // Compute temperature at lattice location
  temp = (1 - f)*center + 0.25*f*(above + below + left + right);

  return temp;
}

void save_lattice(double lattice[], double f) {
  FILE *lattice_file;
  char filename[80] = "";

  // Set data file name
  sprintf(filename, "./data/lattice-%d-%lf.csv", L, f);

  // Open data file for current L
  lattice_file = fopen(filename, "w");

  for (int i = 0; i < L*L; ++i) {
      fprintf(lattice_file, "%lf ", lattice[i]);

      if (i != L*L && (i + 1) % L == 0) {
          fprintf(lattice_file, "\n");
      }
  }

  fclose(lattice_file);
}


int main(int argc, char const *argv[]) {
  int iter = 0; // Number of iterations for convergence
  double old = 0.0, new = 0.0, delta_T = 0.0;
  double delta_sum = 0.0, avg_delta = 1.0;
  long long T = 0.0; // Actual temperature
  double f_opt = 0.0; // Optimal relaxation factor
  double lattice[MAX_LAT_SIZE*MAX_LAT_SIZE]; // Temperature lattice
  int N = 0; // Total lattice elements
  clock_t start, end;
  double computation_time;
  FILE *relaxation_file;
  char filename[80] = "";

  printf("Running Simulation for over-relaxation of Laplace's equation\n");

  while (L <= MAX_LAT_SIZE) {
    printf("Lattice size: %d\n", L);

    N = L * L; // Total grid point in lattice

    // Set data file name
    sprintf(filename, "./data/relaxation-op-%d.csv", L);

    // Open data file for current L
    relaxation_file = fopen(filename, "w");

    // Run simulation for many relaxation factors
    for (double f = 1.9300; f <= 1.9999; f += 0.0001) {
      // Initialize lattice with boundry condition
      for (int i = 0; i < N; i++) {
        // Top of lattice at 100 degrees (absolute units)
        if (i < L) {
          lattice[i] = 100.0;
        } else {
          lattice[i] = 0.0;
        }
      }

      // Convergence time of relaxation
      start = clock();

      // Update lattice until desired delta is achieved
      while (avg_delta > MIN_DELTA) {
        for (int i = L; i < N; i++) {
          old = lattice[i];
          new = update_temp(lattice, i, f);

          lattice[i] = new;

          delta_sum += fabs(old - new);
        }

        avg_delta = delta_sum / N;
        delta_sum = 0.0;

        iter += 1;
      }

      end = clock();

      computation_time = (double)(end - start) / CLOCKS_PER_SEC;

      f_opt = 2.0 - (2.0*M_PI/L);

      if (compare_double(f, f_opt, 0.005)) {
        //save_lattice(lattice, f);
      }

      printf("comp_time: %lf, iter: %d, f = %lf\n", computation_time, iter, f);
      fprintf(relaxation_file, "%lf, %lf, %d\n", f, computation_time, iter);

      avg_delta = 1.0;
      iter = 0;
    }

    /******************* Actual temperature lattice ******************/
    /*
    for (int i = 0; i < L; i++) {
      for (int j = L; j < L; j++) {
        for (double n = 3.0; n <= 39.0; n += 2) {
          T += (400.0/(n*M_PI*sinh(n*M_PI)))*sinh(n*M_PI*(10.0-j)/10.0)*sin(n*M_PI*i/10.0);
        }

        lattice[i + j] = T;
        T = 0.0;
      }
    }

    save_lattice(lattice, 0.0);
    */
    /*****************************************************************/

    L += 100;
    fclose(relaxation_file);
  }

  return 0;
}
