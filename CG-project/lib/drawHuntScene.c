#include <GL/glut.h>

void drawHuntScene() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();

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

    glutSwapBuffers();
}