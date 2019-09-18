#include <GL/glut.h>

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    printf("%d %d %f\n", width, height, aspect);

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset the projection matrix
    if (width >= height) {
        // aspect >= 1, set the height from -1 to 1, with larger width
        gluOrtho2D(0, 600.0 * aspect, 0, 600.0);
    } else {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(0, 600.0, 0, 600.0 / aspect);
    }
}