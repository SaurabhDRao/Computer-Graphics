#include <stdio.h>
#include <GL/glut.h>

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1533, 845, 0);
}

void drawPoint(int x, int y) {
    glPointSize(5);
    glBegin(GL_POINTS);
        glColor3f(0, 0, 0);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawLine(int x, int y) {
    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2i(x - 50, y - 50);
        glVertex2i(x + 50, y + 50);
    glEnd();
    glFlush();
}

void drawTriangle(int x, int y) {
    glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 0.3);
        glVertex2i(x - 50, y -25);
        glVertex2i(x + 50, y - 25);
        glVertex2i(x, y + 50);
    glEnd();
    glFlush(); 
}

void drawStar(int x, int y) {
    glBegin(GL_TRIANGLES);
        glColor3f(0.3, 0.3, 1);
        glVertex2i(x - 50, y -25);
        glVertex2i(x + 50, y - 25);
        glVertex2i(x, y + 50);
        glVertex2i(x - 50, y + 25);
        glVertex2i(x + 50, y + 25);
        glVertex2i(x, y - 50);
    glEnd();
    glFlush();
}

void drawSquare(int x, int y) {
    glBegin(GL_POLYGON);
        glColor3f(0, 1, 0);
        glVertex2i(x - 50, y - 50);
        glVertex2i(x + 50, y - 50);
        glVertex2i(x + 50, y + 50);
        glVertex2i(x - 50, y + 50);
    glEnd();
    glFlush();
}

void drawPentagon(int x, int y) {
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex2i(x - 50, y - 40);
        glVertex2i(x + 50, y - 40);
        glVertex2i(x + 50, y + 40);
        glVertex2i(x, y + 100);
        glVertex2i(x - 50, y + 40);
    glEnd();
    glFlush();
}

void mouse(int btn, int state, int x, int y) {
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        drawPoint(x, y);
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        drawLine(x, y);
}

void keypress(unsigned char key, int x, int y) {
    if(key == 't' || key == 'T')
        drawTriangle(x, y);
    if(key == 's' || key == 'S')
        drawSquare(x, y);
    if(key == 'p' || key == 'P')
        drawPentagon(x, y);
    if(key == 'n' || key == 'N')
        drawStar(x, y);
    
    if(key == 'c' || key == 'C') {
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
    
    if(key == 'q' || key == 'Q')
        exit(0);
}

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(1533, 845);
    glutCreateWindow("Mouse and Keyboard Events");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keypress);
    glutMainLoop();
}