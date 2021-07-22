
/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

/* This program was requested by Patrick Earl; hopefully someone else
   will write the equivalent Direct3D immediate mode program. */

#include <GL/glut.h>
#include <stdlib.h>

double m[4][4] = {{1.0, 0.0, 0.0, 0.0},
                  {0.0, 1.0, 0.0, 0.0},
                  {0.0, 0.0, 1.0, 0.0},
                  {0.0, 0.0, -3.0, 1.0}};

void display(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  glLoadIdentity();
  glMultMatrixd((double *)m);
  glRotated(-15, 1, 0, 0);
  //glTranslatef(0.0, 0.0, -3.0);
  //glRotatef(30, 1, 0, 0);
  glutWireCube(1.0);
  glPushMatrix();
  glFlush();
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //glOrtho(-3.0, 3.0, -3.0, 3.0, 1.5, 20.0);
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(10, 10);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
