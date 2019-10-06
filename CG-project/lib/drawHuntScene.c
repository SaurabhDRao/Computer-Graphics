#include <GL/glut.h>
#include "../headers/spearVar.h"
#include "drawSpear.c"

void drawHuntScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackgroundWithoutTree();

    if(!initDeerStructFlag) {
        deer[0].xStart = 1500;
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
        initDeerStructFlag = 1;
        flipDeerFlag = 1;
    }

    for(int i = 0; i < N_DEERS; ++i) {
        if(!spearKillFlag) {
            glPushMatrix();
            glTranslatef(spearX, spearY, 0);
            glRotatef(45, 0, 0, 1);
            glTranslatef(0 - spearX,0 - spearY, 0);
            drawSpear(spearX, spearY);
            glPopMatrix();
            spearX -= 3; 
            spearY -= 1;
        } else {
            glColor3ub(deer[i].r, deer[i].g, deer[i].b);
            glPushMatrix();
                glTranslatef(deer[i].xStart, deer[i].yStart, 0);
                glRotatef(180, 0, 1, 0);
                glTranslatef(0 - deer[i].xStart,0 - deer[i].yStart, 0);
                drawDeer(deer[i].xStart, deer[i].yStart, deer[i].displacement);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(spearX, spearY, 0);
                glRotatef(45, 0, 0, 1);
                glTranslatef(0 - spearX,0 - spearY, 0);
                drawSpear(spearX, spearY);
            glPopMatrix();
        }
        if(spearX - deer[i].xStart < 3) {
            deer[i].deadFlag = 1; 
            spearKillFlag = 1;
        }

        glColor3ub(deer[i].r, deer[i].g, deer[i].b);
        if(!deer[i].deadFlag) {    
            glPushMatrix();
            glTranslatef(deer[i].xStart, deer[i].yStart, 0);
            glRotatef(180, 0, 1, 0);
            glTranslatef(0 - deer[i].xStart,0 - deer[i].yStart, 0);
            drawDeer(deer[i].xStart, deer[i].yStart, deer[i].displacement);
            glPopMatrix();
        }
        if(deer[i].moveFlag && (!deer[i].deadFlag)) {
            if(flipDeerFlag) {
                updateDeerParams(&deer[i], 'R');
                if(deer[i].xStart < deer[i].xEnd)  {
                    deer[i].moveFlag = 0;
                }
            } else {
                if(deer[i].xStart < deer[i].xEnd) {
                    updateDeerParams(&deer[i], 'L');
                    if(deer[i].xStart >= deer[i].xEnd) {
                        deer[i].moveFlag = 0;
                    }
                }else {
                    updateDeerParams(&deer[i], 'R');
                    if(deer[i].xStart < deer[i].xEnd)  {
                        deer[i].moveFlag = 0;
                    }
                }
            }
        }
    }

    

    glutSwapBuffers();
}