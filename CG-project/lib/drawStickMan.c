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

void drawStickMan(float x, float displacement) {
    glColor3f(1, 1, 1);

    // face
    drawFilledCircle(x, 150, 25);

    // body
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50);
        glVertex2f(x -2, 150);
        glVertex2f(x + 3, 150);
        glVertex2f(x + 3, 50);
    glEnd();

    // hands
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex2f(x - 2, 120);
        glVertex2f(x - 37 + displacement, 75);
        glVertex2f(x - 32 + displacement, 75);
        glVertex2f(x + 3, 120);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 120);
        glVertex2f(x + 32 - displacement, 75);
        glVertex2f(x + 37 - displacement, 75);
        glVertex2f(x + 3, 120);
    glEnd();

    // legs
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50);
        glVertex2f(x - 37 + displacement, 0);
        glVertex2f(x - 32 + displacement, 0);
        glVertex2f(x + 3, 50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x - 2, 50);
        glVertex2f(x + 32 - displacement, 0);
        glVertex2f(x + 37 - displacement, 0);
        glVertex2f(x + 3, 50);
    glEnd();
}