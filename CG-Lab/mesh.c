#include <GL/glut.h>

#define maxx 5
#define maxy 7
#define dx 25
#define dy 20

GLfloat x[maxx + 1] = {0}, y[maxy + 1] = {0}, x0 = 100, y0 = 100;
GLint i, j;

void init() {
    glClearColor(0, 0, 0, 0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 499, 0, 499);
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    
    for(i = 0; i <= maxx; ++i)
        x[i] = x0 + i * dx;
    for(j = 0; j <= maxy; ++j)
        y[j] = y0 + j * dy;

    for(i = 0; i < maxx; ++i) 
        for(j = 0; j < maxy; ++j) {
            glBegin(GL_LINE_LOOP);
                glVertex2f(x[i], y[j]);
                glVertex2f(x[i], y[j + 1]);
                glVertex2f(x[i + 1], y[j + 1]);
                glVertex2f(x[i + 1], y[j]);
            glEnd();
        }
    
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rectangular Mesh");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}