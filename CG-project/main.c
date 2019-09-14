#include <stdio.h>
#include <GL/glut.h>
#include "lib/showIntro.c"

void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 899, 0, 499);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    showIntro();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(900, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("CG-Project");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}