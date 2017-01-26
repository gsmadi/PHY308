#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {

  const float R = 8.31;
  float n = atof(argv[1]);
  float deltaT = atof(argv[2]);
  int numAtoms = atoi(argv[3]);
  float idealGasEnergy = 0.0;
  char igName[12];

  if (numAtoms == 1) {
    idealGasEnergy = (3.0/2) * n * R * deltaT;
    strcpy(igName, "monoatomic");
  } else {
    idealGasEnergy = (5.0/2) * n * R * deltaT;
    strcpy(igName, "diatomic");
  }


  printf("Energy for %s atom: %f Joules\n", igName, idealGasEnergy);

  return 0;
}
