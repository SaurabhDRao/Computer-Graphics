#include <stdio.h>
#include <GL/glut.h>

float x1, y1, x2, y2, x3, y3, x4, y4;

void swap(float *a, float *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void edgeDetect(float x1, float y1, float x2, float y2, int *le, int *re) {
    float x, mx;
    if((y2 - y1) < 0) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    if((y2 - y1) != 0) 
        mx = (x2 - x1) / (y2 - y1);
    else
        mx = (x2 - x1);
    x = x1;
    for(int i = y1; i <= y2; ++i) {
        if(x < (float) le[i])
            le[i] = (int) x;
        if(x > (float) re[i])
            re[i] = (int) x;
        x += mx;
    }
}

void plot(int x, int y) {
    glColor3f(0, 1, 0);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void scanLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    int le[500], re[500];
    for(int i = 0; i < 500; ++i) {
        le[i] = 500;
        re[i] = 0;
    }
    
    edgeDetect(x1, y1, x2, y2, le, re);
    edgeDetect(x2, y2, x3, y3, le, re);
    edgeDetect(x3, y3, x4, y4, le, re);
    edgeDetect(x4, y4, x1, y1, le, re);

    for(int y = 0; y < 500; ++y) {
        if(le[y] <= re[y])  
            for(int i = (int)le[y]; i <= (int) re[y]; ++i)
                plot(i, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
    scanLine(x1, y1, x2, y2, x3, y3, x4, y4);
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[]) {
    printf("Enter the polygon vertices: ");
    printf("\nEnter the first vertex (x, y): ");
    scanf("%f%f", &x1, &y1);
    printf("\nEnter the second vertex (x, y): ");
    scanf("%f%f", &x2, &y2);
    printf("\nEnter the third vertex (x, y): ");
    scanf("%f%f", &x3, &y3);
    printf("\nEnter the fourth vertex (x, y): ");
    scanf("%f%f", &x4, &y4);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scan Fill");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}