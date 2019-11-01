#include "drawCavePaintingScene.c"

int s2Count = 0;

void scene_2() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    strokeChar("Scene 2: Cave Painting", 50, 300, 0);

    ++s2Count;

    if(s2Count > 100) {
        glutDisplayFunc(drawCavePaintingScene);
        glutPostRedisplay();
    }

    glutSwapBuffers();
}