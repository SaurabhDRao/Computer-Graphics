#define N_STICKMANS 3

typedef struct {
    float xStart, xEnd, yStart;
    float speed, displacement, spearAngle;
    float handX, handY, spearX, spearY;
    int limbFlag, moveFlag, spearLoweredFlag, handRisedFlag, handMovedBackFlag;
    /* 
    ---stick man types---
    n - normal, s - spear
    */
    char type;
    float r, g, b;
} StickMan;

StickMan stickMan[N_STICKMANS];

float stickManXStarts[N_STICKMANS] = { 2200, 2100, 2000 };
float stickManXEnds[N_STICKMANS] = { 950, 900, 850 };
float stickManYStarts[N_STICKMANS] = { 50, 40, 30 };

float stickManSpeeds[N_STICKMANS] = { 3, 3, 3 };
float stickManDisps[N_STICKMANS] = { 0, 0, 0 };
float stickManSpearAngles[N_STICKMANS] = { 45, 45, 45 };

float stickManHandXs[N_STICKMANS] = { 0, 0, 0 };
float stickManHandYs[N_STICKMANS] = { 0, 0, 0 };
float stickManSpearYs[N_STICKMANS] = { 0, 0, 0 };
float stickManSpearXs[N_STICKMANS] = { 0, 0, 0 };

int stickManLimbFlags[N_STICKMANS] = { 1, 1, 1 };
int stickManMoveFlags[N_STICKMANS] = { 1, 1, 1 };
int stickManSpearLoweredFlags[N_STICKMANS] = { 0, 0, 0 };
int stickManHandRisedFlags[N_STICKMANS] = { 0, 0, 0 };
int stickManHandMovedBackFlags[N_STICKMANS] = { 0, 0, 0 };

char stickManTypes[N_STICKMANS] = { 'n', 'n', 's' };

float stickManRs[N_STICKMANS] = { 0.094, 0, 1 };
float stickManGs[N_STICKMANS] = { 0.063, 0, 1 };
float stickManBs[N_STICKMANS] = { 0.031, 0, 1 };

void initStickMan(StickMan *sm, int index) {
    sm->xStart = stickManXStarts[index];
    sm->xEnd = stickManXEnds[index];
    sm->yStart = stickManYStarts[index];

    sm->speed = stickManSpeeds[index];
    sm->displacement = stickManDisps[index];

    sm->spearAngle = stickManSpearAngles[index];

    sm->handY = stickManHandYs[index];
    sm->handX = stickManHandXs[index];
    sm->spearY = stickManSpearYs[index];
    sm->spearX = stickManSpearXs[index];

    sm->limbFlag = stickManLimbFlags[index];
    sm->moveFlag = stickManMoveFlags[index];
    sm->spearLoweredFlag = stickManSpearLoweredFlags[index];
    sm->handRisedFlag = stickManHandRisedFlags[index];
    sm->handMovedBackFlag = stickManHandMovedBackFlags[index];

    sm->type = stickManTypes[index];

    sm->r = stickManRs[index];
    sm->g = stickManGs[index];
    sm->b = stickManBs[index];
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
