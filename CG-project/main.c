#include <stdio.h>
#include <GL/glut.h>
#include "glutFuncs.c"
#include "lib/intro/showIntro.c"
#include "lib/drawScene.c"
#include "lib/drawCavePaintingScene.c"

#define WINDOW_WIDTH 1533
#define WINDOW_HEIGHT 845

int showingIntroFlag = 1;
int showingCavePainitingScene = 0;
int initStickManStructFlag = 0;
int initDeerStructFlag = 0;
int flipDeerFlag = 0;
float spearY = 650;
int spearKillFlag = 0;
int stopSpearFlag = 0;
float bloodY = 100;
float groundBlood = 0;
float distUntilDead = 100;

// for cave stickman
int handSpearMovementFlag = 0;
float xDisp = 0, yDisp = 0;

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
            showingCavePainitingScene = 0;
        }
    } else if(key == 'r') {
        if(showingCavePainitingScene) {
            xDisp = 0;
            yDisp = 0;
            handSpearMovementFlag = 0;
            glutPostRedisplay();
            glutDisplayFunc(drawCavePaintingScene);
        } else {
            initStickManStructFlag = 0;
            initDeerStructFlag = 0;
            flipDeerFlag = 0;
            spearY = 650;
            spearKillFlag = 0;
            stopSpearFlag = 0;
            bloodY = 100;
            groundBlood = 0;
            distUntilDead = 100;
            glutPostRedisplay();
            glutDisplayFunc(drawScene);
        }
    } else if(key == 'c') {
        if(showingIntroFlag) {
            glutPostRedisplay();
            glutDisplayFunc(drawCavePaintingScene);
            showingIntroFlag = 0;
            showingCavePainitingScene = 1;
        }
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