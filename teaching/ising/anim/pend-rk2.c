#include <stdio.h>
#include <math.h>
  
double L=1;
double g=9.8;

double rate_omega (double theta)
{
  return -g/L*sin(theta);
}

main()
{
  double theta = 0.5;
  double omega = 0;
  double theta_half;
  double omega_half;
  
  double t, dt=0.01;
  for (t=0; t<100; t += dt)
  {

    theta_half = theta + omega*dt/2;
    omega_half = omega + rate_omega(theta)*dt/2;

    theta = theta + omega_half*dt;
    omega = omega + rate_omega(theta_half)*dt;

    printf("l 0 0 %lf %lf\n",L*sin(theta),-L*cos(theta)); // draw a line
    printf("c %lf %lf 0.05\n",L*sin(theta),-L*cos(theta)); // with a ball
    printf("F\n"); // Flush this to screen
  }
}
