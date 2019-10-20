#include <GL/glut.h>
#include "../headers/caveStickManVars.h"
#include "drawCave.c"
#include "drawCavePaintingStickMan.c"

float ySpeed = 0.5;
float xSpeed = 0.2;

void drawCavePaintingScene() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    drawCave();

    drawCavePaintingStickMan(100, 80, 20, 35, 45, xDisp, yDisp);

    if(handSpearMovementFlag)
        yDisp += ySpeed, xDisp += xSpeed;
    else
        yDisp -= ySpeed, xDisp -= xSpeed;
    
    if(yDisp < (-25))
        handSpearMovementFlag = 1;
    else if(yDisp > 0)
        handSpearMovementFlag = 0; 

    glutSwapBuffers();
}