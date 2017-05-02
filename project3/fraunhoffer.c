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
  double k = 589.29E-9;
  double a = 2.8E-6;
  int status = GSL_CONTINUE;
  int iter = 0, max_iter = 100;
  const gsl_root_fsolver_type *T;
  gsl_root_fsolver *s;
  double root = 0.0, r_expected = sqrt (5.0);
  double x_lo = M_PI, x_hi = 2*M_PI;
  gsl_function f;
  struct fraunhoffer_params params = { 1.0 };
  int n = 1;

  f.function = &fraunhoffer_amplitude;
  f.params = &params;

  T = gsl_root_fsolver_bisection;

  //printf ("using %s method\n", gsl_root_fsolver_name(s));

  printf ("%5s [%9s, %9s] %9s %10s %9s\n",
         "iter", "lower", "upper", "root",
         "err", "err(est)");

  while (root < 200.0) {
      s = gsl_root_fsolver_alloc(T);

      printf("[%lf, %lf]\n", x_hi, x_lo);
      gsl_root_fsolver_set(s, &f, x_lo, x_hi);

      while (status == GSL_CONTINUE && iter < max_iter) {
          status = gsl_root_fsolver_iterate(s);
          root = gsl_root_fsolver_root(s);
          x_lo = gsl_root_fsolver_x_lower(s);
          x_hi = gsl_root_fsolver_x_upper(s);
          status = gsl_root_test_interval(x_lo, x_hi,
                                           0, 0.001);

          if (status == GSL_SUCCESS)
            printf ("Converged:\n");

          printf ("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
                  iter, x_lo, x_hi,
                  root, root - r_expected,
                  x_hi - x_lo);
          iter++;
      }

      n += 1;

      x_lo += M_PI*n;
      x_hi += M_PI*(n+1);

      status = GSL_CONTINUE;
      iter = 0;

      gsl_root_fsolver_free(s);
  }

 return status;
}
