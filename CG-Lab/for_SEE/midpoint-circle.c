#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float h, k, r;

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void plot(float x, float y) {
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void display() {
    float x = 0, y = r, d = 5.0 / 4.0 - r;
    while(y > x) {
        if(d < 0)
            d += (2 * x + 3);
        else {
            d += (2 * (x - y) + 5);
            --y;
        }
        ++x;
        plot(x + h, y + k);
        plot(-x + h, y + k);
        plot(x + h, -y + k);
        plot(-x + h, -y + k);
        plot(y + h, x + k);
        plot(-y + h, x + k);
        plot(y + h, -x + k);
        plot(-y + h, -x + k);
    }
    glFlush();
}

int main(int argc, char *argv[]) {
    printf("Enter the centre of the circle (x, y): ");
    scanf("%f%f", &h, &k);
    printf("Enter the radius: ");
    scanf("%f", &r);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint-Circle");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}