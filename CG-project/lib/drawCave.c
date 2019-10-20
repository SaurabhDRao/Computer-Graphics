#include <GL/glut.h>

void drawCave() {
    // glBegin(GL_POLYGON);
    //     glColor3ub(255, 255, 200);
    //     glVertex2f(0, 500);
    //     glColor3ub(255, 255, 200);
    //     glVertex2f(500, 500);
    //     glVertex2f(560, 400);
    //     glVertex2f(520, 350);
    //     glVertex2f(540, 320);
    //     glVertex2f(500, 300);
    //     glVertex2f(550, 270);
    //     glVertex2f(480, 230);
    //     glVertex2f(560, 220);
    //     glVertex2f(500, 190);
    //     glVertex2f(580, 170);
    //     glVertex2f(660,50);
    //     glColor3ub(255, 69, 0);
    //     glVertex2f(0,50);
    // glEnd();

    // wall
    glBegin(GL_POLYGON);
        glColor3ub(255, 99, 71);
        glVertex2f(0, 100);
        glColor3f(1, 1, 1);
        glVertex2f(0, 500);
        glVertex2f(1000, 500);
        glVertex2f(1000, 0);
    glEnd();

    // painting platform
    glColor3ub(50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(0, 100);
        glVertex2f(1000, 100);
        glVertex2f(1000, 0);
    glEnd();

    // cave roof 
    glColor3ub(50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2f(0, 500);
        glVertex2f(0, 450);
        glVertex2f(1000, 450);
        glVertex2f(1000, 500);
    glEnd();

    // base black
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(0, 50);
        glVertex2f(1000, 50);
        glVertex2f(1000, 0);
    glEnd();
    // some triangles
    glBegin(GL_POLYGON);
        glVertex2f(0, 50);
        glVertex2f(80, 80);
        glVertex2f(150, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(150, 50);
        glVertex2f(400, 200);
        glVertex2f(500, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(400, 150);
        glVertex2f(500, 200);
        glVertex2f(550, 50);
        glVertex2f(400, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(450, 70);
        glVertex2f(600, 240);
        glVertex2f(720, 50);
        glVertex2f(520, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(690, 50);
        glVertex2f(690, 500);
        glVertex2f(1000, 500);
        glVertex2f(1000, 50);
    glEnd();

    // roof triangles
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(0, 500);
        glVertex2f(30, 440);
        glVertex2f(60, 500);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(100, 500);
        glVertex2f(130, 400);
        glVertex2f(160, 500);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(200, 500);
        glVertex2f(230, 390);
        glVertex2f(260, 500);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(400, 500);
        glVertex2f(430, 360);
        glVertex2f(460, 500);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(550, 500);
        glVertex2f(580, 300);
        glVertex2f(660, 500);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0, 500);
        glVertex2f(0, 470);
        glVertex2f(1000, 420);
        glVertex2f(1000, 500);
    glEnd();

    glFlush();

}