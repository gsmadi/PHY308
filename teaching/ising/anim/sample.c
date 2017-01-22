#include <GL/glut.h>      // for Linux
#include <GL/glext.h>      // for Linux
//#include <GLUT/glut.h>       // for Macs 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define window_size 800

double t=0;
double dt=1e-5;
double x=0;
double y=0.8;
double vx=-5;
double vy=0;
double GM=4*M_PI*M_PI;
int nextdraw=-1;
int walltime;
int last_walltime;
int steps=0;
int frames=0;



void idle(void) // GLUT calls this functino in a continuous loop
{
  steps++;   // keep track of how many steps we've done, for statistics (press F)
  static double xmid,ymid,vxmid,vymid,r; // declare these as static to avoid overhead from memory reallocation each time idle() is called
  //rk2 halfstep
  xmid=x+vx*dt/2; 
  ymid=y+vy*dt/2;
  r=sqrt(x*x+y*y);
  vxmid=vx-x*GM/(r*r*r)*dt/2;
  vymid=vy-y*GM/(r*r*r)*dt/2;
  
  //rk2 step
  x+=vxmid*dt;
  y+=vymid*dt;
  r=sqrt(xmid*xmid+ymid*ymid);
  vx+=-xmid*GM/(r*r*r)*dt;
  vy+=-ymid*GM/(r*r*r)*dt;
  
  t+=dt;

  usleep(1); // slow this down by waiting one millisecond, so we don't do millions of timesteps per second
  walltime=glutGet(GLUT_ELAPSED_TIME); // what time is it now?
  if (walltime > nextdraw) glutPostRedisplay();  // nextdraw keeps track of when we think the screen needs updating
}

void circle(double x, double y, double r) // a function of mine to draw a crude circle
{
  int i;
  double angle;
  glBegin(GL_LINE_LOOP); // this does continuous lines at all the vertices; you can also do GL_LINES for single lines
  for (i=0;i<30;i++) // 30-sided polygon, close enough to a circle at 2:30AM, dammit
  {
    angle = i*2*M_PI/30;
    glVertex3f((x+cos(angle)*r), (y+sin(angle)*r),0); // I don't know how to use GL's perspective stuff, so the z-coordinate here is 0
  }
  glEnd(); // end the drawing command we started with glBegin
}


void disp(void) // this function will trigger whenever glutPostRedisplay() is called
{
  frames++;
  glClear(GL_COLOR_BUFFER_BIT); // reset the screen to something blank
  circle(0,0,0.1);
  circle(x,y,0.02);
  glutSwapBuffers(); // this is the equivalent of anim's "F" command: "write the frame we've completed to the screen and start working on a new one"
  nextdraw=glutGet(GLUT_ELAPSED_TIME)+15; // schedule the next screen refresh to be 15ms from now, which is about 60fps
}

void keyb(unsigned char key, int x, int y)    // this function will trigger whenever the user presses a key
{
  if (key == 'Q') {exit(0);} // quit
  if (key == 'F') {printf("Drawn %d frames and simulated %d RK2 steps in %d milliseconds\n",frames,steps,glutGet(GLUT_ELAPSED_TIME)-last_walltime); 
    last_walltime=glutGet(GLUT_ELAPSED_TIME);
    frames=0;
    steps=0;
  }
}    

int main(int argc, char **argv)
{
  //INITIALIZATION
  glutInit(&argc, argv);
  
  //set rgba and double buffering  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |  GLUT_MULTISAMPLE);

  //set window size and position and title
  glutInitWindowSize(800,800); // modify if you have a low resolution screen
  glutInitWindowPosition(100,100);
  glutCreateWindow("Animation sample");

  //SET CALLBACKS
  glutDisplayFunc(disp); // function to execute whenever glutPostRedisplay is called
  glutKeyboardFunc(keyb); // function to execute whenever a key is pressed
  glutIdleFunc(idle); // functino to execute whenever we have nothing else to do

  //DO OPENGL INIT
  glEnable(GL_BLEND); // turn on alpha channel
  glEnable(GL_MULTISAMPLE); // turn on antialiasing
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // some magic that has to do with alpha blending; this is the only thing I use here
  glClearColor(0.0, 0.0, 0.0, 1.0); // background color: RGB = 0, alpha = 1
  
  glMatrixMode(GL_PROJECTION); // I don't do OpenGL 3D perspective, but this controls it (somehow) -- I found this in a tutorial. Need to learn how this works in more detail!
  glLoadIdentity();
  
  walltime=last_walltime=glutGet(GLUT_ELAPSED_TIME); // update our clocks
  glutMainLoop(); // start the thing
}
