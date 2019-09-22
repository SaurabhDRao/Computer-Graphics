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