#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float theta;
GLfloat rotMat[3][3], res[9][3], m, n, tx, ty;

GLfloat house[9][3] = {
    {200, 200, 1}, {300, 200, 1}, {300, 300, 1},
    {200, 300, 1}, {250, 350, 1}, {225, 200, 1},
    {275, 200, 1}, {275, 250, 1}, {225, 250, 1}
};

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void multiply() {
    for(int p = 0; p < 9; ++p) 
        for(int q = 0; q < 3; ++q) {
            res[p][q] = 0;
            for(int r = 0; r < 3; ++r)
                res[p][q] += (house[p][r] * rotMat[r][q]);
        }
}

void rotate() {
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

void drawHouse(GLfloat mat[9][3]) {
    glBegin(GL_LINE_LOOP);
        glVertex2f(mat[0][0], mat[0][1]);
        glVertex2f(mat[1][0], mat[1][1]);
        glVertex2f(mat[2][0], mat[2][1]);
        glVertex2f(mat[3][0], mat[3][1]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(mat[2][0], mat[2][1]);
        glVertex2f(mat[3][0], mat[3][1]);
        glVertex2f(mat[4][0], mat[4][1]);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(mat[5][0], mat[5][1]);
        glVertex2f(mat[6][0], mat[6][1]);
        glVertex2f(mat[7][0], mat[7][1]);
        glVertex2f(mat[8][0], mat[8][1]);
    glEnd();
}

void display() {
    glColor3f(1, 0, 0);
    drawHouse(house);
    rotate();
    glColor3f(0, 0, 1);
    drawHouse(res);
    glFlush();
}

int main(int argc, char *argv[]) {
    printf("Enter the pivot point (x, y): ");
    scanf("%f%f", &tx, &ty);
    printf("Enter the angle of rotation: ");
    scanf("%f", &theta);
    theta = (3.14 * theta) / 180;

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House Rotation");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}