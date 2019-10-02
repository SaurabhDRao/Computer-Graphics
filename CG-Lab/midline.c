#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float x0, y00, x1, y01;

void swap(float *a, float *b) {
	float t = *a;
	*a = *b;
	*b = t;
}

void init() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500, 500, -500, 500);
}

void plot(float x, float y) {
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
	glFlush();
}

void display() {
	glColor3f(1, 0, 0);
	float dx = abs(x1 - x0), dy = abs(y01 - y00), incrE, incrNE, incrY;
	int slopegt1 = 0;

	if(dy > dx) {
		swap(&x0, &y00);
		swap(&x1, &y01);
		swap(&dx, &dy);
		slopegt1 = 1;
	}
	if(x0 > x1) {
		swap(&x0, &x1);
		swap(&y00, &y01);
	}
	if(y00 > y01)
		incrY = -1;
	else
		incrY = 1;

	float d = 2 * dy - dx;
	incrE = 2 * dy;
	incrNE = 2 * (dy - dx);

	while(x0 < x1) {
		if(d <= 0)
			d += incrE;
		else {
			d += incrNE;
			y00 += incrY;
		}
		if(slopegt1)
			plot(y00, x0);
		else
			plot(x0, y00);
		++x0;
	}
	glFlush();
}

int main(int argc, char *argv[]) {
	printf("Enter the line co-ordinates (x0 y00 x1 y01): ");
	scanf("%f%f%f%f", &x0, &y00, &x1, &y01);

	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Midpoint Line");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}