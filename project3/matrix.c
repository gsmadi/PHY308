#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_eigen.h>

int main(void) {
  double matrix[] = { 1.0, 2.0, 3.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0 };
  double inva[9];

  int s;
  double det;

  gsl_matrix_view mat = gsl_matrix_view_array(matrix, 3, 3);
  gsl_matrix_view inv = gsl_matrix_view_array(inva,3,3);
  gsl_permutation * p = gsl_permutation_alloc (3);

  gsl_vector* eval = gsl_vector_alloc (3);
  gsl_matrix* evec = gsl_matrix_alloc (3, 3);
  gsl_eigen_symmv_workspace * w = gsl_eigen_symmv_alloc (3);

  printf("Matrix:\n");
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      printf(j==2?"%6.3f\n":"%6.3f ",gsl_matrix_get(&mat.matrix,i,j));

  gsl_linalg_LU_decomp(&mat.matrix, p, &s);
  gsl_linalg_LU_invert(&mat.matrix, p, &inv.matrix);

  det = gsl_linalg_LU_det(&mat.matrix, s);

  printf("\nInverse:\n");
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      printf(j==2?"%6.3f\n":"%6.3f ",gsl_matrix_get(&inv.matrix,i,j));

  printf("\nDeterminant: %lf\n", det);

  printf("\nEingenvalues & Eigenvectors:\n");

  gsl_eigen_symmv (&mat.matrix, eval, evec, w);
  gsl_eigen_symmv_free (w);
  gsl_eigen_symmv_sort (eval, evec, GSL_EIGEN_SORT_ABS_ASC);


    for (int i = 0; i < 3; i++)
    {
      double eval_i = gsl_vector_get (eval, i);
      gsl_vector_view evec_i = gsl_matrix_column (evec, i);

      printf ("Eigenvalue = %g\n", eval_i);
      printf ("Eigenvector = \n");
      gsl_vector_fprintf(stdout, &evec_i.vector, "%g");
      printf("\n\n");
    }



  gsl_permutation_free (p);
  gsl_vector_free (eval);
  gsl_matrix_free (evec);

  return 0;

}
