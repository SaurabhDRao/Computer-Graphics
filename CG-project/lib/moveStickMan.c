#include <GL/glut.h>
#include <math.h>
#include "drawStickMan.c"
#include "drawSpearStickMan.c"

void moveStickMan(float xStart, float xEnd, float speed) {
    float displacement = 0;
    int flag = 1;
    if(xStart < xEnd) {
        for(float i = xStart; i <= xEnd; i += speed) {
            glClear(GL_COLOR_BUFFER_BIT); 

            // glBegin(GL_POLYGON);
            //     glColor3f(0.95f, 0.95f, 0.95f);
            //     glVertex2f(0, 0);
            //     glVertex2f(1000, 0);
            //     glVertex2f(1000, 10);
            //     glVertex2f(0, 10);
            // glEnd();

            drawStickMan(i, displacement, 1, 1, 1);
            drawSpearStickMan(xEnd - i, displacement, 0, 0, 1);
            if(flag)
                displacement += speed;
            else
                displacement -= speed;
            
            if(displacement > (37 * 2))
                flag = 0;
            else if(displacement < 0)
                flag = 1;

            glFlush();
        }
    } else {
        for(float i = xStart; i >= xEnd; i -= speed) {
            glClear(GL_COLOR_BUFFER_BIT); 

            drawStickMan(i, displacement, 1, 1, 1);
            drawSpearStickMan(xStart - i, displacement, 0, 0, 1);
            if(flag)
                displacement -= speed;
            else
                displacement += speed;
            
            if(displacement > (37 * 2))
                flag = 1;
            else if(displacement < 0)
                flag = 0;

            glFlush();
        }
    }
}