#include "hero.h"
#include "raylib.h"

void deathHero(float *ballPositionx,float *ballPositiony,int *soltaInimigo1,int *soltaInimigo2,int * book3,int *power,float x,float y){
    *ballPositionx = x;
    *ballPositiony= y;
    *soltaInimigo2 = 0;
    *soltaInimigo1 = 0;
    *book3 = 0;
    *power = 0;
}

int hacker(){
    if(IsKeyDown(KEY_M) && IsKeyDown(KEY_A) && IsKeyDown(KEY_R)) return 1;
    else return 0;
}

int powerPoison(int power){
    if(IsKeyDown(KEY_SPACE) && power == 1) return 1;
    else return 0;
}