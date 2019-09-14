#include <stdio.h>
#include <GL/glut.h>

int x00, x01, y00, y01;

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void writePixel(int x, int y) {
    glPointSize(1);
    glBegin(GL_POINTS);
        glColor3f(0, 0, 0);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void display() {
    float dx = x01 - x00, dy = y01 - y00, d = 2 * dy - dx, incrE = dy, incrNE = dy - dx;
    int x = x00, y = y00;
    writePixel(x, y);
    while(x < x01) {
        if(d <= 0) {
            d = d + 2 * incrE;
            ++x;
        } else {
            d = d + 2 * incrNE;
            ++y;
            ++x;
        }
        writePixel(x, y);
    }
}

int main(int argc, char *argv[]) {
    printf("Enter the values: \n");
    printf("x0: "); scanf("%d", &x00);
    printf("y0: "); scanf("%d", &y00);
    printf("x1: "); scanf("%d", &x01);
    printf("y1: "); scanf("%d", &y01);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}