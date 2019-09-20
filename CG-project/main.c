#include <stdio.h>
#include <GL/glut.h>
#include "lib/showIntro.c"
#include "lib/moveStickMan.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

int stickManStart = 0;
int stickMaxEnd = 1000;
float stickManSpeed = 0.3;

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

    moveStickMan(stickManStart, stickMaxEnd, stickManSpeed);
    // moveStickMan(1000, 0, 0.2);
    // drawStickMan(500, 20, 0, 0, 1);
    glFlush();
}

void keypress(unsigned char key, int x, int y) {
    if(key == 'r') {
        moveStickMan(stickManStart, stickMaxEnd, stickManSpeed);
    } else if(key == 'q') {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("CG-Project");
    glutDisplayFunc(display);
    glutReshapeFunc(init);
    glutKeyboardFunc(keypress);
    init();
    glutMainLoop();
}