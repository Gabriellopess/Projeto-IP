#include "raylib.h"
#include "hero.h"

void heroLogic(float section, Texture2D hero, int *heroFramesCounter, int heroFramesSpeed, int *heroCurrentFrame,
    Rectangle *heroFrameRec){
        if(section != 48){
            if (IsKeyDown(KEY_UP)){
                (*heroFrameRec).y = section*3;
                (*heroFramesCounter)++;
                if(*heroFramesCounter >= (15/heroFramesSpeed)){
                    *heroFramesCounter = 0;
                    (*heroCurrentFrame)++;
                    if(*heroCurrentFrame > 2){
                        *heroCurrentFrame = 0;
                    }
                    
                    (*heroFrameRec).x = (float)*heroCurrentFrame * (float)hero.width/12;
                }
            }
        }
        if (IsKeyDown(KEY_RIGHT)){
            (*heroFrameRec).y = section*2;
            (*heroFramesCounter)++;
            if(*heroFramesCounter >= (15/heroFramesSpeed)){
                *heroFramesCounter = 0;
                (*heroCurrentFrame)++;
                if(*heroCurrentFrame > 2){
                    *heroCurrentFrame = 0;
                }
                
                (*heroFrameRec).x = (float)*heroCurrentFrame * (float)hero.width/12;
            }
        } 
        if (IsKeyDown(KEY_LEFT)){
            (*heroFrameRec).y = section;
            (*heroFramesCounter)++;
            if(*heroFramesCounter >= (15/heroFramesSpeed)){
                *heroFramesCounter = 0;
                (*heroCurrentFrame)++;
                if(*heroCurrentFrame > 2){
                    *heroCurrentFrame = 0;
                }
                
                (*heroFrameRec).x = (float)*heroCurrentFrame * (float)hero.width/12;
            }
        }
        
        if (IsKeyDown(KEY_DOWN)){
            (*heroFrameRec).y = section*0;
            (*heroFramesCounter)++;
            if(*heroFramesCounter >= (15/heroFramesSpeed)){
                *heroFramesCounter = 0;
                (*heroCurrentFrame)++;
                if(*heroCurrentFrame > 2){
                    *heroCurrentFrame = 0;
                }

                (*heroFrameRec).x = (float)*heroCurrentFrame * (float)hero.width/12;
            }
        }
}

void drawHero(float x, float y,Texture2D hero, Rectangle *heroFrameRec, Vector2 heroPosition){
    DrawTextureRec(
        hero,
        *heroFrameRec,
        (Vector2){heroPosition.x - x, heroPosition.y - y },
        WHITE
    );
}


void controlHero(float * ballPositionx,float * ballPositiony){
    if (IsKeyDown(KEY_RIGHT)) (*ballPositionx) += 3.0f;
        if (IsKeyDown(KEY_LEFT)) (*ballPositionx) -= 3.0f;
        if (IsKeyDown(KEY_UP)) (*ballPositiony) -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) (*ballPositiony) += 3.0f;
}

void deathHero(int *books, float *ballPositionx,float *ballPositiony,int *soltaInimigo1,int *soltaInimigo2,int * book3,int *power,float x,float y){
    (*ballPositionx) = x;
    (*ballPositiony)= y;
    (*soltaInimigo2) = 0;
    (*soltaInimigo1) = 0;
    (*book3) = 0;
    (*power) = 0;
    (*books) = 0;
}

void deathHero2(int *tempo, float *playerpositionx,float *playerpositiony,float *enemyPositionx,float *enemyPositiony,float *enemyPosition2x,float *enemyPosition2y,int *lifes){
    (*playerpositionx) = 80;
    (*playerpositiony)= 79;
    (*enemyPosition2x) = 33;
    (*enemyPosition2y) = 256;
    (*enemyPositionx) = 600;
    (*enemyPositiony) = 20;
    (*lifes)--;
    (*tempo) = 0;
}


int hacker(){
    if(IsKeyDown(KEY_M) && IsKeyDown(KEY_A) && IsKeyDown(KEY_R)) return 1;
    else return 0;
}

int powerPoison(int power){
    if(IsKeyDown(KEY_SPACE) && power == 1) return 1;
    else return 0;
}

