#include <stdio.h>
#include <GL/glut.h>
#include "glutFuncs.c"
#include "lib/intro/showIntro.c"
#include "lib/circleFunctions.c"
#include "lib/background.c"
#include "lib/drawStickMan.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

float stickManStart = 0;
int stickMaxEnd = 1000;
float stickManSpeed = 3;
int showingIntroFlag = 1;
float displacement = 0;
int dirFlag = 1;

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    showIntro();
    glutSwapBuffers();
}

void updateStickManParams() {
    stickManStart += stickManSpeed;

    if(dirFlag)
        displacement += stickManSpeed;
    else
        displacement -= stickManSpeed;
    
    if(displacement > (37 * 2))
        dirFlag = 0;
    else if(displacement < 0)
        dirFlag = 1;
}

void drawScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    day();

    glColor3f(0.094, 0.063, 0.031);
    drawStickMan(stickManStart, displacement);
    updateStickManParams();

    glutSwapBuffers();
}

void keypress(unsigned char key, int x, int y) {
    if(key == 's') {
        if(showingIntroFlag) {
            glutPostRedisplay();
            glutDisplayFunc(drawScene);
            showingIntroFlag = 0;
        }
    } else if(key == 'r') {
        glutPostRedisplay();
        glutDisplayFunc(drawScene);
    } else if(key == 'q') {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("CG-Project");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keypress);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}