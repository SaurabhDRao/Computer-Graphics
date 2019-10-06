#include <GL/glut.h>

void drawSpear(float x, float y) {
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(x - 65, y - 2);
        glVertex2f(x - 65, y + 2);
        glVertex2f(x + 65, y + 2);
        glVertex2f(x + 65, y - 2);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 65, y - 5);
        glVertex2f(x - 65, y + 5);
        glVertex2f(x - 95, y);
    glEnd();
}