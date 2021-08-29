#include "raylib.h"
#include "hero.h"
#define G 400
#define VELOC_PULO_JOG 300.0f
#define VELOC_HORIZ_JOG 150.0f
 
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
 
int main() {
    const int screenWidth = 800;
    const int screenHeight = 400;
    const char *title = "Joguinho";
    int gatilho=0;
    int gatilho2=0;
    int gatilho3=0;
    float temporary = 0, temporary2 = 0;
    int lifes = 5;
    int finish =0;
 
 
 
    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle(title);
    //music antes while
    InitAudioDevice();
    Music music = LoadMusicStream("assets/music3.mp3");
    float volume = 0.5f;
    PlayMusicStream(music);
 
    Texture2D porta = LoadTexture("assets/portinha.png");
    Texture2D piso= LoadTexture("assets/pisinho.png");
    Texture2D fundo = LoadTexture("assets/fundin.png");
    Texture2D lava = LoadTexture("assets/lava.png");
    Texture2D fantasma1 = LoadTexture("assets/fantasmaLeftSprite50x50.png");
    Texture2D fantasma2 = LoadTexture("assets/fantasmaSprite50x50.png");
 
 
    Vector2 enemyPosition2 = { (float)33, (float)356 };
    Vector2 enemyPosition = { (float)600, (float)20 };
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
 
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
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
 
void drawFantasma(Texture2D fantasma1, Texture2D fantasma2, Vector2 enemyPosition, float *temporary){
    if(enemyPosition.x >= *temporary){
        DrawTextureRec(
            fantasma1,
            (Rectangle){0.0f, 0.0f, (float)fantasma1.width, (float)fantasma1.height},
            (Vector2){enemyPosition.x-25, enemyPosition.y - 22},
            WHITE
        );
    }
    else if(enemyPosition.x < *temporary){
        DrawTextureRec(
            fantasma2,
            (Rectangle){0.0f, 0.0f, (float)fantasma2.width, (float)fantasma2.height},
            (Vector2){enemyPosition.x - 25, enemyPosition.y - 22},
            WHITE
        );
    }
}
/*
void drawFireBall(Texture2D fireball, Vector2 fire){
    if(y == -60){
        DrawTextureV(balldown, fire, WHITE);
    }
    if(y == 460){
        DrawTextureV(ballup, fire, WHITE);
    }
}
*/
 
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float deltaTime = GetFrameTime();
 
        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
        UpdateMusicStream(music);//music
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
 
 
        BeginDrawing();
 
            
            int tempo = GetTime();
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
                DrawCircleV(enemyPosition, 7, DARKBLUE);
                DrawCircleV(enemyPosition2, 7, DARKBLUE);
                DrawCircleV(fireBall1, 15, RED);
                DrawCircleV(fireBall2, 15, RED);
                DrawCircleV(fireBall3, 15, RED);
                DrawRectangleRec(playerRect, RED);

                drawFantasma(fantasma2, fantasma1, enemyPosition, &temporary);
                temporary = enemyPosition.x;

                drawFantasma(fantasma2, fantasma1, enemyPosition2, &temporary2);
                temporary2 = enemyPosition2.x;

                DrawText(TextFormat("Tempo: %d", 30 - tempo), 350, 20, 18, BLACK);


                //colisoes c inimigo
                if(CheckCollisionCircleRec(enemyPosition, 7, playerRect)){
                    deathHero2(&player.position.x,&player.position.y,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y,&lifes);
                }
                if(CheckCollisionCircleRec(enemyPosition2, 7, playerRect)){
                    deathHero2(&player.position.x,&player.position.y,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y,&lifes);
                }
                if(CheckCollisionCircleRec(fireBall1, 15, playerRect)){
                    deathHero2(&player.position.x,&player.position.y,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y,&lifes);
                }
                if(CheckCollisionCircleRec(fireBall2, 15, playerRect)){
                    deathHero2(&player.position.x,&player.position.y,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y,&lifes);
                }
                if(CheckCollisionCircleRec(fireBall3, 15, playerRect)){
                    deathHero2(&player.position.x,&player.position.y,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y,&lifes);
                }
                if(player.position.y == 370){
                    deathHero2(&player.position.x,&player.position.y,&enemyPosition.x,&enemyPosition.y,&enemyPosition2.x,&enemyPosition2.y,&lifes);
                }

                DrawText(TextFormat("Lifes: %d",lifes), 700, 110, 23, BLACK);
                if(lifes <= 0) finish =1;
                else if(tempo == 30) finish =1;
            }
            else if(lifes > 0){    
                ClearBackground(SKYBLUE);
                DrawText(TextFormat("YOU WIN"), 400, 200, 32, BLACK); 
            }
            else{
                ClearBackground(SKYBLUE);
                DrawText(TextFormat("YOU LOSE"), 400, 200, 32, BLACK);
            }
        EndDrawing();
 
    }
 
 
    UnloadMusicStream(music);//close music
    CloseAudioDevice();//para audio
    CloseWindow();  
    return 0;
} 