#include "raylib.h"

#define MAX_FONTS 8

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - raylib fonts");

    int framesCounter = 0;

    Font pixelplay = LoadFont("../raylib/examples/text/resources/fonts/pixelplay.png");

    const char messages[1000] = "Bem vindo ao Reino do CIn, discípulo!\nSua primeira missão como aprendiz de Matemática Discreta\nserá recuperar os 3 livros dos autores favoritos da Princesa Anjolinda:\nRosen, Lovász e Knuth, que estão perdidos no labirinto do castelo,\nprotegidos por fantasmas e paredes amaldiçoadas.\nBoa sorte! Que Fermat o proteja.";

    const int spacing [6] = {2.7,2.7,2.7,2.7,2.7,2.7};

    /*Vector2 position[6] = { 0 }; 

    for (int i = 0; i < 6; i++) {
        position[i].x = screenWidth/2.0f - MeasureTextEx(pixelplay, messages[i], pixelplay.baseSize*2.0f, (float)spacing[i]).x/2.0f;
        position[i].y = 60.0f + pixelplay.baseSize + 45.0f*i;
    }  */

    Color color = BLACK;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
        else framesCounter++;

        if (IsKeyPressed(KEY_ENTER)) framesCounter = 0;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (int i = 0; i < 6; i++) {
                DrawText(TextSubtext(messages, 0, framesCounter/10), 210, 160, 20, MAROON);
                //DrawTextEx(pixelplay, messages[i], position[i], pixelplay.baseSize*2.0f, (float)spacing[i], color);
            }
            //DrawText("PRESS [SPACE] to SPEED UP!", 239, 300, 20, LIGHTGRAY);
           
        EndDrawing();
    }

    CloseWindow();                 

    return 0;
}