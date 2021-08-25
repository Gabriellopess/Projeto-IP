#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "hero.h"
#include "map.h"

#define RAIO 7
//mingw32-make PLATFORM=PLATFORM_DESKTOP

int main() {
    const int screenWidth = 800;
    const int screenHeight = 400;
    const char *title = "Joguinho";
    int power =0;
    int soltaInimigo1 =0;
    int soltaInimigo2 =0;
    int book3 =0;
    Rectangle *mapa = NULL;
    

    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle(title);
    
    Vector2 ballPosition = { (float)33, (float)356 };
    Vector2 enemyPosition2;
    Vector2 enemyPosition;

    //mapa
    Vector2 bullshit = {(float)0, (float)0};
    mapa = map();

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        controlHero(&ballPosition.x,&ballPosition.y);
        controlEnemys(soltaInimigo1,soltaInimigo2,ballPosition.x,ballPosition.y
        ,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y);

        //entrada
        if(ballPosition.x <= 0){
            deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
        }

        if (!hacker()){
            //colisoes com o terreno (hero)
            collisionHero(ballPosition,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power);               
            //colisoes com o terreno (enemy)
            collisionEnemy(enemyPosition,enemyPosition2,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y);
            
            //colisao com inimigo
            if(CheckCollisionCircles(ballPosition, RAIO, enemyPosition, RAIO) && soltaInimigo1 == 1){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }

            if(CheckCollisionCircles(ballPosition, RAIO, enemyPosition2, RAIO) && soltaInimigo2 == 1){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }
            
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleRec(mapa[0], RED);
            DrawRectangleRec(mapa[1], RED);
            DrawRectangleRec(mapa[2], RED);
            DrawRectanglePro(mapa[3], bullshit, 50, RED); 
            DrawRectanglePro(mapa[4], bullshit, 50, RED);
            DrawRectangleRec(mapa[5], RED);
            DrawRectangleRec(mapa[6], RED);
            DrawRectanglePro(mapa[7], bullshit, -230, RED); 
            DrawRectanglePro(mapa[8], bullshit, -230, RED); 
            DrawRectangleRec(mapa[9], RED);
            DrawRectangleRec(mapa[10], RED);
            DrawRectangleRec(mapa[11], RED);
            DrawRectangleRec(mapa[12], RED);
            DrawRectangleRec(mapa[13], RED);
            DrawRectangleRec(mapa[14], RED);
            DrawRectangleRec(mapa[15], RED);
            DrawRectangleRec(mapa[16], RED);
            DrawRectangleRec(mapa[17], RED);
            DrawRectangleRec(mapa[18], RED);
            DrawRectangleRec(mapa[19], RED);
            DrawRectangleRec(mapa[20], RED);
            DrawRectangleRec(mapa[21], RED);
            DrawRectangleRec(mapa[22], RED);
            DrawRectangleRec(mapa[23], RED);
            DrawRectangleRec(mapa[24], RED);
            DrawRectangleRec(mapa[25], RED);
            DrawRectanglePro(mapa[26], bullshit, 45, RED);
            DrawRectangleRec(mapa[27], RED);
            DrawRectanglePro(mapa[28], bullshit, 45, RED);
            DrawRectangleRec(mapa[29], RED);
            DrawRectangleRec(mapa[30], RED);
            DrawRectangleRec(mapa[31], RED);
            DrawRectangleRec(mapa[32], RED);
            DrawRectangleRec(mapa[33], RED);
            DrawRectangleRec(mapa[34], RED);
            DrawRectanglePro(mapa[35], bullshit, -40, RED);

            DrawRectangleRec(mapa[36], BLACK);
            DrawRectangleRec(mapa[37], BLACK);
            DrawRectangleRec(mapa[38], BLACK);
            DrawRectangleRec(mapa[39], BLACK);
            DrawRectangleRec(mapa[40], BLACK);
            DrawRectangleRec(mapa[41], BLACK);
            DrawRectangleRec(mapa[42], BLACK);
            DrawRectangleRec(mapa[43], BLACK);
            DrawRectangleRec(mapa[44], BLACK);
            DrawRectangleRec(mapa[45], BLACK);
            DrawRectangleRec(mapa[46], BLACK);
            DrawRectangleRec(mapa[47], BLACK);
            DrawRectangleRec(mapa[48], BLACK);
            DrawRectangleRec(mapa[49], BLACK);
            DrawRectangleRec(mapa[50], BLACK);
            DrawRectangleRec(mapa[51], BLACK);
            DrawRectangleRec(mapa[52], BLACK);
            DrawRectangleRec(mapa[53], BLACK);
            DrawRectangleRec(mapa[54], BLACK);
            DrawRectangleRec(mapa[55], BLACK);
            DrawRectangleRec(mapa[56], BLACK);
            DrawRectangleRec(mapa[57], BLACK);
            DrawRectangleRec(mapa[58], BLACK);
            DrawRectangleRec(mapa[59], BLACK);
            DrawRectangleRec(mapa[60], BLACK);
            DrawRectangleRec(mapa[61], BLACK);
            DrawRectangleRec(mapa[62], BLACK);
            DrawRectangleRec(mapa[63], BLACK);
            DrawRectangleRec(mapa[64], BLACK);
            DrawRectangleRec(mapa[65], BLACK);
            DrawRectangleRec(mapa[66], BLACK);
            DrawRectangleRec(mapa[67], BLACK);
            DrawRectangleRec(mapa[68], BLACK);
            DrawRectangleRec(mapa[69], BLACK);
            DrawRectangleRec(mapa[70], BLACK);

            DrawRectangleRec(mapa[71], GREEN);
            DrawRectangleRec(mapa[72], GREEN);
            DrawRectangleRec(mapa[73], GREEN);

            DrawRectangleRec(mapa[74], PINK);
            DrawRectangleRec(mapa[75], PINK);
            DrawRectangleRec(mapa[76], PINK);

            if(power == 0) DrawRectangleRec(mapa[80], PURPLE);

            DrawRectangleRec(mapa[81], GRAY);



            if(soltaInimigo1 == 0) DrawRectangleRec(mapa[77], ORANGE);
            if(soltaInimigo2 == 0) DrawRectangleRec(mapa[78], ORANGE);
            if(book3 == 0) DrawRectangleRec(mapa[79], ORANGE);

            DrawText("USE AS SETAS PARA MOVER", 10, 10, 20, DARKGRAY);

            if (powerPoison(power)){
                DrawCircleV(ballPosition, RAIO, RED);
            }
            else if(hacker()){
                DrawCircleV(ballPosition, RAIO, YELLOW);
            }
            else{
                DrawCircleV(ballPosition, RAIO, BLACK);
            }
            
            if(soltaInimigo1 == 1) DrawCircleV(enemyPosition, RAIO, DARKBLUE);
            if(soltaInimigo2 == 1) DrawCircleV(enemyPosition2, RAIO, DARKBLUE);


        EndDrawing();
    } 
    CloseWindow();  // Close window and OpenGL context
    free(mapa);
    return 0;
}
