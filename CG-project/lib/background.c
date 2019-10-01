#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
#include <stdlib.h>

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
    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
        glColor3ub(173, 216, 230);
        glVertex2f(0,150);
        glVertex2f(1000,150);
        glColor3ub(100, 149, 237);
        glVertex2f(1000,500);
        glVertex2f(0,500);
	glEnd();

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