#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *title = "Joguinho";

    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle(title);
    
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 6.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 6.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 6.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 6.0f;
        
        BeginDrawing();

            ClearBackground(SKYBLUE);

            DrawText("USE AS SETAS PARA MOVER", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();  // Close window and OpenGL context
    return 0;
}
