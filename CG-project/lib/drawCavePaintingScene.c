#include <GL/glut.h>
#include "../headers/caveStickManVars.h"
#include "drawCave.c"
#include "drawCavePaintingStickMan.c"
#include "drawPainting.c"

float ySpeed = 0.5;
float xSpeed = 0.2;

void drawCavePaintingScene() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    drawCave();

    drawPainting(30, 250, 50, 240);
    drawPainting(130, 350, 150, 340);
    drawPainting(230, 380, 250, 370);
    drawPainting(330, 250, 350, 240);
    drawPainting(430, 300, 450, 290);
    drawPainting(100, 270, 120, 260);
    drawPainting(200, 330, 220, 320);
    drawPainting(300, 230, 320, 220);
    drawPainting(400, 300, 420, 290);
    drawPainting(500, 310, 520, 300);

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