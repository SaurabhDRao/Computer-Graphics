#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float theta;

GLfloat house[9][3] = {
    {200, 200, 1}, {300, 200, 1}, {300, 300, 1},
    {200, 300, 1}, {250, 400, 1}, {225, 200, 1},
    {275, 200, 1}, {275, 250, 1}, {225, 250, 1}
};

GLfloat rotMat[3][3], m, n, res[9][3], tx = 200, ty = 200;

void multiply() {
    for(int p = 0; p < 9; ++p) 
        for(int q = 0; q < 3; ++q) {
            res[p][q] = 0;
            for(int r = 0; r < 3; ++r) 
                res[p][q] += (house[p][r] * rotMat[r][q]);
        }
}

void roatate() {
    m = (-tx * cos(theta)) + (ty * sin(theta)) + tx;
    n = (-tx * sin(theta)) - (ty * cos(theta)) + ty;

    rotMat[0][0] = cos(theta);
    rotMat[0][1] = sin(theta);
    rotMat[0][2] = 0;
    rotMat[1][0] = -sin(theta);
    rotMat[1][1] = cos(theta);
    rotMat[1][2] = 0;
    rotMat[2][0] = m;
    rotMat[2][1] = n;
    rotMat[2][2] = 1;

    multiply();
}

void drawHouse(GLfloat mat[9][3], float r, float g, float b) {
    glBegin(GL_LINE_LOOP);
        glColor3f(r, g, b);
        glVertex2f(mat[0][0], mat[0][1]);
        glVertex2f(mat[1][0], mat[1][1]);
        glVertex2f(mat[2][0], mat[2][1]);
        glVertex2f(mat[3][0], mat[3][1]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(r, g, b);
        glVertex2f(mat[2][0], mat[2][1]);
        glVertex2f(mat[3][0], mat[3][1]);
        glVertex2f(mat[4][0], mat[4][1]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(r, g, b);
        glVertex2f(mat[5][0], mat[5][1]);
        glVertex2f(mat[6][0], mat[6][1]);
        glVertex2f(mat[7][0], mat[7][1]);
        glVertex2f(mat[8][0], mat[8][1]);
    glEnd();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouse(house, 1, 0, 0);
    roatate();
    drawHouse(res, 0, 0, 1);
    glFlush();
}

int main(int argc, char *argv[]) {
    printf("Enter the angle of rotation: ");
    scanf("%f", &theta);
    theta = (theta * 3.14) / 180;
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
}