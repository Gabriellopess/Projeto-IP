#ifndef HERO_H
#define HERO_H


void deathHero(int *books, float *ballPositionx,float *ballPositiony,int *soltaInimigo1,int *soltaInimigo2,int *book3,int *power,float x,float y);
void deathHero2(int *tempo, float *playerpositionx,float *playerpositiony,float *enemyPositionx,float *enemyPositiony,float *enemyPosition2x,float *enemyPosition2y,int *lifes);
int hacker();
int powerPoison();
void controlHero(float *ballPositionx,float *ballPositiony);
void heroLogic(float section, Texture2D hero, int *heroFramesCounter, int heroFramesSpeed, int *heroCurrentFrame,Rectangle *heroFrameRec);
void drawHero(float x, float y,Texture2D hero, Rectangle *heroFrameRec, Vector2 heroPosition);


#endif