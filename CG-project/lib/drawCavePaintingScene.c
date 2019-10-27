#include <GL/glut.h>
#include "../headers/caveStickManVars.h"
#include "drawCave.c"
#include "drawCavePaintingStickMan.c"
#include "drawPainting.c"

float ySpeed = 0.5;
float xSpeed = 0.2;

int paintingFlag = 0;

float paintingPointsX[10000] = {0}, paintingPointsY[10000] = {0};
int painingIndex = -1;

float PAINT_X = 40, PAINT_Y = 255;
float paintX = 40, paintY = 255;

void drawCavePaintingScene() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    drawCave();

    // drawPainting(30, 250, 50, 240);
    // drawPainting(130, 350, 150, 340);

    // glBegin(GL_LINES);
    //     glColor3f(0, 0, 0);
    //     glVertex2f(PAINT_X, PAINT_Y);
    //     glVertex2f(paintX, paintY);
    // glEnd();

    glBegin(GL_POINTS);
        for(int i = 0; i < painingIndex; ++i) {
            glColor3f(0, 0, 0);
            glVertex2f(paintingPointsX[i], paintingPointsY[i]);
        }
    glEnd();

    drawCavePaintingStickMan(100, 80, 20, 35, 45, xDisp, yDisp);

    if(paintingFlag == 0) {
        paintX -= xSpeed;
        paintY -= ySpeed;
        paintingPointsX[++painingIndex] = paintX;
        paintingPointsY[painingIndex] = paintY;
        yDisp -= ySpeed;
        xDisp -= xSpeed;
    } else if(paintingFlag == 1) {
        if(paintY < 240 && paintX < 30) {
            PAINT_X = paintX;
            PAINT_Y = paintY;
        }
        paintX += xSpeed;
        paintingPointsX[++painingIndex] = paintX;
        paintingPointsY[painingIndex] = paintY;
        xDisp += xSpeed;
    } else if(paintingFlag == 2) {
        if(paintX > 50) {
            PAINT_X = paintX;
            PAINT_Y = paintY;
        }
        paintX -= xSpeed;
        paintY += ySpeed;
        paintingPointsX[++painingIndex] = paintX;
        paintingPointsY[painingIndex] = paintY;
        xDisp -= xSpeed;
        yDisp += ySpeed;
    } else if(paintingFlag == 3) {
        if(paintY > 255) {
            PAINT_X = 30;
            PAINT_Y = 250;
            paintX = PAINT_X;
            paintY = PAINT_Y;
            xDisp = -10;
            yDisp = -5;
        }
        paintX += xSpeed;
        paintingPointsX[++painingIndex] = paintX;
        paintingPointsY[painingIndex] = paintY;
        xDisp += xSpeed;
    } else if(paintingFlag == 4) {
        if(paintX > 50) {
            PAINT_X = paintX;
            PAINT_Y = paintY;
        }
        paintX -= xSpeed;
        paintY -= ySpeed;
        paintingPointsX[++painingIndex] = paintX;
        paintingPointsY[painingIndex] = paintY;
        yDisp -= ySpeed;
        xDisp -= xSpeed;
    } else if(paintingFlag == 5) {
        if(paintY > 225) {
            PAINT_X = paintX;
            PAINT_Y = paintY;
        }
        paintX -= xSpeed;
        paintY += ySpeed;
        paintingPointsX[++painingIndex] = paintX;
        paintingPointsY[painingIndex] = paintY;
        yDisp += ySpeed;
        xDisp -= xSpeed;
    } else {
        xDisp = 10;
        yDisp = -50;
    }

    if((paintY < 240 && paintX < 30) && !paintingFlag)
        paintingFlag = 1;
    else if(paintX > 50 && (paintingFlag == 1)) 
        paintingFlag = 2;
    else if((paintY > 255) && (paintingFlag == 2))
        paintingFlag = 3;
    else if(paintX > 50 && (paintingFlag == 3)) 
        paintingFlag = 4;
    else if((paintY < 225) && (paintingFlag == 4))
        paintingFlag = 5;
    else if((paintY > 250) && (paintingFlag == 5)) 
        paintingFlag = 6;


    // if(handSpearMovementFlag)
    //     yDisp += ySpeed, xDisp += xSpeed, stopPaintingFlag = 1;
    // else
    //     yDisp -= ySpeed, xDisp -= xSpeed;
    
    // if(yDisp < (-25))
    //     handSpearMovementFlag = 1;
    // else if(yDisp > 0)
    //     handSpearMovementFlag = 0; 

    glutSwapBuffers();
}