#include <stdio.h>
#include <math.h>

int drawint = 10000; // number of physics updates per frame

double hypot3(double x,double y, double z) // utility function to simplify some math
{
  return sqrt(x*x+y*y+z*z);
}

int main()
{
  int N=80; // number of nodes
  double stiffness_per_length = 1; // do some preparatory work to make sure we get the same physics, no matter what N is
  double length_unstretched = 1;
  double dt = 0.001,t=0;
  double mass, m;
  mass=1;
  m=mass/N;
  double k = stiffness_per_length / length_unstretched;
  double kp = k / N;
  double U,T;
  double r,F;
  double length_stretched = 1.1; // initial condition: stretch to 10% extra length
  int iters=0;
  double dx = length_stretched/N;
  double dx0 = length_unstretched/N;

  double x[N+1],y[N+1],z[N+1],vx[N+1],vy[N+1],vz[N+1];
  double xm[N+1],ym[N+1],zm[N+1],vxm[N+1],vym[N+1],vzm[N+1];

  
  int i,j;
  
  for (i=0;i<N+1;i++)
  {
    x[i]=(-length_stretched/2) + i * dx;
    y[i]=0.1*sin((float)i/N*5*3.1415926535); 
    z[i]=vx[i]=vy[i]=vz[i]=0;
    vxm[i]=vym[i]=vzm[i]=0;
    xm[i]=x[i];
    ym[i]=y[i];
    zm[i]=z[i];
    printf("!Initial position of node %d: %e, %e, %e\n",i,x[i],y[i],z[i]);
  } 

  for (t=0;1==1;t+=dt)
  {
    iters++;
    for (i=1;i<N;i++) // rk2 halfstep
    {
      // left side
      r=hypot3(x[i-1]-x[i],y[i-1]-y[i],z[i-1]-z[i]);
      F=kp*(r-dx0);
      vxm[i] = vx[i]+F/m*(x[i-1]-x[i])/r*dt/2;
      vym[i] = vy[i]+F/m*(y[i-1]-y[i])/r*dt/2;
      vzm[i] = vz[i]+F/m*(z[i-1]-z[i])/r*dt/2;
      // right side
      r=hypot3(x[i+1]-x[i],y[i+1]-y[i],z[i+1]-z[i]);
      F=kp*(r-dx0);
      vxm[i] += F/m*(x[i+1]-x[i])/r*dt/2;
      vym[i] += F/m*(y[i+1]-y[i])/r*dt/2;
      vzm[i] += F/m*(z[i+1]-z[i])/r*dt/2;
      xm[i] = x[i]-vx[i]*dt/2;
      ym[i] = y[i]-vy[i]*dt/2;
      zm[i] = z[i]-vz[i]*dt/2;
   }
   T=U=0;
   for (i=0;i<=N;i++) // rk2 fullstep
    {
      if (i==0 || i==N) continue;
      // left side
      r=hypot3(xm[i-1]-xm[i],ym[i-1]-ym[i],zm[i-1]-zm[i]);
      F=kp*(r-dx0);
      T+=0.5*m*(vx[i]*vx[i]+vy[i]*vy[i]+vz[i]*vz[i]);
      U+=0.5*kp*(r-dx0)*(r-dx0); // potential energy
      vx[i] = vx[i]+F/m*(xm[i-1]-xm[i])/r*dt;
      vy[i] = vy[i]+F/m*(ym[i-1]-ym[i])/r*dt;
      vz[i] = vz[i]+F/m*(zm[i-1]-zm[i])/r*dt;
      // right side
      r=hypot3(xm[i+1]-xm[i],ym[i+1]-ym[i],zm[i+1]-zm[i]);
      F=kp*(r-dx0);
      U+=0.5*kp*(r-dx0)*(r-dx0); // potential energy
      vx[i] = vx[i]+F/m*(xm[i+1]-xm[i])/r*dt;
      vy[i] = vy[i]+F/m*(ym[i+1]-ym[i])/r*dt;
      vz[i] = vz[i]+F/m*(zm[i+1]-zm[i])/r*dt;
      x[i] = x[i]+vxm[i]*dt;
      y[i] = y[i]+vym[i]*dt;
      z[i] = z[i]+vzm[i]*dt;
   }
  if (iters % drawint == 0)
  {
    for (i=0;i<=N;i++)
    {
      printf("T 0 0.8\nT=%.3e\tU=%.3e\tE=%.3e\n",T,U,T+U);
      printf("c3 %e %e %e %e\n",x[i],y[i],z[i],0.01);
      if (i==N) break; // don't draw a line from the last node
      printf("l3 %e %e %e %e %e %e\n",x[i],y[i],z[i],x[i+1],y[i+1],z[i+1]);
    }
    printf("F\n");
  }
  }
}
