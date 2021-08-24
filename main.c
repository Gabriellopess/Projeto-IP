#include "raylib.h"
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

    //A partir daqui os diagonais....
    Rectangle dia1 = {(float)116, (float)258, (float)12, (float)12};
    Rectangle dia2 = {(float)108, (float)265, (float)13, (float)13};
    Rectangle dia3 = {(float)95, (float)278, (float)13, (float)13};
    Rectangle dia4 = {(float)72, (float)221, (float)13, (float)13};
    Rectangle dia5 = {(float)59, (float)234, (float)13, (float)13};
    Rectangle dia6 = {(float)5, (float)141, (float)13, (float)13};
    Rectangle dia7 = {(float)18, (float)154, (float)13, (float)13};
    Rectangle dia8 = {(float)31, (float)163, (float)13, (float)13};
    Rectangle dia9 = {(float)44, (float)175, (float)13, (float)13};
    Rectangle dia10 = {(float)57, (float)185, (float)13, (float)13};
    Rectangle dia11 = {(float)70, (float)194, (float)13, (float)13};
    Rectangle dia12 = {(float)70, (float)112, (float)13, (float)13};
    Rectangle dia13 = {(float)83, (float)124, (float)13, (float)13};
    Rectangle dia14 = {(float)96, (float)135, (float)13, (float)13};
    Rectangle dia15 = {(float)106, (float)143, (float)13, (float)13};
    Rectangle dia16 = {(float)522, (float)232, (float)13, (float)13};
    Rectangle dia17 = {(float)509, (float)245, (float)13, (float)13};
    Rectangle dia18 = {(float)496, (float)258, (float)13, (float)13};
    Rectangle dia19 = {(float)483, (float)271, (float)13, (float)13};
    Rectangle dia20 = {(float)552, (float)303, (float)13, (float)13};
    Rectangle dia21 = {(float)539, (float)316, (float)13, (float)13};
    Rectangle dia22 = {(float)526, (float)329, (float)13, (float)13};
    Rectangle dia23 = {(float)513, (float)342, (float)13, (float)13};
    Rectangle dia24 = {(float)500, (float)355, (float)13, (float)13};
    Rectangle dia25 = {(float)487, (float)368, (float)13, (float)13};
    Rectangle dia26 = {(float)634, (float)170, (float)13, (float)13};
    Rectangle dia27 = {(float)647, (float)183, (float)13, (float)13};
    Rectangle dia28 = {(float)658, (float)197, (float)13, (float)13};
    Rectangle dia29 = {(float)669, (float)210, (float)13, (float)13};
    Rectangle dia30 = {(float)680, (float)223, (float)13, (float)13};
    Rectangle dia31 = {(float)691, (float)236, (float)13, (float)13};
    Rectangle dia32 = {(float)703, (float)249, (float)13, (float)13};
    Rectangle dia33 = {(float)713, (float)262, (float)13, (float)13};
    Rectangle dia34 = {(float)721, (float)271, (float)13, (float)13};
    Rectangle dia35 = {(float)730, (float)281, (float)12, (float)12};

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
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec6)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
            } 
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec7)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356);
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
            }
        
            if(CheckCollisionCircleRec(ballPosition, RAIO, rec28)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
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


            if(CheckCollisionCircleRec(ballPosition, RAIO, dia1)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia2)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia3)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia4)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia5)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia6)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia7)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia8)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia9)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia10)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia11)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia12)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia13)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia14)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia15)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia16)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia17)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia18)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia19)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia20)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia21)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia22)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia23)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia24)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia25)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia26)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia27)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia28)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia29)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia30)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia31)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia32)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia33)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia34)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
            }
            if(CheckCollisionCircleRec(ballPosition, RAIO, dia35)){
                deathHero(&ballPosition.x,&ballPosition.y,&soltaInimigo1,&soltaInimigo2,&book3,&power,33,356); 
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

            DrawRectangleRec(dia1, BLACK);
            DrawRectangleRec(dia2, BLACK);
            DrawRectangleRec(dia3, BLACK);
            DrawRectangleRec(dia4, BLACK);
            DrawRectangleRec(dia5, BLACK);
            DrawRectangleRec(dia6, BLACK);
            DrawRectangleRec(dia7, BLACK);
            DrawRectangleRec(dia8, BLACK);
            DrawRectangleRec(dia9, BLACK);
            DrawRectangleRec(dia10, BLACK);
            DrawRectangleRec(dia11, BLACK);
            DrawRectangleRec(dia12, BLACK);
            DrawRectangleRec(dia13, BLACK);
            DrawRectangleRec(dia14, BLACK);
            DrawRectangleRec(dia15, BLACK);
            DrawRectangleRec(dia16, BLACK);
            DrawRectangleRec(dia17, BLACK);
            DrawRectangleRec(dia18, BLACK);
            DrawRectangleRec(dia19, BLACK);
            DrawRectangleRec(dia20, BLACK);
            DrawRectangleRec(dia21, BLACK);
            DrawRectangleRec(dia22, BLACK);
            DrawRectangleRec(dia23, BLACK);
            DrawRectangleRec(dia24, BLACK);
            DrawRectangleRec(dia25, BLACK);
            DrawRectangleRec(dia26, BLACK);
            DrawRectangleRec(dia27, BLACK);
            DrawRectangleRec(dia28, BLACK);
            DrawRectangleRec(dia29, BLACK);
            DrawRectangleRec(dia30, BLACK);
            DrawRectangleRec(dia31, BLACK);
            DrawRectangleRec(dia32, BLACK);
            DrawRectangleRec(dia33, BLACK);
            DrawRectangleRec(dia34, BLACK);
            DrawRectangleRec(dia35, BLACK);

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
}
