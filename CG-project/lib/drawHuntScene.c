#include <GL/glut.h>
#include "../headers/vars.h"
#include "drawDeerWithSpear.c"
#include "drawBlood.c"
#include "scene_2.c"

void drawHuntScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackgroundWithoutTree();

    if(!initDeerStructFlag) {
        deer[0].xStart = 1300;
        deer[0].xEnd = -100;
        deer[0].speed = 6;
        deer[0].moveFlag = 1;
        
        deer[1].xStart = 1100;
        deer[1].xEnd = -100;
        deer[1].speed = 6;
        deer[1].moveFlag = 1;
        
        deer[2].xStart = 1000;
        deer[2].xEnd = -100;
        deer[2].speed = 6;
        deer[2].moveFlag = 1;

        deer[3].xStart = 1050;
        deer[3].xEnd = -100;
        deer[3].speed = 6;
        deer[3].moveFlag = 1;
        
        deer[4].xStart = 1130;
        deer[4].xEnd = -100;
        deer[4].speed = 6;
        deer[4].moveFlag = 1;

        initDeerStructFlag = 1;
        flipDeerFlag = 1;
    }

    for(int i = 0; i < 5; ++i) {
        glColor3ub(deer[i].r, deer[i].g, deer[i].b);
        if((i == 0)) {
            glPushMatrix();
            glTranslatef(deer[i].xStart, deer[i].yStart, 0);
            glRotatef(180, 0, 1, 0);
            glTranslatef(0 - deer[i].xStart,0 - deer[i].yStart, 0);
            drawDeerWithSpear(deer[i].xStart, deer[i].yStart, spearY, deer[i].displacement);
            glPopMatrix();
            if((spearY - deer[i].yStart) < 80) {
                stopSpearFlag = 1;
                deer[i].speed = 0.5;
                distUntilDead -= 0.5;
            }
            if (!stopSpearFlag)
                spearY -= 6;
            if(!distUntilDead)
                deer[i].deadFlag = 1;
        } else {
            glPushMatrix();
            glTranslatef(deer[i].xStart, deer[i].yStart, 0);
            glRotatef(180, 0, 1, 0);
            glTranslatef(0 - deer[i].xStart,0 - deer[i].yStart, 0);
            drawDeer(deer[i].xStart, deer[i].yStart, deer[i].displacement);
            glPopMatrix();
        }
        if(deer[i].moveFlag && !deer[i].deadFlag) {
            updateDeerParams(&deer[i], 'R');
            if(deer[i].xStart < deer[i].xEnd)  {
                deer[i].moveFlag = 0;
            }
        }
    }

    if(stopSpearFlag) {
        if(bloodY - deer[0].yStart > 7) {
            drawBlood(deer[0].xStart, bloodY);
            drawBlood(deer[0].xStart - 3, bloodY - 7);
            drawBlood(deer[0].xStart + 3, bloodY - 15);
            // drawBlood(deer[0].xStart - 3, bloodY - 15);
            // drawBlood(deer[0].xStart + 3, bloodY - 15);
            // drawBlood(deer[0].xStart - 7, bloodY - 20);
            // drawBlood(deer[0].xStart + 7, bloodY - 20);
            bloodY -= 0.5;
        } else {
            bloodY = 100;
            if(deer[0].deadFlag)
                groundBlood += 5;
        }
        if(deer[0].deadFlag) {
            glColor3f(1, 0, 0);
            glBegin(GL_POLYGON);
                glVertex2f((deer[0].xStart + 40) - groundBlood, deer[0].yStart);
                glVertex2f((deer[0].xStart + 40) - groundBlood, deer[0].yStart - 3);
                glVertex2f((deer[0].xStart + 40) + groundBlood, deer[0].yStart - 3);
                glVertex2f((deer[0].xStart + 40) + groundBlood, deer[0].yStart);
            glEnd();
        }
        if(groundBlood == 20) {
            glutDisplayFunc(scene_2);
            glutPostRedisplay();
        }
    }

    glutSwapBuffers();
}