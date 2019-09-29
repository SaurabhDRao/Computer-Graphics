#ifndef HEADER
#define HEADER #include "circleFunctions.c"
#endif

void drawStickMan(float x, float y, float displacement) {
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
}