#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 2

// Generate random numbers of type double between frmin and frmax
double frand(double frmin, double frmax)
{
    double f = (double)rand() / RAND_MAX;
    return frmin + f * (frmax - frmin);
}

void print_lattice(int lattice[L][L]) {
  // Initialize lattice
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < L; j++) {
      printf("%d ", lattice[i][j]);
    }
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  int lattice[L][L];

  // Initialize lattice
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < L; j++) {
      lattice[i][j] = 1;
    }
  }

  // Metropolis algorithm
  print_lattice(lattice);

  return 0;
}
