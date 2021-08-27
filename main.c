/*#include "raylib.h"
#include "enemy.h"
#include "hero.h"

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



    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle(title);
    
    Vector2 ballPosition = { (float)33, (float)356 };
    Vector2 enemyPosition2;
    Vector2 enemyPosition;


    //mapa
    Vector2 bullshit = {(float)0, (float)0};

    Rectangle rec1 = {(float)0, (float)381, (float)800, (float)20};
    Rectangle rec2 = {(float)0, (float)316, (float)207, (float)20};
    Rectangle rec3 = {(float)76, (float)291, (float)20, (float)40};
    Rectangle rec4 = {(float)122, (float)252, (float)20, (float)60};
    Rectangle rec5 = {(float)85, (float)208, (float)20, (float)60};
    Rectangle rec6 = {(float)39, (float)247, (float)15, (float)18};
    Rectangle rec7 = {(float)0, (float)204, (float)98, (float)20};
    Rectangle rec8 = {(float)96, (float)204, (float)22, (float)130};
    Rectangle rec9 = {(float)127, (float)146, (float)22, (float)80};
    Rectangle rec10 = {(float)52, (float)71, (float)22, (float)40};
    Rectangle rec11 = {(float)0, (float)0, (float)800, (float)20};
    Rectangle rec12 = {(float)186, (float)10, (float)20, (float)148};
    Rectangle rec13 = {(float)186, (float)215, (float)20, (float)55};
    Rectangle rec14 = {(float)186, (float)204, (float)70, (float)20};
    Rectangle rec15 = {(float)250, (float)154, (float)20, (float)70};
    Rectangle rec16 = {(float)250, (float)270, (float)20, (float)114};
    Rectangle rec17 = {(float)250, (float)270, (float)168, (float)20};
    Rectangle rec18 = {(float)315, (float)197, (float)20, (float)90};
    Rectangle rec19 = {(float)315, (float)110, (float)20, (float)40};
    Rectangle rec20 = {(float)250, (float)95, (float)220, (float)20};
    Rectangle rec21 = {(float)400, (float)20, (float)20, (float)90};
    Rectangle rec22 = {(float)410, (float)270, (float)20, (float)65};
    Rectangle rec23 = {(float)384, (float)154, (float)20, (float)70};
    Rectangle rec24 = {(float)384, (float)154, (float)80, (float)20};
    Rectangle rec25 = {(float)464, (float)154, (float)20, (float)150};
    Rectangle rec26 = {(float)484, (float)214, (float)67, (float)20};
    Rectangle rec27 = {(float)535, (float)219, (float)20, (float)100};
    Rectangle rec28 = {(float)535, (float)20, (float)20, (float)110};
    Rectangle rec29 = {(float)565, (float)290, (float)20, (float)150};
    Rectangle rec30 = {(float)565, (float)290, (float)20, (float)100};
    Rectangle rec31 = {(float)565, (float)290, (float)80, (float)20};
    Rectangle rec32 = {(float)618, (float)90, (float)188, (float)20};
    Rectangle rec33 = {(float)618, (float)90, (float)20, (float)80};
    Rectangle rec34 = {(float)790, (float)90, (float)20, (float)365};
    Rectangle rec35 = {(float)0, (float)0, (float)8, (float)320};
    Rectangle rec36 = {(float)618, (float)165, (float)20, (float)180};

    //venenos
    Rectangle veneno = {(float)410, (float)335, (float)20, (float)46};
    Rectangle veneno2 = {(float)52, (float)20, (float)22, (float)51};
    Rectangle veneno3 = {(float)618, (float)20, (float)20, (float)70};

    //area segura
    Rectangle areaSeguranca = {(float)33, (float)335, (float)60, (float)45};
    Rectangle areaSeguranca2 = {(float)700, (float)110, (float)90, (float)45};
    Rectangle areaSeguranca3 = {(float)300, (float)20, (float)100, (float)75};

    //books
    Rectangle actGhost1 = {(float)15, (float)280, (float)25, (float)25};
    Rectangle actGhost2 = {(float)275, (float)300, (float)25, (float)25};
    Rectangle actGhost3 = {(float)650, (float)120, (float)25, (float)25};

    //mascara de gas
    Rectangle mask = {(float)20, (float)30, (float)25, (float)25};

    //saida
    Rectangle door = {(float)780, (float)20, (float)20, (float)70};


    SetTargetFPS(60); // Set our game to run at 60 frames-per-second


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 3.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 3.0f;
        
        if(soltaInimigo1 == 0){
            resetEnemy(&enemyPosition.x,&enemyPosition.y,450,80);
        }

        if(soltaInimigo2 == 0){
            resetEnemy(&enemyPosition2.x,&enemyPosition2.y,600,356);
        }


        if(soltaInimigo1 == 1){
            if(ballPosition.x > enemyPosition.x) enemyPosition.x += 0.25f;
            if(ballPosition.x < enemyPosition.x) enemyPosition.x -= 0.25f;
            if(ballPosition.y > enemyPosition.y) enemyPosition.y += 0.25f;
            if(ballPosition.y < enemyPosition.y) enemyPosition.y -= 0.25f;
        }
        
        if(soltaInimigo2 == 1){
            if(ballPosition.x > enemyPosition2.x) enemyPosition2.x += 0.25f;
            if(ballPosition.x < enemyPosition2.x) enemyPosition2.x -= 0.25f;
            if(ballPosition.y > enemyPosition2.y) enemyPosition2.y += 0.25f;
            if(ballPosition.y < enemyPosition2.y) enemyPosition2.y -= 0.25f;
        }

        //entrada
        if(ballPosition.x <= 0){
            deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
        }

        if (!hacker()){
            //colisoes com o terreno
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec1)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec2)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec3)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }/*
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec4)){
                ballPosition.x = 33;
                ballPosition.y= 356; 
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec5)){
                ballPosition.x = 33;
                ballPosition.y= 356; 
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec6)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec7)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }
            /*if(CheckCollisionCircleRec(ballPosition, RAIO, rec8)){
                ballPosition.x = 33;
                ballPosition.y= 356; 
            } */
            /*if(CheckCollisionCircleRec(ballPosition, RAIO, rec9)){
                ballPosition.x = 33;
                ballPosition.y= 356;
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec10)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec11)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec12)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec13)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec14)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec15)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec16)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec17)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec18)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec19)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec20)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec21)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec22)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec23)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec24)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec25)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec26)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }/*
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec27)){
                ballPosition.x = 33;
                ballPosition.y= 356; 
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec28)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec29)){
                ballPosition.x = 33;
                ballPosition.y= 356; 
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec30)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec31)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec32)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec33)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec34)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec35)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            } 
                if(CheckCollisionCircleRec(ballPosition, RAIO, rec36)){
                ballPosition.x = 33;
                ballPosition.y= 356; 
            } 
            
            //area de segurança

            if(CheckCollisionCircleRec(enemyPosition, RAIO, areaSeguranca)){
                resetEnemy(&enemyPosition.x,&enemyPosition.y,450,80);
            }
            if(CheckCollisionCircleRec(enemyPosition2, RAIO, areaSeguranca)){
                resetEnemy(&enemyPosition2.x,&enemyPosition2.y,600,356);
            }

            if(CheckCollisionCircleRec(enemyPosition, RAIO, areaSeguranca2)){
                resetEnemy(&enemyPosition.x,&enemyPosition.y,450,80);
            }
            if(CheckCollisionCircleRec(enemyPosition2, RAIO, areaSeguranca2)){
                resetEnemy(&enemyPosition2.x,&enemyPosition2.y,600,356);
            }

            if(CheckCollisionCircleRec(enemyPosition, RAIO, areaSeguranca3)){
                resetEnemy(&enemyPosition.x,&enemyPosition.y,450,80);
            }
            if(CheckCollisionCircleRec(enemyPosition2, RAIO, areaSeguranca3)){
                resetEnemy(&enemyPosition2.x,&enemyPosition2.y,600,356);
            }

            //books
            if(CheckCollisionCircleRec(ballPosition, RAIO, actGhost1)) soltaInimigo1 =1;
            if(CheckCollisionCircleRec(ballPosition, RAIO, actGhost2)) soltaInimigo2 =1;
            if(CheckCollisionCircleRec(ballPosition, RAIO, actGhost3)) book3 =1;                

            //colisao com inimigo
            if(CheckCollisionCircles(ballPosition, RAIO, enemyPosition, RAIO) && soltaInimigo1 == 1){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }

            if(CheckCollisionCircles(ballPosition, RAIO, enemyPosition2, RAIO) && soltaInimigo2 == 1){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            }
            
            //mascara
            if(CheckCollisionCircleRec(ballPosition, RAIO, mask)) power =1;


            //saida
            if(CheckCollisionCircleRec(ballPosition, RAIO, door) && soltaInimigo1 == 1 && soltaInimigo2 == 1 
            && book3 == 1){
                CloseWindow();;
            } 
            else if(CheckCollisionCircleRec(ballPosition, RAIO, door)){
                ballPosition.x = 770;
            }

            //veneno
            if (!powerPoison(power)){
                if(CheckCollisionCircleRec(ballPosition, RAIO, veneno) 
                || CheckCollisionCircleRec(ballPosition, RAIO, veneno2)
                || CheckCollisionCircleRec(ballPosition, RAIO, veneno3)){

                    deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
                }

            }
            
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleRec(rec1, RED);
            DrawRectangleRec(rec2, RED);
            DrawRectangleRec(rec3, RED);
            DrawRectanglePro(rec4, bullshit, 50, RED); 
            DrawRectanglePro(rec5, bullshit, 50, RED);
            DrawRectangleRec(rec6, RED);
            DrawRectangleRec(rec7, RED);
            DrawRectanglePro(rec8, bullshit, -230, RED); 
            DrawRectanglePro(rec9, bullshit, -230, RED); 
            DrawRectangleRec(rec10, RED);
            DrawRectangleRec(rec11, RED);
            DrawRectangleRec(rec12, RED);
            DrawRectangleRec(rec13, RED);
            DrawRectangleRec(rec14, RED);
            DrawRectangleRec(rec15, RED);
            DrawRectangleRec(rec16, RED);
            DrawRectangleRec(rec17, RED);
            DrawRectangleRec(rec18, RED);
            DrawRectangleRec(rec19, RED);
            DrawRectangleRec(rec20, RED);
            DrawRectangleRec(rec21, RED);
            DrawRectangleRec(rec22, RED);
            DrawRectangleRec(rec23, RED);
            DrawRectangleRec(rec24, RED);
            DrawRectangleRec(rec25, RED);
            DrawRectangleRec(rec26, RED);
            DrawRectanglePro(rec27, bullshit, 45, RED);
            DrawRectangleRec(rec28, RED);
            DrawRectanglePro(rec29, bullshit, 45, RED);
            DrawRectangleRec(rec30, RED);
            DrawRectangleRec(rec31, RED);
            DrawRectangleRec(rec32, RED);
            DrawRectangleRec(rec33, RED);
            DrawRectangleRec(rec34, RED);
            DrawRectangleRec(rec35, RED);
            DrawRectanglePro(rec36, bullshit, -40, RED);

            DrawRectangleRec(veneno, GREEN);
            DrawRectangleRec(veneno2, GREEN);
            DrawRectangleRec(veneno3, GREEN);

            DrawRectangleRec(areaSeguranca, PINK);
            DrawRectangleRec(areaSeguranca2, PINK);
            DrawRectangleRec(areaSeguranca3, PINK);

            if(power == 0) DrawRectangleRec(mask, PURPLE);

            DrawRectangleRec(door, GRAY);



            if(soltaInimigo1 == 0) DrawRectangleRec(actGhost1, ORANGE);
            if(soltaInimigo2 == 0) DrawRectangleRec(actGhost2, ORANGE);
            if(book3 == 0) DrawRectangleRec(actGhost3, ORANGE);
            


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
    return 0;
}*/