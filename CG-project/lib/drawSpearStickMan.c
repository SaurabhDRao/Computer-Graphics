#include <GL/glut.h>

void drawSpearStickMan(float x, float y, float displacement) {
    // face
    drawFilledCircle(x, 150 + y, 25);

    // body
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x -2, 150 + y);
        glVertex2f(x + 3, 150 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();

    // hands
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120 + y);
        glVertex2f(x - 37 + displacement, 75 + y);
        glVertex2f(x - 32 + displacement, 75 + y);
        glVertex2f(x + 3, 120 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120 + y);
        glVertex2f(x + 32 - displacement, 75 + y);
        glVertex2f(x + 37 - displacement, 75 + y);
        glVertex2f(x + 3, 120 + y);
    glEnd();

    // legs
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x - 37 + displacement, 0 + y);
        glVertex2f(x - 32 + displacement, 0 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x + 32 - displacement, 0 + y);
        glVertex2f(x + 37 - displacement, 0 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();

    // spear
    glPushMatrix();

    glTranslatef(x, y + 75, 0.0);

    glRotatef(45.0, 0.0, 0.0,1.0);

    if(displacement < 37)
        glTranslatef(0 - (x + 25), 0 - (y + 75 + displacement), 0.0);
    else
        glTranslatef(0 - (x + 40), 0 - (y + 75 + displacement - (displacement / 5)), 0.0);

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(x - 2 + displacement, y + 20);
        glVertex2f(x + 2 + displacement, y + 20);
        glVertex2f(x + 2 + displacement, 150 + y);
        glVertex2f(x - 2 + displacement, 150 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x + 5 + displacement, 150 + y);
        glVertex2f(x + displacement, 180 + y);
        glVertex2f(x - 5 + displacement, 150 + y);
    glEnd();

    glPopMatrix();
}