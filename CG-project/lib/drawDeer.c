#include <GL/glut.h>

void drawDeer(float x, float y, float displacement) {
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
    glBegin(GL_POLYGON);
        glVertex2f(x, 100 + y);
        glVertex2f(x - 3, 100 + y);
        glVertex2f(x - 25, 120 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 3, 100 + y);
        glVertex2f(x - 7, 100 + y);
        glVertex2f(x - 35, 120 + y);
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

    // tail
    // glBegin(GL_POLYGON);
    //     glVertex2f((x - 95) - 3, 65 + y);
    //     glVertex2f((x - 95) - 3, 55 + y);
    //     glVertex2f((x - 95) - 20, 45 + y);
    //     glVertex2f((x - 95) - 20, 47 + y);
    // glEnd();
}