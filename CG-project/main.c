#include <stdio.h>
#include <GL/glut.h>
#include "lib/showIntro.c"
#include "lib/circleFunctions.c"
#include "lib/background.c"
#include "lib/drawStickMan.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

float stickManStart = 0;
int stickMaxEnd = 1000;
float stickManSpeed = 1;
int showingIntroFlag = 1;
float displacement = 0;
int flag = 1;

void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 500);
}

void timer( int value ) {
    glutTimerFunc( 5, timer, 0 );
    glutPostRedisplay();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    showIntro();
    glutSwapBuffers();
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 500);
}

void moveStickMan() {
    drawStickMan(stickManStart, displacement, 1, 1, 1);
    stickManStart += stickManSpeed;

    if(flag)
        displacement += stickManSpeed;
    else
        displacement -= stickManSpeed;
    
    if(displacement > (37 * 2))
        flag = 0;
    else if(displacement < 0)
        flag = 1;
}

void drawScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    day();

    moveStickMan();

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