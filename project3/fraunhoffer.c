#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>

struct fraunhoffer_params {double A_o;};

double fraunhoffer_amplitude(double x, void *p) {
  struct fraunhoffer_params * params = (struct fraunhoffer_params *)p;

  double A_o = params->A_o;

  return (((-A_o*sin(x)/pow(x, 2)) + (A_o*cos(x)/x)));
}


int main (void)
{
  FILE *data;
  double k = 2*M_PI/589.29E-9;
  double a = 2.8E-6;
  double angle = 0.0;
  int status = GSL_CONTINUE;
  int iter = 0, max_iter = 100;
  const gsl_root_fsolver_type *T;
  gsl_root_fsolver *s;
  double root = 0.0;
  double x_lo = M_PI, x_hi = 2*M_PI;
  gsl_function f;
  struct fraunhoffer_params params = { 1.0 };
  int n = 1;
  char filename[80] = "";

  // Set data file name
  sprintf(filename, "./data/fraunhoffer.csv");

  // Open data file
  data = fopen(filename, "w");

  f.function = &fraunhoffer_amplitude;
  f.params = &params;

  T = gsl_root_fsolver_bisection;


  while (root < (k*a/2)) {
      s = gsl_root_fsolver_alloc(T);

      printf("Searching interval: [%lf, %lf]\n", x_hi, x_lo);
      gsl_root_fsolver_set(s, &f, x_lo, x_hi);

      while (status == GSL_CONTINUE && iter < max_iter) {
          status = gsl_root_fsolver_iterate(s);
          root = gsl_root_fsolver_root(s);
          x_lo = gsl_root_fsolver_x_lower(s);
          x_hi = gsl_root_fsolver_x_upper(s);
          status = gsl_root_test_interval(x_lo, x_hi,
                                           0, 0.001);

          iter++;
      }

      if (root < (k*a/2)) {
        angle = asin(2*root/(k*a));
        printf("Found root: %lf\n", root);
        printf("Equivalent diffraction angle: %lf radians, %lf degrees\n\n", angle, angle*(180/M_PI));
        fprintf(data, "%lf, %lf \n", root, angle);
      }

      n += 1;

      x_lo = M_PI*n;
      x_hi = M_PI*(n+1);

      status = GSL_CONTINUE;
      iter = 0;

      gsl_root_fsolver_free(s);
  }

  fclose(data);

 return status;
}
