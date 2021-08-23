#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 400;
    const char *title = "Joguinho";


    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle(title);

    Vector2 ballPosition = { (float)33, (float)356 };
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


    SetTargetFPS(60); // Set our game to run at 60 frames-per-second


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 4.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 4.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 4.0f;
        
        BeginDrawing();

            ClearBackground(SKYBLUE);

            DrawCircleV(ballPosition, 7, BLACK);


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
            DrawText("USE AS SETAS PARA MOVER", 10, 30, 20, DARKGRAY);


            

        EndDrawing();

        if(CheckCollisionCircleRec(ballPosition, 10, rec1)){
            ballPosition.x = 33;
            ballPosition.y= 356;
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec2)){
            ballPosition.x = 33;
            ballPosition.y= 356;
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec3)){
            ballPosition.x = 33;
            ballPosition.y= 356;
        }/*
         if(CheckCollisionCircleRec(ballPosition, 10, rec4)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } 
         if(CheckCollisionCircleRec(ballPosition, 10, rec5)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } */
         if(CheckCollisionCircleRec(ballPosition, 10, rec6)){
            ballPosition.x = 33;
            ballPosition.y= 356;
        } 
         if(CheckCollisionCircleRec(ballPosition, 10, rec7)){
            ballPosition.x = 33;
            ballPosition.y= 356;
        }
         /*if(CheckCollisionCircleRec(ballPosition, 10, rec8)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } */
         /*if(CheckCollisionCircleRec(ballPosition, 10, rec9)){
            ballPosition.x = 33;
            ballPosition.y= 356;
        } */
         if(CheckCollisionCircleRec(ballPosition, 10, rec10)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec11)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec12)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec13)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec14)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec15)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec16)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec17)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec18)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec19)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec20)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec21)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec22)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec23)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec24)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec25)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
         if(CheckCollisionCircleRec(ballPosition, 10, rec26)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }/*
         if(CheckCollisionCircleRec(ballPosition, 10, rec27)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } */
         if(CheckCollisionCircleRec(ballPosition, 10, rec28)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }/*
         if(CheckCollisionCircleRec(ballPosition, 10, rec29)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } */
         if(CheckCollisionCircleRec(ballPosition, 10, rec30)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
        if(CheckCollisionCircleRec(ballPosition, 10, rec31)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
        if(CheckCollisionCircleRec(ballPosition, 10, rec32)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
        if(CheckCollisionCircleRec(ballPosition, 10, rec33)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
        if(CheckCollisionCircleRec(ballPosition, 10, rec34)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        }
        if(CheckCollisionCircleRec(ballPosition, 10, rec35)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } /*
             if(CheckCollisionCircleRec(ballPosition, 10, rec36)){
            ballPosition.x = 33;
            ballPosition.y= 356; 
        } */

    }

    CloseWindow();  // Close window and OpenGL context
    return 0;
}
