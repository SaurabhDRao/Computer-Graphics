#include <stdio.h>
#include <GL/glut.h>

float t1 = 0, t2 = 1;
float x1, y1, x2, y2, x3, y3, x4, y4;
float p[4], q[4];
float xmin, ymin, xmax, ymax;

void init() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
    glFlush();
}

void lineClip(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1, dy = y2 - y1, t;
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for(int i = 0; i < 4; ++i) {
        t = q[i] / p[i];
        if((p[i] == 0) && (q[i] < 0))
            return;
        if((p[i] < 0) && ((t > t1) && (t < t2))) {
            t1 = t;
        } else if((p[i] > 0) && ((t > t1) && (t < t2))) {
            t2 = t;
        }
    }
    if(t1 < t2) {
        x3 = x1 + t1 * (x2 - x1);
        x4 = x1 + t2 * (x2 - x1);
        y3 = y1 + t1 * (y2 - y1);
        y4 = y1 + t2 * (y2 - y1);
        if(
            ((x3 >= xmin) && (x3 <= xmax) && (y3 >= ymin) && (y3 <= ymax)) &&
            ((x4 >= xmin) && (x4 <= xmax) && (y4 >= ymin) && (y4 <= ymax))
        ) {
            glColor3f(1, 0, 0);
            glBegin(GL_LINES);
                glVertex2f(x3, y3);
                glVertex2f(x4, y4);
            glEnd();
            glFlush();
        }
    }
}

void keypress(unsigned char key, int x, int y) {
    if(key == 'c') {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0, 0, 1);
        glBegin(GL_LINE_LOOP);
            glVertex2f(xmin, ymin);
            glVertex2f(xmax, ymin);
            glVertex2f(xmax, ymax);
            glVertex2f(xmin, ymax);
        glEnd();
        lineClip(x1, y1, x2, y2);
        printf("Line clipped!\n");
    }
}

int main(int argc, char *argv[]) {
    printf("(Clipping window parameters format: xMin, yMin, xMax, yMax)\n");
    printf("Enter the clipping window parameters: ");
    scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);

    printf("\n(Line co-ordinates format: x1, y1, x2, y2)\n");
    printf("Enter line co-ordinates: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Liang-Barsky");
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    init();
    glutMainLoop();
}