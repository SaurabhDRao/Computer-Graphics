#include <GL/glut.h>

void drawCavePaintingStickMan(float x, float y,
    float spearX, float spearY, float angle, 
    float xDisp, float yDisp) {
    
    glColor3f(1, 1, 1);

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
        glVertex2f((x) - 37 + xDisp, 150 + y + yDisp);
        glVertex2f((x) - 32 + xDisp, 150 + y + yDisp);
        glVertex2f(x + 3, 120 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120 + y);
        glVertex2f(x + 32, 75 + y);
        glVertex2f(x + 37, 75 + y);
        glVertex2f(x + 3, 120 + y);
    glEnd();

    // legs
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x - 37, 0 + y);
        glVertex2f(x - 32, 0 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50 + y);
        glVertex2f(x + 32, 0 + y);
        glVertex2f(x + 37, 0 + y);
        glVertex2f(x + 3, 50 + y);
    glEnd();

    // spear
    glPushMatrix();

    glTranslatef((x - spearX + xDisp) - 30, y + 75 + yDisp + spearY, 0.0);

    glRotatef(angle, 0.0, 0.0,1.0);

    glScalef(1, 0.5, 0);

    glTranslatef(0 - ((x - spearX + xDisp) - 30), 0 - (y + 75 + yDisp + spearY), 0.0);

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f((x + spearX - 30) - 2 + xDisp, y + 20 + spearY + yDisp);
        glVertex2f((x + spearX - 30) + 2 + xDisp, y + 20 + spearY + yDisp);
        glVertex2f((x + spearX - 30) + 2 + xDisp, y + 150 + spearY + yDisp);
        glVertex2f((x + spearX - 30) - 2 + xDisp, y + 150 + spearY + yDisp);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((x + spearX - 30) + 5 + xDisp, y + 150 + spearY + yDisp);
        glVertex2f((x + spearX - 30) + xDisp, y + 180 + spearY + yDisp);
        glVertex2f((x + spearX - 30) - 5 + xDisp, y + 150 + spearY + yDisp);
    glEnd();

    glPopMatrix();

    glColor3f(1, 1, 1);
    // face
    drawFilledCircle(x, 150 + y, 25);
}