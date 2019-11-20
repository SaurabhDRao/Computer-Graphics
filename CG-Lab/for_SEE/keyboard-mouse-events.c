#include <GL/glut.h>

int WIDTH = 1533, HEIGHT = 845;

void init() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

void drawPoint(int x, int y) {
    glPointSize(5);
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
} 

void drawLine(int x, int y) {
    glLineWidth(5);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(x - 50, y - 50);
        glVertex2f(x + 50, y + 50);
    glEnd();
    glFlush();
}

void drawTriangle(int x, int y) {
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 50, y - 25);
        glVertex2f(x + 50, y - 25);
        glVertex2f(x, y + 50);
    glEnd();
    glFlush();
}

void drawSquare(int x, int y) {
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(x - 50, y - 50);
        glVertex2f(x + 50, y - 50);
        glVertex2f(x + 50, y + 50);
        glVertex2f(x - 50, y + 50);
    glEnd();
    glFlush();
}

void drawPentagon(int x, int y) {
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(x - 50, y - 40);
        glVertex2f(x + 50, y - 40);
        glVertex2f(x + 50, y + 40);
        glVertex2f(x, y + 80);
        glVertex2f(x - 50, y + 40);
    glEnd();
    glFlush();
}

void drawStar(int x, int y) {
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 50, y - 25);
        glVertex2f(x + 50, y - 25);
        glVertex2f(x, y + 50);
        glVertex2f(x - 50, y + 25);
        glVertex2f(x + 50, y + 25);
        glVertex2f(x, y - 50);
    glEnd();
    glFlush();
}

void mouseclick(int btn, int state, int x, int y) {
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        drawPoint(x, y);
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        drawLine(x, y);
}

void keypress(unsigned char key, int x, int y) {
    if(key == 't' || key == 'T')
        drawTriangle(x, y);
    else if(key == 's' || key == 'S')
        drawSquare(x, y);
    else if(key == 'p' || key == 'P')
        drawPentagon(x, y);
    else if(key == 'n' || key == 'N')
        drawStar(x, y);

    if(key == 'c' || key == 'C') {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Events");
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    glutMouseFunc(mouseclick);
    init();
    glutMainLoop();
}