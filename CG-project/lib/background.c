#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
#include <stdlib.h>

float skyR = 0.4;
float skyG = 0.7;
float skyB = 1.0;
float changeRGB = 0.005;
int count = 0;

float getVal(float val) {
    return (val >= 0 ? val : 0);
}

void tree() {
    glColor3f(0.3, 0.1, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(800, 250);
        glVertex2f(875, 250);
        glVertex2f(875, 75);
        glVertex2f(800, 75);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(800,250);
        glVertex2f(700,250);
        glVertex2f(775,350);
        glVertex2f(725,350);
        glVertex2f(800,425);
        glVertex2f(750,425);
        glVertex2f(840,500);
        glVertex2f(925,425);
        glVertex2f(875,425);
        glVertex2f(950,350);
        glVertex2f(900,350);
        glVertex2f(975,250);
        glVertex2f(875,250);
    glEnd();

    glFlush();
}

void sun() {
    glColor3f(1.0, 1.0, 0.0);
    drawFilledCircle(500, 450, 25);
    glFlush();
}

void drawBackground() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // SKY
    glColor3f(skyR, skyG, skyB);
    glBegin(GL_POLYGON);
        glVertex2f(0,150);
        glVertex2f(1000,150);
        glVertex2f(1000,500);
        glVertex2f(0,500);
	glEnd();

    if(count < 50) {
        skyR -= changeRGB;
        skyG -= changeRGB;
        skyB -= changeRGB;
        count += 1;
    } else {
        skyR += changeRGB;
        skyG += changeRGB;
        skyB += changeRGB;
        count += 1;
        if(count == 100)
            count = 0;
    }

	// GROUND
	glColor3f(0.0,0.6,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0,150);
        glVertex2f(1000,150);
        glVertex2f(1000,0);
        glVertex2f(0,0);
	glEnd();
	glFlush();

	tree();
    sun();
}