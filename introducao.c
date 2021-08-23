#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - text writing anim");

    const char message[100] = "Teste lalalala historinha bla bla bla\nbla bla bla bla";

    int framesCounter = 0;

    SetTargetFPS(60); 
    
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
        else framesCounter++;
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(TextSubtext(message, 0, framesCounter/10), 400, 50, 20, MAROON);
            DrawText("PRESSIONE [ESPAÇO] PARA ADIANTAR!", 239, 300, 20, LIGHTGRAY);
            DrawText("PRESSIONE [PLAY] PARA JOGAR!", 239, 340, 20, LIGHTGRAY);
            

        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}