#include <GL/glut.h>
#include <math.h>
#define PI 3.14

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100;
	
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void drawFilledCircle(float x, float y, float radius){
	float twicePi = 2.0f * PI;
	
	glBegin(GL_POLYGON);
		for(float i = 0; i <= (twicePi); i += 0.01) { 
			glVertex2f(
                x + (radius * cos(i)), 
			    y + (radius * sin(i))
			);
		}
	glEnd();
}

void drawStickMan() {
    glColor3f(1, 1, 1);

    // face
    drawFilledCircle(100, 150, 25);

    // body
    glBegin(GL_POLYGON);
        // glVertex2i(100, 50);
        // glVertex2i(100, 150);
        glVertex2i(98, 50);
        glVertex2i(98, 150);
        glVertex2i(103, 150);
        glVertex2i(103, 50);
    glEnd();

    // hands
    glBegin(GL_POLYGON);
        // glVertex2i(100, 120);
        // glVertex2i(80, 75);
        glVertex2i(98, 120);
        glVertex2i(78, 75);
        glVertex2i(83, 75);
        glVertex2i(103, 120);
    glEnd();
    glBegin(GL_POLYGON);
        // glVertex2i(100, 120);
        // glVertex2i(120, 75);
        glVertex2i(98, 120);
        glVertex2i(118, 75);
        glVertex2i(123, 75);
        glVertex2i(103, 120);
    glEnd();

    // legs
    glBegin(GL_POLYGON);
        // glVertex2i(100, 50);
        // glVertex2i(65, 0);
        glVertex2i(98, 50);
        glVertex2i(63, 0);
        glVertex2i(68, 0);
        glVertex2i(103, 50);
    glEnd();
    glBegin(GL_POLYGON);
        // glVertex2i(100, 50);
        // glVertex2i(135, 0);
        glVertex2i(98, 50);
        glVertex2i(133, 0);
        glVertex2i(138, 0);
        glVertex2i(103, 50);
    glEnd();
}