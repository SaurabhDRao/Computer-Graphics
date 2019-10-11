#include <GL/glut.h>
#include "drawSpear.c"

void drawDeerWithSpear(float x, float y, float spearY, float displacement) {
    // spear
    glPushMatrix();
    glTranslatef((x - 50), spearY, 0);
    glRotatef(135, 0, 0, 1);
    glTranslatef(0 - (x - 50),0 - spearY, 0);
    drawSpear((x - 50), spearY);
    glPopMatrix();

    glColor3ub(100, 0, 0);
    // body
    glBegin(GL_POLYGON);
        glVertex2f(x, 45 + y);
        glVertex2f(x + 3, 65 + y);
        glVertex2f((x - 100) - 3, 65 + y);
        glVertex2f((x - 95) - 3, 45 + y);
    glEnd();

    // neck
    glBegin(GL_POLYGON);
        glVertex2f(x + 3, 63 + y);
        glVertex2f(x + 3, 85 + y);
        glVertex2f(x - 3, 85 + y);
        glVertex2f(x - 3, 63 + y);
    glEnd();

    // head
    glBegin(GL_POLYGON);
        glVertex2f(x - 7, 85 + y);
        glVertex2f(x + 30, 85 + y);
        glVertex2f(x + 30, 90 + y);
        glVertex2f(x, 100 + y);
        glVertex2f(x - 15, 100 + y);
        glVertex2f(x - 7, 95 + y);
    glEnd();

    // horns
    // horn 1
    glBegin(GL_POLYGON);
        glVertex2f(x, 100 + y);
        glVertex2f(x - 3, 100 + y);
        glVertex2f(x - 25, 120 + y);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - 15, 112 + y);
        glVertex2f(x - 15, 111 + y);
        glVertex2f(x - 25, 105 + y);
        glVertex2f(x - 45, 111 + y);
        glVertex2f(x - 25, 105 + y);
    glEnd();
    // horn 2
    glBegin(GL_POLYGON);
        glVertex2f(x - 3, 100 + y);
        glVertex2f(x - 7, 100 + y);
        glVertex2f(x - 35, 120 + y);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - 25, 112 + y);
        glVertex2f(x - 25, 111 + y);
        glVertex2f(x - 30, 110 + y);
        glVertex2f(x - 55, 115 + y);
        glVertex2f(x - 30, 110 + y);
    glEnd();

    // front legs
    glBegin(GL_POLYGON);
        glVertex2f((x - 3) - 2, 50 + y);
        glVertex2f((x - 3) - 25 + displacement, 0 + y);
        glVertex2f((x - 3) - 20 + displacement, 0 + y);
        glVertex2f((x - 3) + 3, 50 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((x - 3) - 2, 50 + y);
        glVertex2f((x - 3) + 20 - displacement, 0 + y);
        glVertex2f((x - 3) + 25 - displacement, 0 + y);
        glVertex2f((x - 3) + 3, 50 + y);
    glEnd();

    // back legs
    glBegin(GL_POLYGON);
        glVertex2f((x - 95) - 2, 50 + y);
        glVertex2f((x - 95) - 25 + displacement, 0 + y);
        glVertex2f((x - 95) - 20 + displacement, 0 + y);
        glVertex2f((x - 95) + 3, 50 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((x - 95) - 2, 50 + y);
        glVertex2f((x - 95) + 20 - displacement, 0 + y);
        glVertex2f((x - 95) + 25 - displacement, 0 + y);
        glVertex2f((x - 95) + 3, 50 + y);
    glEnd();
}