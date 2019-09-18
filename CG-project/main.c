#include <stdio.h>
#include <GL/glut.h>
#include "lib/showIntro.c"
#include "lib/drawStickMan.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 500);
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    // showIntro();

    glBegin(GL_POLYGON);
        glColor3f(0.95f, 0.95f, 0.95f);
        glVertex2f(0, 0);
        glVertex2f(1000, 0);
        glVertex2f(1000, 10);
        glVertex2f(0, 10);
    glEnd();

    drawStickMan();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("CG-Project");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}