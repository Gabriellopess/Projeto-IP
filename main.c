#include "raylib.h"
#include "introducao.h"

//mingw32-make PLATFORM=PLATFORM_DESKTOP


int main() {
    const int screenWidth = 800;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60); 

    int castleCurrentFrame = 0;
    int castleFramesCounter = 0;
    int castleFramesSpeed = 1;
    float castleX = -40;
    float castleY = 49.52;

    char message[100] = "Teste lalalala historinha bla bla bla\nbla bla bla bla";
    int framesCounter = 0;

    Vector2 castlePosition = {castleX, castleY};
    Texture2D castle = LoadTexture("assets/castleSpriteRed.png");
    Rectangle castleFrameRec = {0.0f, 0.0f, (float)castle.width/2, (float)castle.height};

    while (!WindowShouldClose())
    {   

        introducaoLogic(castle, &castleFramesCounter, castleFramesSpeed, &castleCurrentFrame, &castleFrameRec, &framesCounter);       

        BeginDrawing();
            ClearBackground(RAYWHITE);
            introducao(castle, &castleFrameRec, castlePosition, message, framesCounter);

            // DrawText(TextFormat("castleFrame.x: %.2f", castleFrameRec.x), 50, 20, 10, RED);
            // DrawText(TextFormat("castleFrame.x: %d", castleFramesCounter), 50, 35, 20, RED);
        EndDrawing();
    }

    CloseWindow();        
    return 0;
}