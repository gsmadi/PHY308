#include <stdio.h>
#include <math.h>

main()
{
  double theta = 0.5;
  double L=1;
  double g=9.8;
  double omega = 0;
  double t, dt=0.01;
  for (t=0; t<100; t += dt)
  {

    theta += omega*dt;
    omega += -sin(theta)*g/L*dt;

    printf("l 0 0 %lf %lf\n",L*sin(theta),-L*cos(theta)); // draw a line
    printf("c %lf %lf 0.05\n",L*sin(theta),-L*cos(theta)); // with a ball
    printf("F\n"); // Flush this to screen
  }
}
