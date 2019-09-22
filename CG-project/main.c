#include <stdio.h>
#include <GL/glut.h>
#include "lib/showIntro.c"
#include "lib/moveStickMan.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

int stickManStart = 0;
int stickMaxEnd = 1000;
float stickManSpeed = 0.3;
int showingIntroFlag = 1;

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
    showIntro();

    // moveStickMan(stickManStart, stickMaxEnd, stickManSpeed);
    // moveStickMan(1000, 0, 0.2);
    // drawStickMan(500, 20, 0, 0, 1);

    // drawSpearStickMan(500, 0, 0, 0, 1);

    glFlush();
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 500);
}

void keypress(unsigned char key, int x, int y) {
    if(key == 's') {
        if(showingIntroFlag) {
            glClearColor(0, 0, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            moveStickMan(stickManStart, stickMaxEnd, stickManSpeed);
            showingIntroFlag = 0;
        }
    } else if(key == 'r') {
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
    glutReshapeFunc(resize);
    glutKeyboardFunc(keypress);
    init();
    glutMainLoop();
}