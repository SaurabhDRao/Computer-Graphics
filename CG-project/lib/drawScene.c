#include <GL/glut.h>
#include "circleFunctions.c"
#include "background.c"
#include "drawStickMan.c"
#include "drawSpearStickMan.c"
#include "../headers/flag.h"

#define N 3

typedef struct {
    float xStart, xEnd, speed, displacement;
    int limbFlag, moveFlag;
    /* 
    ---stick man types---
    n - normal, s - spear
    */
    char type;
    float r, g, b;
} StickMan;

StickMan stickMan[N];
float xStarts[N] = { 100, 700, 0 };
float xEnds[N] = { 1100, -100, 1100 };
float speeds[N] = { 3, 3, 3 };
float displacements[N] = { 0, 0, 0 };
int limbFlags[N] = { 1, 1, 1 };
int moveFlags[N] = { 0, 0, 1 };
char types[N] = { 'n', 's', 's' };
float rs[N] = { 0.094, 0, 1 };
float gs[N] = { 0.063, 0, 1 };
float bs[N] = { 0.031, 0, 1 };

void initStickMan(StickMan *sm, int index) {
    sm->xStart = xStarts[index];
    sm->xEnd = xEnds[index];
    sm->speed = speeds[index];
    sm->displacement = displacements[index];
    sm->limbFlag = limbFlags[index];
    sm->moveFlag = moveFlags[index];
    sm->type = types[index];
    sm->r = rs[index];
    sm->g = gs[index];
    sm->b = bs[index];
}

void updateStickManParams(StickMan *sm, char startDir) {
    if(startDir == 'L') {
        sm->xStart += sm->speed;

        if(sm->limbFlag)
            sm->displacement += sm->speed;
        else
            sm->displacement -= sm->speed;
        
        if(sm->displacement > (37 * 2))
            sm->limbFlag = 0;
        else if(sm->displacement < 0)
            sm->limbFlag = 1;
    } else {
        sm->xStart -= sm->speed;

        if(sm->limbFlag)
            sm->displacement -= sm->speed;
        else
            sm->displacement += sm->speed;
        
        if(sm->displacement > (37 * 2))
            sm->limbFlag = 1;
        else if(sm->displacement < 0)
            sm->limbFlag = 0;
    }
}

void drawScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();

    if(!initStickManStructFlag) {
        for(int i = 0; i < N; ++i) {
            initStickMan(&stickMan[i], i);
        }
        initStickManStructFlag = 1;
    }

    for(int i = 0; i < N; ++i) {
        if(stickMan[i].type == 'n') {
            glColor3f(stickMan[i].r, stickMan[i].g, stickMan[i].b);
            drawStickMan(stickMan[i].xStart, stickMan[i].displacement);
        } else if(stickMan[i].type == 's') {
            glColor3f(stickMan[i].r, stickMan[i].g, stickMan[i].b);
            drawSpearStickMan(stickMan[i].xStart, stickMan[i].displacement);
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
        }
    }


    glutSwapBuffers();
}