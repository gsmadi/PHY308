#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

  float tau = atof(argv[1]);
  float t = atof(argv[2]);

  float lambda = log(2) / tau;

  float remainingAtoms = exp(-lambda * t); // N/N_0

  printf("Remaining radioactive atoms: %f\n", remainingAtoms);

  return 0;
}
