#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "hero.h"
#include "map.h"
#include "introducao.h"
#include "texturas.h"

#define RAIO 7

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

    int power =0;
    int soltaInimigo1 =0;
    int soltaInimigo2 =0;
    int book3 =0;
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
    Texture2D veneno = LoadTexture("assets/venenoSprite.png");
    Rectangle stoneWallRec = {0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height};

    mapa = map();
    
    //castelo introdução
    int castleCurrentFrame = 0;
    int castleFramesCounter = 0;
    int castleFramesSpeed = 1;
    float castleX = -40;
    float castleY = -20; //49.52
    Vector2 castlePosition = {castleX, castleY};
    Texture2D castle = LoadTexture("assets/castleSpriteRed.png");
    Rectangle castleFrameRec = {0.0f, 0.0f, (float)castle.width/2, (float)castle.height};

    //background introducao
    Texture2D background = LoadTexture("assets/grassFundo.png");

    //texto introducao
    char message[100] = "Teste lalalala historinha bla bla bla\nbla bla bla bla";
    int framesCounter = 0;


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(gameStage == 0){
            //Introducao
            introducaoLogic(castle, &castleFramesCounter, castleFramesSpeed, &castleCurrentFrame, &castleFrameRec, &framesCounter, &gameStage);
        }

        if(gameStage == 1){
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
   
        }
        
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if(gameStage == 0){
                //introducao
                introducao(background, castle, &castleFrameRec, castlePosition, message, framesCounter);
            }
            if(gameStage == 1){
                //labirinto

                //grama textura
                //coluna 1
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){0, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){0, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){0, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){0, 345},
                    WHITE
                );

                //coluna2
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){116, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){116, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){116, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){116, 345},
                    WHITE
                );

                //coluna3
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){232, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){232, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){232, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){232, 345},
                    WHITE
                );

                //coluna 4
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){348, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){348, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){348, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){348, 345},
                    WHITE
                );

                //coluna 5
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){464, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){464, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){464, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){464, 345},
                    WHITE
                );

                //coluna 6
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){580, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){580, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){580, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){580, 345},
                    WHITE
                );

                //coluna 7
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){696, 0},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){696, 115},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){696, 230},
                    WHITE
                );
                DrawTextureRec(
                    mapGrass,
                    (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
                    (Vector2){696, 345},
                    WHITE
                );



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
                DrawRectangleRec(mapa[71], GREEN);
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)410, (float)335},
                    WHITE
                );
                DrawRectangleRec(mapa[72], GREEN);
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)52, (float)20},
                    WHITE
                );
                DrawRectangleRec(mapa[73], GREEN);
                DrawTextureRec(
                    veneno,
                    (Rectangle){0.0f, 0.0f, (float)veneno.width, (float)veneno.height},
                    (Vector2){(float)618, (float)20},
                    WHITE
                );

                //safe zone
                DrawRectangleRec(mapa[74], PINK);
                DrawRectangleRec(mapa[75], PINK);
                DrawRectangleRec(mapa[76], PINK);

                //mask
                if(power == 0) {
                    DrawRectangleRec(mapa[80], PURPLE);
                    DrawTextureRec(
                        mask,
                        (Rectangle){0.0f, 0.0f, (float)mask.width, (float)mask.height},
                        (Vector2){(float)17, (float)25},
                        WHITE
                    );
                }
                
                //porta de saida
                DrawRectangleRec(mapa[81], GRAY);

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
                // if(soltaInimigo1 == 0) DrawTextureRec(book1, mapa[77], (Vector2){(float)15, (float)280}, WHITE);
                // if(soltaInimigo2 == 0) DrawTextureRec(mapa[78], ORANGE);
                // if(book3 == 0) DrawTextureRec(mapa[79], ORANGE);
                
                if (powerPoison(power)){
                    DrawCircleV(ballPosition, RAIO, RED);
                }
                else if(hacker()){
                    DrawCircleV(ballPosition, RAIO, YELLOW);
                }
                else{
                    DrawCircleV(ballPosition, RAIO, BLACK);
                }
                
                if(soltaInimigo1 == 1){
                    DrawCircleV(enemyPosition, RAIO, DARKBLUE);
                    if(enemyPosition.x >= temporary){
                        DrawTextureRec(
                            fantasmaRight,
                            (Rectangle){0.0f, 0.0f, (float)fantasmaRight.width, (float)fantasmaRight.height},
                            (Vector2){enemyPosition.x - 25, enemyPosition.y - 22},
                            WHITE
                        );
                    }
                    else if(enemyPosition.x < temporary){
                        DrawTextureRec(
                            fantasmaLeft,
                            (Rectangle){0.0f, 0.0f, (float)fantasmaLeft.width, (float)fantasmaLeft.height},
                            (Vector2){enemyPosition.x - 25, enemyPosition.y - 22},
                            WHITE
                        );
                    }
                    temporary = enemyPosition.x;
                } 
                if(soltaInimigo2 == 1) {
                    DrawCircleV(enemyPosition2, RAIO, DARKBLUE);
                    if(enemyPosition2.x >= temporary2){
                        DrawTextureRec(
                            fantasmaRight,
                            (Rectangle){0.0f, 0.0f, (float)fantasmaRight.width, (float)fantasmaRight.height},
                            (Vector2){enemyPosition2.x - 25, enemyPosition2.y - 22},
                            WHITE
                        );
                    }
                    else if(enemyPosition2.x < temporary2){
                        DrawTextureRec(
                            fantasmaLeft,
                            (Rectangle){0.0f, 0.0f, (float)fantasmaLeft.width, (float)fantasmaLeft.height},
                            (Vector2){enemyPosition2.x - 25, enemyPosition2.y - 22},
                            WHITE
                        );
                    }
                    temporary2 = enemyPosition2.x;
                }

                

                //Stone Wall
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){0, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){80, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){160, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){240, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){320, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){400, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){480, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){560, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){640, 380},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){720, 380},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){0, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){80, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){160, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){240, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){320, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){400, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){480, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){560, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){640, 0},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){720, 0},
                    WHITE
                );


                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){0, 315},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){80, 315},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){127, 315},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){0, 203},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){20, 203},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){250, 269},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){330, 269},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){350, 269},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){250, 94},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){330, 94},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){390, 94},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){384, 152},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width/1.7, (float)stoneHorizWall.height},
                    (Vector2){484, 213}, //IMAGEM MT GRANDE PARA O RETANGULO 484
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){565, 289},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){618, 89},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){698, 89},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){726, 89},
                    WHITE
                );

                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){186, 203},
                    WHITE
                );
                DrawTextureRec(
                    stoneHorizWall,
                    (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
                    (Vector2){190, 203},
                    WHITE
                );

                
            }
        EndDrawing();
    }
        
    CloseWindow();  // Close window and OpenGL context

    free(mapa);
    return 0;
}