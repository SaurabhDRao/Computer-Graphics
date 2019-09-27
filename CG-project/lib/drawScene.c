#include <GL/glut.h>
#include "circleFunctions.c"
#include "background.c"
#include "drawStickMan.c"
#include "drawSpearStickMan.c"

float stickManStart = 0;
float stickManEnd = 1100;
float spearStickManStart = 1000;
float spearStickManEnd = -100;
float stickManSpeed = 3;
float spearStickManSpeed = 3;
int showingIntroFlag = 1;
float stickManDisp = 0;
float spearStickManDisp = 0;
int stickManLimbFlag = 1;
int spearStickManLimbFlag = 1;

void updateStickManParams(char startDir) {
    if(startDir == 'L') {
        stickManStart += stickManSpeed;

        if(stickManLimbFlag)
            stickManDisp += stickManSpeed;
        else
            stickManDisp -= stickManSpeed;
        
        if(stickManDisp > (37 * 2))
            stickManLimbFlag = 0;
        else if(stickManDisp < 0)
            stickManLimbFlag = 1;
    } else {
        stickManStart -= stickManSpeed;

        if(stickManLimbFlag)
            stickManDisp -= stickManSpeed;
        else
            stickManDisp += stickManSpeed;
        
        if(stickManDisp > (37 * 2))
            stickManLimbFlag = 1;
        else if(stickManDisp < 0)
            stickManLimbFlag = 0;
    }
}

void updateSpearStickManParams(char startDir) {
    if(startDir == 'L') {
        spearStickManStart += spearStickManSpeed;

        if(spearStickManLimbFlag)
            spearStickManDisp += spearStickManSpeed;
        else
            spearStickManDisp -= spearStickManSpeed;
        
        if(spearStickManDisp > (37 * 2))
            spearStickManLimbFlag = 0;
        else if(spearStickManDisp < 0)
            spearStickManLimbFlag = 1;
    } else {
        spearStickManStart -= spearStickManSpeed;

        if(spearStickManLimbFlag)
            spearStickManDisp -= spearStickManSpeed;
        else
            spearStickManDisp += spearStickManSpeed;
        
        if(spearStickManDisp > (37 * 2))
            spearStickManLimbFlag = 1;
        else if(spearStickManDisp < 0)
            spearStickManLimbFlag = 0;
    }
}

void drawScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    day();

    glColor3f(0.094, 0.063, 0.031);
    if(stickManStart < stickManEnd) {
        drawStickMan(stickManStart, stickManDisp);
        updateStickManParams('L');
    } else {
        drawStickMan(stickManStart, stickManDisp);
        updateStickManParams('R');
    }

    glColor3f(0, 0, 0);
    if(spearStickManStart < spearStickManEnd) {
        drawSpearStickMan(spearStickManStart, spearStickManDisp);
        updateSpearStickManParams('L');
    } else {
        drawSpearStickMan(spearStickManStart, spearStickManDisp);
        updateSpearStickManParams('R');
    }

    glutSwapBuffers();
}