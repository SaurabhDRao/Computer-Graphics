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
}