/*
#include "raylib.h"

#define G 400
#define VELOC_PULO_JOG 300.0f
#define VELOC_HORIZ_JOG 150.0f

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta){
    if (IsKeyDown(KEY_LEFT)) player->position.x -= VELOC_HORIZ_JOG*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += VELOC_HORIZ_JOG*delta;
    if (IsKeyDown(KEY_UP) && player->podPular)
    {
        player->velocidade = -VELOC_PULO_JOG;
        player->podPular = false;
    }
 
    int hitObstacle = 0;
    for (int i = 0; i < envItemsLength; i++)
    {
        EnvItem *ei = envItems + i;
        Vector2 *p = &(player->position);
        if (ei->blocking &&
            ei->rect.x <= p->x &&
            ei->rect.x + ei->rect.width >= p->x &&
            ei->rect.y >= p->y &&
            ei->rect.y < p->y + player->velocidade*delta)
        {
            hitObstacle = 1;
            player->velocidade = 0.0f;
            p->y = ei->rect.y;
        }
    }
    if (!hitObstacle)
    {
        player->position.y += player->velocidade*delta;
        player->velocidade += G*delta;
    }
    else player->podPular = true;
}


void plataformaLogic(Player *player, EnvItem *envItems, int envItemsLength){
    float deltaTime = GetFrameTime();

    UpdateMusicStream(music);//music
    
    UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
    //volume
    if (IsKeyDown(KEY_M)) volume -= 0.01f;
    else if (IsKeyDown(KEY_N)) volume += 0.01f;
    SetMusicVolume(music, volume);
    
    
    //fantasmas
    if(player.position.x > enemyPosition.x) enemyPosition.x += 0.70f;
    if(player.position.x < enemyPosition.x) enemyPosition.x -= 0.70f;
    if(player.position.y > enemyPosition.y) enemyPosition.y += 0.70f;
    if(player.position.y < enemyPosition.y) enemyPosition.y -= 0.70f;

    if(player.position.x > enemyPosition2.x) enemyPosition2.x += 0.85f;
    if(player.position.x < enemyPosition2.x) enemyPosition2.x -= 0.85f;
    if(player.position.y > enemyPosition2.y) enemyPosition2.y += 0.85f;
    if(player.position.y < enemyPosition2.y) enemyPosition2.y -= 0.85f;
    //bolas de fogo

    if(fireBall1.y >= (-20) && gatilho == 0){
        fireBall1.y -= 3.0f;
        if(fireBall1.y <= (-20)) gatilho=1;
    }
    else{
        fireBall1.y += 3.0f;
        if(fireBall1.y >= 420) gatilho=0;
    } 

    if(fireBall2.y >= (-20) && gatilho2 == 0){
        fireBall2.y -= 3.0f;
        if(fireBall2.y <= (-20)) gatilho2=1;
    }
    else{
        fireBall2.y += 3.0f;
        if(fireBall2.y >= 420) gatilho2=0;
    } 

    if(fireBall3.y >= (-20) && gatilho3 == 0){
        fireBall3.y -= 3.0f;
        if(fireBall3.y <= (-20)) gatilho3=1;
    }
    else{
        fireBall3.y += 3.0f;
        if(fireBall3.y >= 420) gatilho3=0;
    } 
}

void drawPlataforma(EnvItem *envItems){
    for (int i = 0; i < envItemsLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);

    Rectangle playerRect = { player.position.x - 20, player.position.y - 40, 40, 40 };
    DrawCircleV(enemyPosition, 7, DARKBLUE);
    DrawCircleV(enemyPosition2, 7, DARKBLUE);
    DrawCircleV(fireBall1, 15, RED);
    DrawCircleV(fireBall2, 15, RED);
    DrawCircleV(fireBall3, 15, RED);
    DrawRectangleRec(playerRect, RED);

    //colisoes c inimigo
    if(CheckCollisionCircleRec(enemyPosition, 7, playerRect)){
        enemyPosition.x = 600;
        enemyPosition.y = 20;
        enemyPosition2.x = 33;
        enemyPosition2.y = 256;
        player.position.x = 80;
        player.position.y = 79;
    }
    if(CheckCollisionCircleRec(enemyPosition2, 7, playerRect)){
        enemyPosition.x = 600;
        enemyPosition.y = 20;
        enemyPosition2.x = 33;
        enemyPosition2.y = 256;
        player.position.x = 80;
        player.position.y = 79;
    }
    if(CheckCollisionCircleRec(fireBall1, 15, playerRect)){
        enemyPosition.x = 600;
        enemyPosition.y = 20;
        enemyPosition2.x = 33;
        enemyPosition2.y = 256;
        player.position.x = 80;
        player.position.y = 79;
    }
    if(CheckCollisionCircleRec(fireBall2, 15, playerRect)){
        enemyPosition.x = 600;
        enemyPosition.y = 20;
        enemyPosition2.x = 33;
        enemyPosition2.y = 256;
        player.position.x = 80;
        player.position.y = 79;
    }
    if(CheckCollisionCircleRec(fireBall3, 15, playerRect)){
        enemyPosition.x = 600;
        enemyPosition.y = 20;
        enemyPosition2.x = 33;
        enemyPosition2.y = 256;
        player.position.x = 80;
        player.position.y = 79;
    }
    if(player.position.y == 370){
        enemyPosition.x = 600;
        enemyPosition.y = 20;
        enemyPosition2.x = 33;
        enemyPosition2.y = 256;
        player.position.x = 80;
        player.position.y = 79;
    }
}

*/