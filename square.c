#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

const double s = 0.25881867051;
const double c = 0.96592592665;

double t[4][4] = {{c, s, 0.0, 0.0},
                  {-s, c, 0.0, 0.0},
                  {0.0, 0.0, 1.0, 0.0},
                  {0.0, 0.0, 0.0, 1.0}};

double m[4][4] = {{1.0, 0.0, 0.0, 0.0},
                  {0.0, 1.0, 0.0, 0.0},
                  {0.0, 0.0, 1.0, 0.0},
                  {0.0, 0.0, 0.0, 1.0}};

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                         // start with identity matrix
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); // setup a 10x10x2 viewing world

    //glRotated(-15, 0, 0, 1);

    glMultMatrixd((double *)t);

    glBegin(GL_LINES);

    glColor3f(0.0, 0.0, 0.0);

    glVertex3f(4.0, 4.0, 0);
    glVertex3f(6.0, 6.0, 0);
    glVertex3f(6.0, 6.0, 0);
    glVertex3f(8.0, 4.0, 0);
    glVertex3f(8.0, 4.0, 0);
    glVertex3f(6.0, 2.0, 0);
    glVertex3f(6.0, 2.0, 0);
    glVertex3f(4.0, 4.0, 0);
    glEnd();
    //glPopMatrix();
    //glMultMatrixd((double *)m);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutCreateWindow("square");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}