#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pthread.h"
#include "enemy.h"
#include "hero.h"
#include "map.h"
#include "introducao.h"
#include "texturas.h"
#include "texto.h"
#include "plataforma.h"

#define RAIO 7
#define G 400
#define VELOC_PULO_JOG 300.0f
#define VELOC_HORIZ_JOG 150.0f
#define INTRODUCAO 0
#define TEXTO1 1
#define LABIRINTO 2
#define TEXTO2 3
#define PLATAFORMA 4
#define FINAL 5
#define CONTROLES 6

typedef struct Player {
    Vector2 position;
    float velocidade;
    bool podPular;
} Player;
 
typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

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

    int framesCounterTime = 0;
    float aux1 = 0;
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

    //plataforma
    int gatilho = 0;
    int gatilho2 = 0;
    int gatilho3 = 0;
    float temporaryplat = 0, temporary2plat = 0;
    int lifes = 5;
    int finish = 0;
 
    //music antes while
    InitAudioDevice();
    Music music = LoadMusicStream("assets/music3.mp3");
    Music musiclab = LoadMusicStream("assets/music1.mp3");
    Music musictema = LoadMusicStream("assets/music2.mp3");
    Music musicWin = LoadMusicStream("assets/music4.mp3");
    Music musicLose = LoadMusicStream("assets/music5.mp3");

    float volume = 0.1f;
    PlayMusicStream(music);
    PlayMusicStream(musiclab);
    PlayMusicStream(musictema);
    PlayMusicStream(musicWin);
    PlayMusicStream(musicLose);

 
    Texture2D porta = LoadTexture("assets/portinha.png");
    Texture2D piso = LoadTexture("assets/pisinho.png");
    Texture2D fundo = LoadTexture("assets/fundin.png");
    Texture2D lava = LoadTexture("assets/lava.png");
    Texture2D fireballUp = LoadTexture("assets/fireballUp45x94.png");
    Texture2D fireballDown = LoadTexture("assets/fireballDown45x94.png");
    Texture2D heart = LoadTexture("assets/heart28x28.png");
 
 
    Vector2 enemyPosition2plat = { (float)33, (float)356 };
    Vector2 enemyPositionplat = { (float)600, (float)20 };
    Vector2 fireBall1 = { (float)(180), (float)420 };
    Vector2 fireBall2 = { (float)340, (float)420 };
    Vector2 fireBall3 = { (float)495, (float)420 };
 
    Player player = { 0 };
    player.position = (Vector2){ 80, 79};
    player.velocidade = 0;
    player.podPular = false;
    EnvItem envItems[] = {
        {{ 530, 340, 80, 30 }, 1, GREEN},//1
        {{ 0, 370, 800, 30 }, 1, ORANGE},//2
        {{ 224, 173, 80, 30 }, 1, GREEN },//3
        {{ 222, 289, 80, 30 }, 1, GREEN },//4
        {{ 0, 80, 160, 30 }, 1, GREEN },//5
        {{ 395, 252, 80, 30 }, 1, GREEN},//6
        {{ 544, 145, 80, 30 }, 1, GREEN },//7
        {{ 683, 280, 80, 30 }, 1, GREEN },//8
        {{ 683, 61, 190, 30 }, 1, GREEN },//9
        {{ 0, 300, 80, 30 }, 1, GREEN },//10
        {{ 40, 180, 80, 30 }, 1, GREEN },//11
        {{ 357, 81, 80, 30 }, 1, GREEN }//12
    };
 
    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);
    

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
    Texture2D backButton = LoadTexture("assets/back.png");
    Texture2D whiteBackButton = LoadTexture("assets/whiteBack.png");

    Texture2D controls = LoadTexture("assets/controls.png");

    //background introducao
    Texture2D background = LoadTexture("assets/grassFundo.png");

    //texto introducao
    char message[100] = "Anjolinda\n    Rescue";
    int framesCounter = 0;
    //texto explicação
    char secondMessage[1000] = "Bem vindo ao Reino do CIn, discípulo!\nSua primeira missão como aprendiz de Matemática Discreta\nserá recuperar os 3 livros dos autores favoritos da\nPrincesa Anjolinda: Rosen, Lovász e Knuth, que estão\nperdidos no labirinto do castelo, protegidos por\nfantasmas e paredes amaldiçoadas.\nBoa sorte! Que Fermat o proteja.";

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
            //player->podPular = false;
        }
        else player->podPular = true;
    }

    void drawFantasma(Texture2D fantasmaLeft, Texture2D fantasmaRight, Vector2 enemyPositionplat, float *temporaryplat){
        if(enemyPositionplat.x >= *temporaryplat){
            DrawTextureRec(
                fantasmaLeft,
                (Rectangle){0.0f, 0.0f, (float)fantasmaLeft.width, (float)fantasmaLeft.height},
                (Vector2){enemyPositionplat.x-25, enemyPositionplat.y - 22},
                WHITE
            );
        }
        else if(enemyPositionplat.x < *temporaryplat){
            DrawTextureRec(
                fantasmaRight,
                (Rectangle){0.0f, 0.0f, (float)fantasmaRight.width, (float)fantasmaRight.height},
                (Vector2){enemyPositionplat.x - 25, enemyPositionplat.y - 22},
                WHITE
            );
        }
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //dentro do while
        if(gameStage == INTRODUCAO || gameStage == CONTROLES || gameStage == TEXTO1 ){
            UpdateMusicStream(musictema);//music
            //volume
            if (IsKeyDown(KEY_M)) volume -= 0.01f;
            else if (IsKeyDown(KEY_N)) volume += 0.01f;
            SetMusicVolume(musictema, volume);
        }

        if(gameStage == LABIRINTO || gameStage == TEXTO2 ){
            UpdateMusicStream(musiclab);//music
            //volume
            if (IsKeyDown(KEY_M) && !IsKeyDown(KEY_A)) volume -= 0.01f;
            else if (IsKeyDown(KEY_N)) volume += 0.01f;
            SetMusicVolume(musiclab, volume);
        }

        if(gameStage == PLATAFORMA && finish == 0){
            UpdateMusicStream(music);//music
            //volume
            if (IsKeyDown(KEY_M)) volume -= 0.01f;
            else if (IsKeyDown(KEY_N)) volume += 0.01f;
            SetMusicVolume(music, volume);
        }

        if(gameStage == PLATAFORMA && finish == 1 && lifes > 0){
            UpdateMusicStream(musicWin);//music
            //volume
            if (IsKeyDown(KEY_M)) volume -= 0.01f;
            else if (IsKeyDown(KEY_N)) volume += 0.01f;
            SetMusicVolume(musicWin, volume);
        }

        if(gameStage == PLATAFORMA && finish == 1 && lifes <= 0){
            UpdateMusicStream(musicLose);//music
            //volume
            if (IsKeyDown(KEY_M)) volume -= 0.01f;
            else if (IsKeyDown(KEY_N)) volume += 0.01f;
            SetMusicVolume(musicLose, volume);
        }

        if(gameStage == INTRODUCAO){
            //Introducao
            introducaoLogic(castle, &castleFramesCounter, castleFramesSpeed, &castleCurrentFrame, &castleFrameRec, &framesCounter, &gameStage);
        }
        if(gameStage == CONTROLES){
            controlsLogic(&gameStage);
        }
        if(gameStage == TEXTO1){
            textLogic(&framesCounter, &gameStage);
        }
        if(gameStage == LABIRINTO){
            controlHero(&ballPosition.x,&ballPosition.y);
            controlEnemys(soltaInimigo1,soltaInimigo2,ballPosition.x,ballPosition.y
            ,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y);

            //entrada
            if(ballPosition.x <= 0){
                deathHero(&books,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }

            if (!hacker()){
                //colisoes com o terreno (hero)
                collisionHero(&gameStage, &books,ballPosition,&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power);               
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

        if(gameStage == PLATAFORMA){
            float deltaTime = GetFrameTime();
            framesCounterTime++;
            UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
            //fantasmas
            if(player.position.x > enemyPositionplat.x) enemyPositionplat.x += 0.70f;
            if(player.position.x < enemyPositionplat.x) enemyPositionplat.x -= 0.70f;
            if(player.position.y > enemyPositionplat.y) enemyPositionplat.y += 0.70f;
            if(player.position.y < enemyPositionplat.y) enemyPositionplat.y -= 0.70f;
    
            if(player.position.x > enemyPosition2plat.x) enemyPosition2plat.x += 0.85f;
            if(player.position.x < enemyPosition2plat.x) enemyPosition2plat.x -= 0.85f;
            if(player.position.y > enemyPosition2plat.y) enemyPosition2plat.y += 0.85f;
            if(player.position.y < enemyPosition2plat.y) enemyPosition2plat.y -= 0.85f;
            //bolas de fogo
    
            if(fireBall1.y >= (-60) && gatilho == 0){
                fireBall1.y -= 3.0f;
                if(fireBall1.y <= (-60)) gatilho=1;
            }
            else{
                fireBall1.y += 3.0f;
                if(fireBall1.y >= 460) gatilho=0;
            } 
    
            if(fireBall2.y >= (-60) && gatilho2 == 0){
                fireBall2.y -= 3.0f;
                if(fireBall2.y <= (-60)) gatilho2=1;
            }
            else{
                fireBall2.y += 3.0f;
                if(fireBall2.y >= 460) gatilho2=0;
            } 
    
            if(fireBall3.y >= (-60) && gatilho3 == 0){
                fireBall3.y -= 3.0f;
                if(fireBall3.y <= (-60)) gatilho3=1;
            }
            else{
                fireBall3.y += 3.0f;
                if(fireBall3.y >= 460) gatilho3=0;
            }
        }

        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if(gameStage == INTRODUCAO){
                //introducao
                introducao(background, castle, playButton, whitePlayButton, controlsButton, whiteControlsButton, exitButton, whiteExitButton, &castleFrameRec, castlePosition, message, framesCounter);
            }
            if(gameStage == CONTROLES){
                drawControls(controls,background,castle,castlePosition, castleFrameRec, backButton, whiteBackButton);
            }
            if(gameStage == TEXTO1){
                drawText(background, castle, castlePosition, castleFrameRec,secondMessage, framesCounter);
            }
            if(gameStage == LABIRINTO){
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

            if(gameStage == PLATAFORMA){
                float time = GetFrameTime();
            
                if(!(finish == 1)){
                    //background completo
                    float a = 0, b = 0; 
                    int cont = 0;
                    for(int i = 0; i<50; i++){
                        DrawTextureRec(fundo, (Rectangle){0.0f, 0.0f, (float)fundo.width, (float)fundo.height}, (Vector2){a, b}, WHITE);
                        cont++;
                        a+=80;
                        if(cont == 10){
                            cont = 0;
                            a = 0;
                            b+=80;
                        }
                    } 
                    //pisos sem textura
                    for (int i = 0; i < envItemsLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);
                    //pisos com textura
                    DrawTextureRec(porta, (Rectangle){0.0f, 0.0f, (float)porta.width, (float)porta.height}, (Vector2){7, 25}, WHITE); 
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)530, (float)340}, WHITE);//1
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)224, (float)173}, WHITE);//3
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)222, (float)289}, WHITE);//4
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)395, (float)252}, WHITE);//6
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)544, (float)145}, WHITE);//7
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)683, (float)280}, WHITE);//8
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)0, (float)300}, WHITE);//10
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)40, (float)180}, WHITE);//11
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)357, (float)81}, WHITE);//12
                    float c = 0;
                    for(int i = 0; i<9; i++){
                        DrawTextureRec(lava, (Rectangle){0.0f, 0.0f, (float)lava.width, (float)lava.height}, (Vector2){c, (float)370}, WHITE);//2
                        c+=80;
                    }


                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)0, (float)80}, WHITE);//5
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)80, (float)80}, WHITE);//5

                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)683, (float)61}, WHITE);//9
                    DrawTextureRec(piso, (Rectangle){0.0f, 0.0f, (float)piso.width, (float)piso.height}, (Vector2){(float)763, (float)61}, WHITE);//9




                    Rectangle playerRect = { player.position.x - 20, player.position.y - 40, 40, 40 };
                    DrawCircleV(enemyPositionplat, 7, DARKBLUE);
                    DrawCircleV(enemyPosition2plat, 7, DARKBLUE);

                    //limitando as laterais
                    if(player.position.x < 0) player.position.x = 0;
                    if(player.position.x > screenWidth) player.position.x = screenWidth;

                    // DrawCircleV(fireBall1, 15, RED);
                    // DrawTextureRec(
                    //     fireballUp,
                    //     (Rectangle){0.0f, 0.0f, fireballUp.width, fireballUp.height}, 
                    //     (Vector2){fireBall1.x - 22, fireBall1.y - 32},
                    //     WHITE);
                    drawFireBall(fireballUp, fireballDown, fireBall1, &aux1);
                     

                    // DrawCircleV(fireBall2, 15, RED);
                    // DrawTextureRec(
                    //     fireballUp,
                    //     (Rectangle){0.0f, 0.0f, fireballUp.width, fireballUp.height}, 
                    //     (Vector2){fireBall2.x - 22, fireBall2.y - 32},
                    //     WHITE);
                    drawFireBall(fireballUp, fireballDown, fireBall2, &aux1);
                    

                    // DrawCircleV(fireBall3, 15, RED);
                    // DrawTextureRec(
                    //     fireballUp,
                    //     (Rectangle){0.0f, 0.0f, fireballUp.width, fireballUp.height}, 
                    //     (Vector2){fireBall3.x - 22, fireBall3.y - 32},
                    //     WHITE);
                    drawFireBall(fireballUp, fireballDown, fireBall3, &aux1);
                    aux1 = fireBall3.y;


                    DrawRectangleRec(playerRect, RED);

                    drawFantasma(fantasmaRight, fantasmaLeft, enemyPositionplat, &temporaryplat);
                    temporaryplat = enemyPositionplat.x;

                    drawFantasma(fantasmaRight, fantasmaLeft, enemyPosition2plat, &temporary2plat);
                    temporary2plat = enemyPosition2plat.x;

                    //colisoes c inimigo
                    if(CheckCollisionCircleRec(enemyPositionplat, 7, playerRect)){
                        deathHero2(&framesCounterTime,&player.position.x,&player.position.y,&enemyPositionplat.x,&enemyPositionplat.y,&enemyPosition2plat.x,&enemyPosition2plat.y,&lifes);
                    }
                    if(CheckCollisionCircleRec(enemyPosition2plat, 7, playerRect)){
                        deathHero2(&framesCounterTime,&player.position.x,&player.position.y,&enemyPositionplat.x,&enemyPositionplat.y,&enemyPosition2plat.x,&enemyPosition2plat.y,&lifes);
                    }
                    if(CheckCollisionCircleRec(fireBall1, 15, playerRect)){
                        deathHero2(&framesCounterTime,&player.position.x,&player.position.y,&enemyPositionplat.x,&enemyPositionplat.y,&enemyPosition2plat.x,&enemyPosition2plat.y,&lifes);
                    }
                    if(CheckCollisionCircleRec(fireBall2, 15, playerRect)){
                        deathHero2(&framesCounterTime,&player.position.x,&player.position.y,&enemyPositionplat.x,&enemyPositionplat.y,&enemyPosition2plat.x,&enemyPosition2plat.y,&lifes);
                    }
                    if(CheckCollisionCircleRec(fireBall3, 15, playerRect)){
                        deathHero2(&framesCounterTime,&player.position.x,&player.position.y,&enemyPositionplat.x,&enemyPositionplat.y,&enemyPosition2plat.x,&enemyPosition2plat.y,&lifes);
                    }
                    if(player.position.y == 370){
                        deathHero2(&framesCounterTime,&player.position.x,&player.position.y,&enemyPositionplat.x,&enemyPositionplat.y,&enemyPosition2plat.x,&enemyPosition2plat.y,&lifes);
                    }

                    // DrawText(TextFormat("Lifes: %d",lifes), 700, 110, 23, BLACK);
                    // DrawTextureRec(
                    //     heart,
                    //     (Rectangle){0.0f, 0.0f, heart.width, heart.height}, 
                    //     (Vector2){700, 170},
                    //     WHITE);
                    drawHearts(heart, &lifes);
                    // DrawText(TextFormat("Tempo: %d", 30 - (framesCounterTime/60)), 350, 20, 25, BLACK);
                    drawTimer(&framesCounterTime);

                    if(lifes <= 0) finish = 1;
                    else if((framesCounterTime/60) == 30) finish = 1;
                }
                else if(lifes > 0){    
                    ClearBackground(SKYBLUE);
                    DrawText(TextFormat("YOU WIN"), 400, 200, 32, BLACK); 
                }
                else{
                    ClearBackground(SKYBLUE);
                    DrawText(TextFormat("YOU LOSE"), 400, 200, 32, BLACK);
                }
            }
        EndDrawing();
    }
    

    UnloadMusicStream(music);//close music
    UnloadMusicStream(musiclab);//close music
    UnloadMusicStream(musictema);//close music
    UnloadMusicStream(musicWin);//close music
    UnloadMusicStream(musicLose);//close music
    CloseAudioDevice();//para audio
    CloseWindow();  // Close window and OpenGL context
    free(mapa);
    return 0;
}

