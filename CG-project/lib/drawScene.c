#include <GL/glut.h>
#include "circleFunctions.c"
#include "background.c"
#include "drawStickMan.c"
#include "drawSpearStickMan.c"
#include "../headers/flag.h"
#include "../headers/stickMan.h"
#include "../headers/deer.h"
#include "drawDeer.c"
#include "drawHuntScene.c"

float colors[N_STICKMANS][3];

void flipDeer() {
    for(int j = 0; j < N_DEERS; ++j) {
        deer[j].moveFlag = 1;
        deer[j].speed = 6;
    }
    flipDeerFlag = 1;
}

void drawScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackgroundWithTree();

    if(!initStickManStructFlag) {
        for(int i = 0; i < N_STICKMANS; ++i) {
            initStickMan(&stickMan[i], i);
            colors[i][0] = stickMan[i].r;
            colors[i][1] = stickMan[i].g;
            colors[i][2] = stickMan[i].b;
        }
        initStickManStructFlag = 1;
    }

    for(int i = 0; i < N_STICKMANS; ++i) {
        if(stickMan[i].type == 'n') {
            glColor3f(stickMan[i].r, stickMan[i].g, stickMan[i].b);
            drawStickMan(stickMan[i].xStart, stickMan[i].yStart, stickMan[i].displacement);
        } else if(stickMan[i].type == 's') {
            glColor3f(stickMan[i].r, stickMan[i].g, stickMan[i].b);
            drawSpearStickMan(stickMan[i].xStart, stickMan[i].yStart,
                stickMan[i].handX, stickMan[i].handY, stickMan[i].spearX, stickMan[i].spearY,
                stickMan[i].spearAngle, stickMan[i].displacement, colors[i]);
        }
        if(stickMan[i].moveFlag) {
            if(stickMan[i].xStart < stickMan[i].xEnd) {
                updateStickManParams(&stickMan[i], 'L');
                if(stickMan[i].xStart > stickMan[i].xEnd) {
                    stickMan[i].moveFlag = 0;
                }
            }else {
                updateStickManParams(&stickMan[i], 'R');
                if(stickMan[i].xStart < stickMan[i].xEnd)  {
                    stickMan[i].moveFlag = 0;
                }
            }
        } else {
            if (stickMan[i].type == 's') {
                stickMan[i].displacement = 0;
                if (!stickMan[i].spearLoweredFlag) {
                    stickMan[i].spearAngle += 3;
                    if (stickMan[i].spearAngle == 90)
                        stickMan[i].spearLoweredFlag = 1;
                } else {
                    flipDeer();
                    if(!stickMan[i].handRisedFlag) {
                        stickMan[i].handY += 2;
                        stickMan[i].spearAngle -= 0.2;
                        if(stickMan[i].handY > 85)
                            stickMan[i].handRisedFlag = 1;
                    } else if((stickMan[i].handX <= 50) && (stickMan[i].handMovedBackFlag != -1)) {
                        if(!stickMan[i].handMovedBackFlag)
                            stickMan[i].handX += 5;
                        else if(stickMan[i].handX > 0)
                            stickMan[i].handX -= 5;
                        else
                            stickMan[i].handMovedBackFlag = -1;

                        if(stickMan[i].handX == 50)
                            stickMan[i].handMovedBackFlag = 1;
                    } else if(stickMan[i].handMovedBackFlag == -1) {
                        stickMan[i].spearX += 10;
                        stickMan[i].spearY += 5;
                    }
                }
            }
        }
    }

    if(!initDeerStructFlag) {
        for(int i = 0; i < N_DEERS; ++i) {
            initDeer(&deer[i], i);
        }
        initDeerStructFlag = 1;
    }

    for(int i = 0; i < N_DEERS; ++i) {
        glColor3ub(deer[i].r, deer[i].g, deer[i].b);
        if(flipDeerFlag) {
            glPushMatrix();
            glTranslatef(deer[i].xStart, deer[i].yStart, 0);
            glRotatef(180, 0, 1, 0);
            glTranslatef(0 - deer[i].xStart,0 - deer[i].yStart, 0);
            drawDeer(deer[i].xStart, deer[i].yStart, deer[i].displacement);
            glPopMatrix();
        } else {
            drawDeer(deer[i].xStart, deer[i].yStart, deer[i].displacement);
        }
        if(deer[i].moveFlag) {
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

    // drawDeer(500, 20, 0);

    if(stickMan[2].spearX >= 1000) {
        initDeerStructFlag = 0;
        glutDisplayFunc(drawHuntScene);
        glutPostRedisplay();
    }

    glutSwapBuffers();
}