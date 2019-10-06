#define N_DEERS 3

typedef struct {
    float xStart, xEnd, yStart, speed, displacement;
    int limbFlag, moveFlag, deadFlag;
    int r, g, b;
} Deer;

Deer deer[N_DEERS];
float deerXStarts[N_DEERS] = { -100, -200, -450 };
float deerXEnds[N_DEERS] = { 450, 150, 100 };
float deerYStarts[N_DEERS] = { 40, 25, 10 };
float deerSpeeds[N_DEERS] = { 3, 4, 5 };
float deerDisps[N_DEERS] = { 0, 0, 0 };
int deerLimbFlags[N_DEERS] = { 1, 1, 1 };
int deerMoveFlags[N_DEERS] = { 1, 1, 1 };
int deerDeadFlags[N_DEERS] = { 0, 0, 0 };
float deerRs[N_DEERS] = { 100, 159, 255 };
float deerGs[N_DEERS] = { 0, 100, 0 };
float deerBs[N_DEERS] = { 0, 0, 0 };

void initDeer(Deer *d, int index) {
    d->xStart = deerXStarts[index];
    d->xEnd = deerXEnds[index];
    d->yStart = deerYStarts[index];
    d->speed = deerSpeeds[index];
    d->displacement = deerDisps[index];
    d->limbFlag = deerLimbFlags[index];
    d->moveFlag = deerMoveFlags[index];
    d->deadFlag = deerDeadFlags[index];
    d->r = deerRs[index];
    d->g = deerGs[index];
    d->b = deerBs[index];
}

void updateDeerParams(Deer *d, char startDir) {
    if(startDir == 'L') {
        d->xStart += d->speed;

        if(d->limbFlag)
            d->displacement += d->speed;
        else
            d->displacement -= d->speed;
        
        if(d->displacement > (25 * 2))
            d->limbFlag = 0;
        else if(d->displacement < 0)
            d->limbFlag = 1;
    } else {
        d->xStart -= d->speed;

        if(d->limbFlag)
            d->displacement -= d->speed;
        else
            d->displacement += d->speed;
        
        if(d->displacement > (25 * 2))
            d->limbFlag = 1;
        else if(d->displacement < 0)
            d->limbFlag = 0;
    }
}
