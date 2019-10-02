#define N_STICKMANS 3

typedef struct {
    float xStart, xEnd, yStart, speed, displacement;
    int limbFlag, moveFlag;
    /* 
    ---stick man types---
    n - normal, s - spear
    */
    char type;
    float r, g, b;
} StickMan;

StickMan stickMan[N_STICKMANS];
float sticmManXStarts[N_STICKMANS] = { 100, 700, 1000 };
float sticmManXEnds[N_STICKMANS] = { 1100, -100, -100 };
float sticmManYStarts[N_STICKMANS] = { 50, 40, 30 };
float sticmManSpeeds[N_STICKMANS] = { 3, 3, 3 };
float sticmManDisps[N_STICKMANS] = { 0, 0, 0 };
int sticmManLimbFlags[N_STICKMANS] = { 1, 1, 1 };
int sticmManMoveFlags[N_STICKMANS] = { 0, 0, 1 };
char sticmManTypes[N_STICKMANS] = { 'n', 's', 's' };
float sticmManRs[N_STICKMANS] = { 0.094, 0, 1 };
float sticmManGs[N_STICKMANS] = { 0.063, 0, 1 };
float sticmManBs[N_STICKMANS] = { 0.031, 0, 1 };

void initStickMan(StickMan *sm, int index) {
    sm->xStart = sticmManXStarts[index];
    sm->xEnd = sticmManXEnds[index];
    sm->yStart = sticmManYStarts[index];
    sm->speed = sticmManSpeeds[index];
    sm->displacement = sticmManDisps[index];
    sm->limbFlag = sticmManLimbFlags[index];
    sm->moveFlag = sticmManMoveFlags[index];
    sm->type = sticmManTypes[index];
    sm->r = sticmManRs[index];
    sm->g = sticmManGs[index];
    sm->b = sticmManBs[index];
}

void updateStickManParams(StickMan *sm, char startDir) {
    if(startDir == 'L') {
        sm->xStart += sm->speed;

        if(sm->limbFlag)
            sm->displacement += sm->speed;
        else
            sm->displacement -= sm->speed;
        
        if(sm->displacement > (37 * 2))
            sm->limbFlag = 0;
        else if(sm->displacement < 0)
            sm->limbFlag = 1;
    } else {
        sm->xStart -= sm->speed;

        if(sm->limbFlag)
            sm->displacement -= sm->speed;
        else
            sm->displacement += sm->speed;
        
        if(sm->displacement > (37 * 2))
            sm->limbFlag = 1;
        else if(sm->displacement < 0)
            sm->limbFlag = 0;
    }
}
