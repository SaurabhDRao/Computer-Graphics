#include <stdio.h>
#include <GL/glut.h>

#define dx 25
#define dy 20

int maxx, maxy, x0 = 100, y0 = 100, x[100] = {0}, y[100] = {0};

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void display() {
    glColor3f(1, 0, 0);

    for(int i = 0; i < maxx; ++i)
        x[i] = x0 + i * dx;
    for(int j = 0; j < maxy; ++j)
        y[j] = y0 + j * dy;
    
    for(int i = 0; i < maxx - 1; ++i) 
        for(int j = 0; j < maxy - 1; ++j) {
            glBegin(GL_LINE_LOOP);
                glVertex2f(x[i], y[j]);
                glVertex2f(x[i + 1], y[j]);
                glVertex2f(x[i + 1], y[j + 1]);
                glVertex2f(x[i], y[j + 1]);
            glEnd();
        }
    glFlush();
}

int main(int argc, char *argv[]) {
    printf("Enter the size of the mesh (maxX maxY): ");
    scanf("%d%d", &maxx, &maxy);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rectangular Mesh");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}