#include <stdio.h>
#include <GL/glut.h>
#include "glutFuncs.c"
#include "lib/intro/showIntro.c"
#include "lib/drawScene.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    showIntro();
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