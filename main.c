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
    // Vector2 bullshit = {(float)0, (float)0};
    Texture2D mapGrass = LoadTexture("assets/GrassSprite.png");
    Texture2D stoneHorizWall = LoadTexture("assets/StoneWallSprite80x22.png");
    Texture2D stoneVertWall = LoadTexture("assets/NewStoneVerticalSprite33x22.png");
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

                

                //mask
                if(power == 0) {
                    DrawTextureRec(
                        mask,
                        (Rectangle){0.0f, 0.0f, (float)mask.width, (float)mask.height},
                        (Vector2){(float)17, (float)25},
                        WHITE
                    );
                }
                
                //porta de saida
                DrawTextureRec(
                    door,
                    (Rectangle){0.0f, 0.0f, (float)door.width, (float)door.height},
                    (Vector2){(float)752, (float)28},
                    WHITE
                );

                //books
                if(soltaInimigo1 == 0) {
                    DrawTextureRec(
                        book1text,
                        (Rectangle){0.0f, 0.0f, (float)book1text.width, (float)book1text.height},
                        (Vector2){(float)13, (float)270},
                        WHITE
                    );
                }
                if(soltaInimigo2 == 0){
                    DrawTextureRec(
                        book2text,
                        (Rectangle){0.0f, 0.0f, (float)book2text.width, (float)book2text.height},
                        (Vector2){(float)273, (float)290},
                        WHITE
                    );
                } 
                if(book3 == 0) {
                    DrawTextureRec(
                        book3text,
                        (Rectangle){0.0f, 0.0f, (float)book3text.width, (float)book3text.height},
                        (Vector2){(float)648, (float)110},
                        WHITE
                    );
                }

                //StoneWall
                drawDiagWall(diagWall);
                drawVertWall(stoneVertWall);
                
                //veneno
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)409, (float)330},
                    WHITE
                );
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)52, (float)20},
                    WHITE
                );
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)618, (float)20},
                    WHITE
                );

                //Stone wall
                drawHorizontalWall(stoneHorizWall);
                
                 
                //fantasmas
                if(soltaInimigo1 == 1){
                    DrawCircleV(enemyPosition, RAIO, DARKBLUE);
                    drawFantasma(fantasmaRight, fantasmaLeft, enemyPosition, &temporary);
                    temporary = enemyPosition.x;
                } 
                if(soltaInimigo2 == 1) {
                    drawFantasma(fantasmaRight, fantasmaLeft, enemyPosition2, &temporary2);
                    temporary2 = enemyPosition2.x;
                }

                //Personagem
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
                DrawTextureRec(
                    cage1,
                    (Rectangle){0.0f, 0.0f, (float)cage1.width, (float)cage1.height},
                    (Vector2){(float)33, (float)334},
                    WHITE
                );
                DrawTextureRec(
                    cage2,
                    (Rectangle){0.0f, 0.0f, (float)cage2.width, (float)cage2.height},
                    (Vector2){(float)700, (float)109},
                    WHITE
                );
                DrawTextureRec(
                    cage3,
                    (Rectangle){0.0f, 0.0f, (float)cage3.width, (float)cage3.height},
                    (Vector2){(float)300, (float)19},
                    WHITE
                );


                drawContadores(books);
            }
        EndDrawing();
    }
        
    CloseWindow();  // Close window and OpenGL context

    free(mapa);
    return 0;
}
