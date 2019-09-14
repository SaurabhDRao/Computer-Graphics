#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int x00, x01, y00, y01;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int sign(int a) {
    return (a > 0) ? 1 : ((a < 0) ? -1 : 0);
}

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void plot(int x, int y) {
    glPointSize(1);
    glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void display() {
    int dy = abs(y01 - y00), dx = abs(x01 - x00), x, y;
    float m = (float) (y01 - y00) / (x01 - x00);

    if(y00 == y01) {
        x = min(x00, x01);
        y = y00;
        while(x <= max(x00, x01)) {
            plot(x, y);
            ++x;
        }
    } else if(x00 == x01) {
        y = min(y00, y01);
        x = x00;
        while(y <= max(y00, y01)) {
            plot(x, y);
            ++y;
        }
    } else if(dx == dy) {
        x = x00;
        y = y00;
        do {
            plot(x, y);
            x += sign(x01 - x00);
            y += sign(y01 - y00);
        } while((x != x01) && (y != y01));
        plot(x, y);
    } else {
        if(((m > 0) && (m < 1)) || ((m < 0) && (m > -1))) {
            int d = 2 * dy - dx;
            x = min(x00, x01);
            if((m < 0) && (m > -1))
                y = max(y00, y01);
            else
                y = min(y00, y01);
            plot(x, y);
            while(x < max(x00, x01)) {
                if(d <= 0) {
                    d += (2 * dy);
                } else {
                    d += (2 * (dy - dx));
                    if((m < 0) && (m > -1))
                        --y;
                    else 
                        ++y;
                }
                ++x;
                plot(x, y);
            }
        } else if((m > 1) || (m < -1)) {
            int d = 2 * dx - dy;
            if(m < -1)
                x = max(x00, x01);
            else
                x = min(x00, x01);
            y = min(y00, y01);
            plot(x, y);
            while(y < max(y00, y01)) {
                if(d <= 0) {
                    d += (2 * dx);
                } else {
                    d += (2 * (dx - dy));
                    if(m < -1)
                        --x;
                    else
                        ++x;
                }
                ++y;
                plot(x, y);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    printf("Enter the values: \n");
    printf("x0: "); scanf("%d", &x00);
    printf("y0: "); scanf("%d", &y00);
    printf("x1: "); scanf("%d", &x01);
    printf("y1: "); scanf("%d", &y01);
    printf("\n");

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}