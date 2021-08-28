#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "hero.h"
#include "map.h"
#include "introducao.h"
#include "texturas.h"
#include "texto.h"

#define RAIO 7

/*
Define para nome das fases;
struct para os estados;
função para chamar nos gameStages;
reutilização de codigo criando função;
*/


//mingw32-make PLATFORM=PLATFORM_DESKTOP

int main() {
    const int screenWidth = 800;
    const int screenHeight = 400;
    const char *title = "Joguinho";
    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle(title);
    SetTargetFPS(60);

    int gameStage = 0;
    float temporary = 0;
    float temporary2 = 0;

    int power = 0;
    int soltaInimigo1 =0;
    int soltaInimigo2 =0;
    int book3 =0;
    int books = 0;
    Vector2 ballPosition = { (float)33, (float)356 };
    Vector2 enemyPosition2;
    Vector2 enemyPosition;

    //mapa
    Rectangle *mapa = NULL;
    Vector2 bullshit = {(float)0, (float)0};
    Texture2D mapGrass = LoadTexture("assets/GrassSprite.png");
    Texture2D stoneHorizWall = LoadTexture("assets/StoneWallSprite80x22.png");
    Texture2D book1text = LoadTexture("assets/book1Sprite40x40.png");
    Texture2D book2text = LoadTexture("assets/book2Sprite40x40.png");
    Texture2D book3text = LoadTexture("assets/book3Sprite40x40.png");
    Texture2D fantasmaRight = LoadTexture("assets/fantasmaSprite50x50.png");
    Texture2D fantasmaLeft = LoadTexture("assets/fantasmaLeftSprite50x50.png");
    Texture2D mask = LoadTexture("assets/mask2Sprite.png");
    Texture2D veneno = LoadTexture("assets/venom.png");
    Texture2D cage3 = LoadTexture("assets/cage3.png");
    Texture2D cage2 = LoadTexture("assets/cage2.png");
    Texture2D cage1 = LoadTexture("assets/cage1.png");
    Texture2D door = LoadTexture("assets/castleDoor49x60.png");
    Texture2D diagWall = LoadTexture("assets/wall1.png");

    mapa = map();
    
    //castelo introdução
    int castleCurrentFrame = 0;
    int castleFramesCounter = 0;
    int castleFramesSpeed = 1;
    float castleX = -55;
    float castleY = -30; //49.52
    Vector2 castlePosition = {castleX, castleY};
    Texture2D castle = LoadTexture("assets/castleSpriteRed.png");
    Rectangle castleFrameRec = {0.0f, 0.0f, (float)castle.width/2, (float)castle.height};
    
    //buttons introducao
    Texture2D playButton = LoadTexture("assets/playButton150x50.png");
    Texture2D whitePlayButton = LoadTexture("assets/whitePlayButton.png");
    Texture2D controlsButton = LoadTexture("assets/controlsButton150x50.png");
    Texture2D whiteControlsButton = LoadTexture("assets/whiteControlsButton.png");
    Texture2D exitButton = LoadTexture("assets/exitButton150x50.png");
    Texture2D whiteExitButton = LoadTexture("assets/whiteExitButton.png");

    //background introducao
    Texture2D background = LoadTexture("assets/grassFundo.png");

    //texto introducao
    char message[100] = "Anjolinda\n    Rescue";
    int framesCounter = 0;
    //texto explicação
    char secondMessage[1000] = "Bem vindo ao Reino do CIn, discípulo!\nSua primeira missão como aprendiz de Matemática Discreta\nserá recuperar os 3 livros dos autores favoritos da\nPrincesa Anjolinda: Rosen, Lovász e Knuth, que estão\nperdidos no labirinto do castelo, protegidos por\nfantasmas e paredes amaldiçoadas.\nBoa sorte! Que Fermat o proteja.";

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(gameStage == 0){
            //Introducao
            introducaoLogic(castle, &castleFramesCounter, castleFramesSpeed, &castleCurrentFrame, &castleFrameRec, &framesCounter, &gameStage);
        }
        if(gameStage == 1){
            textLogic(&framesCounter, &gameStage);
        }
        if(gameStage == 2){
            controlHero(&ballPosition.x,&ballPosition.y);
            controlEnemys(soltaInimigo1,soltaInimigo2,ballPosition.x,ballPosition.y
            ,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y);

            //entrada
            if(ballPosition.x <= 0){
                deathHero(&books,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }

            if (!hacker()){
                //colisoes com o terreno (hero)
                collisionHero(&books,ballPosition,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power);               
                //colisoes com o terreno (enemy)
                collisionEnemy(enemyPosition,enemyPosition2,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y);
                
                //colisao com inimigo
                if(CheckCollisionCircles(ballPosition, RAIO, enemyPosition, RAIO) && soltaInimigo1 == 1){
                    deathHero(&books,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
                }
                if(CheckCollisionCircles(ballPosition, RAIO, enemyPosition2, RAIO) && soltaInimigo2 == 1){
                    deathHero(&books,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
                }
            }

   
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if(gameStage == 0){
                //introducao
                introducao(background, castle, playButton, whitePlayButton, controlsButton, whiteControlsButton, exitButton, whiteExitButton, &castleFrameRec, castlePosition, message, framesCounter);
            }
            if(gameStage == 1){
                drawText(background, castle, castlePosition, castleFrameRec,secondMessage, framesCounter);
            }
            if(gameStage == 2){
                //labirinto
                //grama textura
                drawGrass(mapGrass);

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

                //veneno
                // DrawRectangleRec(mapa[71], GREEN);
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)409, (float)330},
                    WHITE
                );
                // DrawRectangleRec(mapa[72], GREEN);
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)52, (float)20},
                    WHITE
                );
                // DrawRectangleRec(mapa[73], GREEN);
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)618, (float)20},
                    WHITE
                );
                
                

                //mask
                if(power == 0) {
                    // DrawRectangleRec(mapa[80], PURPLE);
                    DrawTextureRec(
                        mask,
                        (Rectangle){0.0f, 0.0f, (float)mask.width, (float)mask.height},
                        (Vector2){(float)17, (float)25},
                        WHITE
                    );
                }
                
                //porta de saida
                // DrawRectangleRec(mapa[81], GRAY);
                DrawTextureRec(
                    door,
                    (Rectangle){0.0f, 0.0f, (float)door.width, (float)door.height},
                    (Vector2){(float)752, (float)28},
                    WHITE
                );

                //books
                if(soltaInimigo1 == 0) {
                    // DrawRectangleRec(mapa[77], ORANGE);
                    DrawTextureRec(
                        book1text,
                        (Rectangle){0.0f, 0.0f, (float)book1text.width, (float)book1text.height},
                        (Vector2){(float)13, (float)270},
                        WHITE
                    );
                }
                if(soltaInimigo2 == 0){
                    // DrawRectangleRec(mapa[78], ORANGE);
                    DrawTextureRec(
                        book2text,
                        (Rectangle){0.0f, 0.0f, (float)book2text.width, (float)book2text.height},
                        (Vector2){(float)273, (float)290},
                        WHITE
                    );
                } 
                if(book3 == 0) {
                    // DrawRectangleRec(mapa[79], ORANGE);
                    DrawTextureRec(
                        book3text,
                        (Rectangle){0.0f, 0.0f, (float)book3text.width, (float)book3text.height},
                        (Vector2){(float)648, (float)110},
                        WHITE
                    );
                }
                
                if (powerPoison(power)){
                    DrawCircleV(ballPosition, RAIO, RED);
                }
                else if(hacker()){
                    DrawCircleV(ballPosition, RAIO, YELLOW);
                }
                else{
                    DrawCircleV(ballPosition, RAIO, BLACK);
                }

                //safe zone
                // DrawRectangleRec(mapa[74], PINK);
                DrawTextureRec(
                    cage1,
                    (Rectangle){0.0f, 0.0f, (float)cage1.width, (float)cage1.height},
                    (Vector2){(float)33, (float)334},
                    WHITE
                );
                // DrawRectangleRec(mapa[75], PINK);
                DrawTextureRec(
                    cage2,
                    (Rectangle){0.0f, 0.0f, (float)cage2.width, (float)cage2.height},
                    (Vector2){(float)700, (float)109},
                    WHITE
                );

                // DrawRectangleRec(mapa[76], PINK);
                DrawTextureRec(
                    cage3,
                    (Rectangle){0.0f, 0.0f, (float)cage3.width, (float)cage3.height},
                    (Vector2){(float)300, (float)19},
                    WHITE
                );
                
                if(soltaInimigo1 == 1){
                    DrawCircleV(enemyPosition, RAIO, DARKBLUE);
                    drawFantasma(fantasmaRight, fantasmaLeft, enemyPosition, &temporary);
                    temporary = enemyPosition.x;
                } 
                if(soltaInimigo2 == 1) {
                    drawFantasma(fantasmaRight, fantasmaLeft, enemyPosition2, &temporary2);
                    temporary2 = enemyPosition2.x;
                }

                //StoneWall
                drawDiagWall(diagWall);
                drawHorizontalWall(stoneHorizWall);

                 

                drawContadores(books);   
            }
        EndDrawing();
    }
        
    CloseWindow();  // Close window and OpenGL context

    free(mapa);
    return 0;
}