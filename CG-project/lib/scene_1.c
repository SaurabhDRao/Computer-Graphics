#include "drawScene.c"

int s1Count = 0;

void scene_1() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);    
    strokeChar("Scene 1: Hunting", 150, 300, 0);

    ++s1Count;

    if(s1Count > 100) {
        glutDisplayFunc(drawScene);
        glutPostRedisplay();
    }

    glutSwapBuffers();
}