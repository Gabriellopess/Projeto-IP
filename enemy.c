#include "enemy.h"

void resetEnemy(float *enemyPositionx,float *enemyPositiony,float x,float y){
    *enemyPositionx = x;
    *enemyPositiony= y;
}

void controlEnemys(int soltaInimigo1,int soltaInimigo2,float ballPositionx,float ballPositiony
                    ,float *enemyPositionx,float *enemyPositiony,float *enemyPosition2x,float *enemyPosition2y ){
    if(soltaInimigo1 == 0){
            resetEnemy(enemyPositionx,enemyPositiony,450,80);
        }

        if(soltaInimigo2 == 0){
            resetEnemy(enemyPosition2x,enemyPosition2y,600,356);
        }
    if(soltaInimigo1 == 1){
        if(ballPositionx > (*enemyPositionx)) (*enemyPositionx) += 0.65f;
        if(ballPositionx < (*enemyPositionx)) (*enemyPositionx) -= 0.65f;
        if(ballPositiony > (*enemyPositiony)) (*enemyPositiony) += 0.65f;
        if(ballPositiony < (*enemyPositiony)) (*enemyPositiony) -= 0.65f;
    }
    
    if(soltaInimigo2 == 1){
        if(ballPositionx > (*enemyPosition2x)) (*enemyPosition2x) += 0.75f;
        if(ballPositionx < (*enemyPosition2x)) (*enemyPosition2x) -= 0.75f;
        if(ballPositiony > (*enemyPosition2y)) (*enemyPosition2y) += 0.75f;
        if(ballPositiony < (*enemyPosition2y)) (*enemyPosition2y) -= 0.75f;
    }
}