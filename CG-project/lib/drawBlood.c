#include <GL/glut.h>

void drawBlood(float x, float y) {
    glBegin(GL_POLYGON);
        glColor3ub(255, 99, 71);
        glVertex2f(x + 40, y + 5);
        glVertex2f(x + 45, y);
        glColor3ub(255, 0, 0);
        glVertex2f(x + 40, y - 5);
        glColor3ub(255, 99, 71);
        glVertex2f(x+ 35, y);
    glEnd();
}