#ifndef HEADER
#define HEADER #include "circleFunctions.c"
#endif

void drawStickMan(float x, float displacement) {
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
}