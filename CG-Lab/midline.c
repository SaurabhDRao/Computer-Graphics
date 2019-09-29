#include <GL/glut.h>
#include <stdio.h>

float x1,y1,x0,y0;

void swap(float *a,float *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void writepixel(float x,float y)
{
	glPointSize(1);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}

void init()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-500,500,-500,500);
	glColor3f(1,0,0);
}


 
void midpointline()
{
	float dx,dy,d,incry,incre,incrne,slopegt1=0;
	dx=abs(x0-x1);dy=abs(y0-y1);
	if(dy>dx)
	{
		swap(&x0,&y0);
		swap(&x1,&y1);
		swap(&dx,&dy);
		slopegt1=1;
	}
	if(x0>x1)
	{
		swap(&x0,&x1);
		swap(&y0,&y1);
	}
	if(y0>y1)
		incry=-1;
	else
		incry=1;
	d=2*dy-dx;
	incre=2*dy;
	incrne=2*(dy-dx);
	while(x0<x1)
	{
		if(d<=0)
			d+=incre;
		else
		{
			d+=incrne;
			y0+=incry;
		}
		x0++;
		if(slopegt1)
			writepixel(y0,x0);
		else
			writepixel(x0,y0);
	}
	glFlush();
}

int main(int argc,char **argv)
{

	printf("Enter coordinates:");
	scanf("%f%f%f%f",&x0,&y0,&x1,&y1);
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Mid Line");
	init();
	glutDisplayFunc(midpointline);
	glutMainLoop();

	return 0;
}