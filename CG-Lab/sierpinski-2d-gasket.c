#include <stdio.h>
#include <GL/glut.h>

int n;
float a[2] = {1, 1}, b[2] = {6, 1}, c[2] = {3.5, 5};

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 10, 0, 10);
}

void drawTrinagle(float a[], float b[], float c[]) {
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}

void divideTriangle(float a[], float b[], float c[], int k) {
    float ab[2], ca[2], bc[2];
    if(k > 0) {
        for(int i = 0; i < 2; ++i) {
            ab[i] = (a[i] + b[i]) / 2;
            bc[i] = (b[i] + c[i]) / 2;
            ca[i] = (c[i] + a[i]) / 2;
        }
        divideTriangle(a, ab, ca, k - 1);
        divideTriangle(b, bc, ab, k - 1);
        divideTriangle(c, ca, bc, k - 1);
    } else {
        drawTrinagle(a, b, c);
    }
}

void display() {
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        divideTriangle(a, b, c, n);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    printf("Enter the number of divisions: ");
    scanf("%d", &n);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Gasket");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}