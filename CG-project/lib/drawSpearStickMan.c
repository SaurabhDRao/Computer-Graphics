#include <GL/glut.h>

void drawSpearStickMan(float x, float displacement) {
    // face
    drawFilledCircle(x, 150, 25);

    // body
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50);
        glVertex2f(x -2, 150);
        glVertex2f(x + 3, 150);
        glVertex2f(x + 3, 50);
    glEnd();

    // hands
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120);
        glVertex2f(x - 37 + displacement, 75);
        glVertex2f(x - 32 + displacement, 75);
        glVertex2f(x + 3, 120);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120);
        glVertex2f(x + 32 - displacement, 75);
        glVertex2f(x + 37 - displacement, 75);
        glVertex2f(x + 3, 120);
    glEnd();

    // legs
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50);
        glVertex2f(x - 37 + displacement, 0);
        glVertex2f(x - 32 + displacement, 0);
        glVertex2f(x + 3, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50);
        glVertex2f(x + 32 - displacement, 0);
        glVertex2f(x + 37 - displacement, 0);
        glVertex2f(x + 3, 50);
    glEnd();

    // spear
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(x + displacement, 20);
        glVertex2f(x - 37 + displacement, 75);
        glVertex2f(x - 37 - 40 + displacement, 75 + 55);
        glVertex2f(x - 32 - 40 + displacement, 75 + 55);
        glVertex2f(x - 32 + displacement, 75);
        glVertex2f(x + 5 + displacement, 20);
    glEnd();
}