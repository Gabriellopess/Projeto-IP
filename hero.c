#include "hero.h"
#include "raylib.h"

void deathHero(int *books, float *ballPositionx,float *ballPositiony,int *soltaInimigo1,int *soltaInimigo2,int * book3,int *power,float x,float y){
    *ballPositionx = x;
    *ballPositiony= y;
    *soltaInimigo2 = 0;
    *soltaInimigo1 = 0;
    *book3 = 0;
    *power = 0;
    *books = 0;
}

int hacker(){
    if(IsKeyDown(KEY_M) && IsKeyDown(KEY_A) && IsKeyDown(KEY_R)) return 1;
    else return 0;
}

int powerPoison(int power){
    if(IsKeyDown(KEY_SPACE) && power == 1) return 1;
    else return 0;
}

void controlHero(float * ballPositionx,float * ballPositiony){
    if (IsKeyDown(KEY_RIGHT)) (*ballPositionx) += 3.0f;
        if (IsKeyDown(KEY_LEFT)) (*ballPositionx) -= 3.0f;
        if (IsKeyDown(KEY_UP)) (*ballPositiony) -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) (*ballPositiony) += 3.0f;
}