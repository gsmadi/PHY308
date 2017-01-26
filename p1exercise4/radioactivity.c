#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

  FILE *fp;
  float remainingAtoms = 0.0;
  static const float tau = 5.0E4;
  int t = 0;
  float lambda = log(2) / tau;

  fp=fopen("radioactivity.dat", "w");

  for (t = 0; t <= 2E5; t=t+1000) {
    remainingAtoms = exp(-lambda * (float)(t)); // N/N_0

    fprintf(fp, "%d %f\n", t, remainingAtoms);
  }

  fclose(fp);

  return 0;
}
