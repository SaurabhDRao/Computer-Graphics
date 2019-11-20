#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float x00, y00, x01, y01;

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

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
    float dx = abs(x01 - x00), dy = abs(y01 - y00);
    int slopegt1 = 0;

    if(dy > dx) {
        swap(&x00, &y00);
        swap(&x01, &y01);
        swap(&dx, &dy);
        slopegt1 = 1;    
    }
    if(x00 > x01) {
        swap(&x00, &x01);
        swap(&y00, &y01);
    }

    float incrY = 1;
    if(y00 > y01) 
        incrY = -1;
        
    float d = 2 * dy - dx;
    float incrE = 2 * dy;
    float incrNE = 2 * (dy - dx);
    
    while(x00 < x01) {
        if(d <= 0)
            d += incrE;
        else {
            d += incrNE;
            y00 += incrY;
        }
        if(slopegt1)
            plot(y00, x00);
        else 
            plot(x00, y00);
        ++x00;
    }
    glFlush();
}

int main(int argc, char *argv[]) {
    printf("Enter the line co-ordinates (x00 y00 x01 y01): ");
    scanf("%f%f%f%f", &x00, &y00, &x01, &y01);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint-Line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}