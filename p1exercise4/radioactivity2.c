#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

  FILE *fp;
  float remainingAtoms = 0.0;
  static const float tau = 5.0E4;
  int t = 0;
  float lambda = log(2) / tau;

  fp=fopen("radioactivity2.dat", "w");

  do {
    remainingAtoms = exp(-lambda * (float)(t)); // N/N_0
    fprintf(fp, "%d %f\n", t, remainingAtoms);
    t = t + 1000;
  } while (remainingAtoms > 0.1);

  fclose(fp);

  return 0;
}
