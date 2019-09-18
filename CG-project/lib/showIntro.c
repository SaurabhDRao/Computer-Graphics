#include "drawChar.c"

void showIntro() {
    glColor3f(0.196078f,  0.6f, 0.8f);
    
    char names[3][20] = {
        "Sanchitha Kodgi",
        "Sanjana Nambiar",
        "Saurabh D Rao"
    };
    char usns[3][11] = {
        "4NM16CS130",
        "4NM16CS131",
        "4NM16CS132"
    };
    char projectTitle[] = "Ancient Humans";
    
    int COL_SPACE = 200, ROW_SPACE = 50;

    for(int i = 0; i < 3; ++i) {
        drawBitMapChar(usns[2 - i], 350, 300 + ROW_SPACE * i, 0);
        drawBitMapChar(names[2 - i], 350 + COL_SPACE, 300 + ROW_SPACE * i, 0);
        printf("%s %s\n", usns[2 - i], names[2 - i]);
    }

    glBegin(GL_POLYGON);
        glColor3f(0.05f, 0.05f, 0.05f);
        glVertex2i(100, 250);
        glVertex2i(900, 250);
        glVertex2i(900, 100);
        glVertex2i(100, 100);
    glEnd();

    glColor3f(1, 0, 0);    
    strokeChar(projectTitle, 150, 300 - ROW_SPACE * 1, 0);
}