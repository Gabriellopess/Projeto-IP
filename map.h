#ifndef MAP_H
#define MAP_H

Rectangle *map();
void collisionHero(int *gameStage, int *books, Vector2 ballPosition,float *ballPositionx,float *ballPositiony,int *soltaInimigo1,int *soltaInimigo2,int * book3,int *power);
void collisionEnemy(Vector2 enemyPosition,Vector2 enemyPosition2,float *enemyPositionx,float *enemyPositiony,float *enemyPosition2x,float *enemyPosition2y);
#endif