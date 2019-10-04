#include <GL/glut.h>
#include "circleFunctions.c"
#include "background.c"
#include "drawStickMan.c"
#include "drawSpearStickMan.c"
#include "../headers/flag.h"
#include "../headers/stickMan.h"
#include "../headers/deer.h"
#include "drawDeer.c"

void drawScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();

    if(!initStickManStructFlag) {
        for(int i = 0; i < N_STICKMANS; ++i) {
            initStickMan(&stickMan[i], i);
        }
        initStickManStructFlag = 1;
    }

    for(int i = 0; i < N_STICKMANS; ++i) {
        if(stickMan[i].type == 'n') {
            glColor3f(stickMan[i].r, stickMan[i].g, stickMan[i].b);
            drawStickMan(stickMan[i].xStart, stickMan[i].yStart, stickMan[i].displacement);
        } else if(stickMan[i].type == 's') {
            glColor3f(stickMan[i].r, stickMan[i].g, stickMan[i].b);
            drawSpearStickMan(stickMan[i].xStart, stickMan[i].yStart, stickMan[i].angle, stickMan[i].displacement);
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
                if (stickMan[i].angle < 90)
                    stickMan[i].angle += 3;
                else {
                    
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
        drawDeer(deer[i].xStart, deer[i].yStart, deer[i].displacement);
        if(deer[i].moveFlag) {
            if(deer[i].xStart < deer[i].xEnd) {
                updateDeerParams(&deer[i], 'L');
                if(deer[i].xStart > deer[i].xEnd) {
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

    // drawDeer(500, 20, 0);

    glutSwapBuffers();
}