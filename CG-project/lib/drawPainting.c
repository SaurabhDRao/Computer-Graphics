#include <GL/glut.h>

void drawPainting(int xStart, int yStart, int xEnd, int yEnd) {
    glColor3ub(50, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xStart, yStart);
        glVertex2f(xEnd, yStart);
        glVertex2f((xStart + xEnd) / 2, yEnd);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f((xStart + xEnd) / 2, yEnd);
        glVertex2f(xStart, yStart - ((yStart - yEnd) * 2));
        glVertex2f(xEnd, yStart - ((yStart - yEnd) * 2));
    glEnd();
    drawHollowCircle((xStart + xEnd) / 2, yStart + 5, 5);
    glBegin(GL_LINES);
        glVertex2f(xStart + 3, yStart - 3);
        glVertex2f(xStart + 3, yStart -10);
        glVertex2f(xEnd - 3, yStart - 3);
        glVertex2f(xEnd - 3, yStart - 10);

        glVertex2f(xStart + 5, yStart - ((yStart - yEnd) * 2));
        glVertex2f(xStart + 5, yStart - ((yStart - yEnd) * 2) - 10);
        glVertex2f(xEnd - 5, yStart - ((yStart - yEnd) * 2));
        glVertex2f(xEnd - 5, yStart - ((yStart - yEnd) * 2) - 10);
    glEnd();

    //Drawings
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(400, 250);
        glVertex2f(420, 250);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(400, 250);
        glVertex2f(400, 240);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(420, 250);
        glVertex2f(420, 240);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(420, 250);
        glVertex2f(425, 255);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(425, 255);
        glVertex2f(430, 255);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(425, 255);
        glVertex2f(422, 252);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(400, 250);
        glVertex2f(395, 254);
    glEnd();

    //Drawing person
    glBegin(GL_LINE_LOOP);
        glColor3f(0,0,0);
        glVertex2f(380, 270);
        glVertex2f(380, 280);
        glVertex2f(390, 280);
        glVertex2f(390, 270);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(385, 270);
        glVertex2f(385, 255);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(378, 265);
        glVertex2f(392, 265);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(385, 255);
        glVertex2f(380, 245);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(385, 255);
        glVertex2f(390, 245);
    glEnd();
}