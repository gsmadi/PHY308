#include <stdio.h>
#include <time.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>

int main(void) {
  FILE *data;
  int s;
  double det;
  clock_t start, end;
  double computation_time;
  gsl_matrix* m = gsl_matrix_alloc(1, 1);
  gsl_permutation * p = gsl_permutation_alloc(1);

  char filename[80] = "";

  // Set data file name
  sprintf(filename, "./data/det_time.csv");

  // Open data file for current L
  data = fopen(filename, "w");


  for(int i = 1; i <= 10; i++) {
    m = gsl_matrix_alloc(1000*i, 1000*i);
    p = gsl_permutation_alloc (1000*i);

    gsl_matrix_set_all(m, 2.0);

    start = clock();

    gsl_linalg_LU_decomp(m, p, &s);
    det = gsl_linalg_LU_det(m, s);

    end = clock();

    computation_time = (double)(end - start) / CLOCKS_PER_SEC;

    fprintf(data, "%d, %lf \n", i, computation_time);

    printf("Time to compute determinant of %d x %d: %lf\n", 1000*i, 1000*i, computation_time);

  }

  return 0;
}
