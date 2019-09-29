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
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(x + displacement, 20 + y);
        glVertex2f(x - 37 + displacement, 75 + y);
        glVertex2f(x - 37 - 40 + displacement, 75 + 55 + y);
        glVertex2f(x - 32 - 40 + displacement, 75 + 55 + y);
        glVertex2f(x - 32 + displacement, 75 + y);
        glVertex2f(x + 5 + displacement, 20 + y);
    glEnd();
}