#include <stdio.h>
#include <GL/glut.h>

void display();

float xmin, ymin, xmax, ymax, lx0, ly0, lx1, ly1;
int TOP = 8, BOTTOM = 4, RIGHT = 2, LEFT = 1;

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

int getOutcode(float x, float y) {
    int c = 0;
    if(y > ymax)
        c = TOP;
    if(y < ymin)
        c = BOTTOM;
    if(x > xmax)
        c |= RIGHT;
    if(x < xmin)
        c |= LEFT;
    return c;
}

void clipLine(float x1, float y1, float x2, float y2) {
    int outcode1 = getOutcode(x1, y1);
    int outcode2 = getOutcode(x2, y2);
    float m = (y2 - y1) / (x2 - x1);

    while((outcode1 | outcode2) != 0) {
        if((outcode1 & outcode2) != 0) {
            lx0 = ly0 = lx1 = ly1 = -500;
            break;
        }

        float x, y;
        float xi = x1, yi = y1;
        int c = outcode1;
        if(c == 0) {
            xi = x2;
            yi = y2;
            c = outcode2;
        }

        if((c & TOP) != 0) {
            y = ymax;
            x = xi + 1.0 / m * (ymax - yi);
        } else if((c & BOTTOM) != 0) {
            y = ymin;
            x = xi + 1.0 / m * (ymin - yi);
        } else if((c & RIGHT) != 0) {
            x = xmax;
            y = yi + m * (xmax - xi);
        } else if((c & LEFT) != 0) {
            x = xmin;
            y = yi + m * (xmin - xi);
        }
        if(c == outcode1) {
            lx0 = x;
            ly0 = y;
            outcode1 = getOutcode(lx0, ly0);
        }
        if(c == outcode2) {
            lx1 = x;
            ly1 = y;
            outcode2 = getOutcode(lx1, ly1);
        }
    }
    display();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  
    
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex2f(lx0, ly0);
        glVertex2f(lx1, ly1);
    glEnd();
    glFlush();
}

void keypress(unsigned char key, int x, int y) {
    if(key == 'c') {
        clipLine(lx0, ly0, lx1, ly1);
        printf("Line clipped!\n");
        glFlush();
    }
}

int main(int argc, char *argv[]) {
    printf("(Clipping window parameters format: xMin, yMin, xMax, yMax)\n");
    printf("Enter the clipping window parameters: ");
    scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);

    printf("\n(Line co-ordinates format: x0, y0, x1, y1)\n");
    printf("Enter line co-ordinates: ");
    scanf("%f%f%f%f", &lx0, &ly0, &lx1, &ly1);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cohen-Sutherland");
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    init();
    glutMainLoop();
}