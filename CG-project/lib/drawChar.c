#include <string.h>

void drawBitMapChar(char *str, float x, float y, float z) {
    char *c;
    glRasterPos3f(x, y, z);
    for(c = str; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void strokeChar(char *str, int x, int y, int z) {
    char *c;
    glPushMatrix();
    glTranslatef(x + 130, y - 100, z);
	glScalef(0.3f, 0.5f, z);
  
    for (c = str; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , *c);
	}
    glPopMatrix();
}

/* 

---bit map fonts available---
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_HELVETICA_18
GLUT_BITMAP_TIMES_NEW_ROMAN_24

 */