#include <stdio.h>
#include <GL/glut.h>

float x, y, r;

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void writePixel(float x, float y) {
    glPointSize(1);
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void midpointCircle() {
    x = 0;
    y = r;
    double d = 5.0 / 4.0 - r;
    writePixel(x, y);
    while(y > x) {
        if(d < 0) 
            d += (2.0 * x + 3.0);
        else {
            d += (2.0 * (x - y) + 5.0);
            --y;
        }
        ++x;
        writePixel(x, y);
        writePixel(y, x);
        writePixel(y, -x);
        writePixel(x, -y);
        writePixel(-x, -y);
        writePixel(-y, -x);
        writePixel(-y, x);
        writePixel(-x, y);
        glFlush();
    }
}

int main(int argc, char *argv[]) {
    printf("Enter the radius: ");
    scanf("%f", &r);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Circle");
    init();
    glutDisplayFunc(midpointCircle);
    glutMainLoop();
}