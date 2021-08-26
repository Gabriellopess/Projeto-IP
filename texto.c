/*#include "raylib.h"
#define MAX_FONTS   100

int main() {
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - raylib fonts");

    Font fonts[MAX_FONTS] = { 0 };
    fonts[1] = LoadFont("C:/Users/camil/OneDrive/Desktop/jogo_ip/projeto/raylib/examples/text/C:/Users/camil/OneDrive/Desktop/jogo_ip/projeto/raylib/examples/text/resources/fonts/pixelplay.png");

    const char *messages[MAX_FONTS] = {"joguinho lallalala"};
    const int spacings[MAX_FONTS] = { 4 };

    Vector2 positions[MAX_FONTS] = { 0 };

    for (int i = 0; i < MAX_FONTS; i++)
    {
        positions[i].x = screenWidth/2.0f - MeasureTextEx(fonts[i], messages[i], fonts[i].baseSize*2.0f, (float)spacings[i]).x/2.0f;
        positions[i].y = 60.0f + fonts[i].baseSize + 45.0f*i;
    }

    Color colors[MAX_FONTS] = { DARKGREEN };
    SetTargetFPS(60);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < MAX_FONTS; i++)
            {
                DrawTextEx(fonts[i], messages[i], positions[i], fonts[i].baseSize*2.0f, (float)spacings[i], colors[i]);
            }

        EndDrawing();
    }

    for (int i = 0; i < MAX_FONTS; i++) UnloadFont(fonts[i]);

    CloseWindow();  // Close window and OpenGL context
    return 0;
}*/

#include "raylib.h"

#define MAX_FONTS   8

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - raylib fonts");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Font pixelplay = LoadFont("C:/Users/camil/OneDrive/Desktop/jogo_ip/projeto/raylib/examples/text/resources/fonts/pixelplay.png");

    const char messages[100] = "PIXELPLAY FONT designed by Aleksander Shevchuk";

    const int spacing= 4;

    Vector2 position = { 30,30 };

    //position.x = screenWidth/2.0f - MeasureTextEx(pixelplay, messages, pixelplay.baseSize*2.0f, (float)spacing).x/2.0f;
    //position.y = 60.0f + pixelplay.baseSize + 45.0f;
    

    Color color = DARKGREEN;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTextEx(pixelplay, messages, position, pixelplay.baseSize*2.0f, (float)spacing, color);
           

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // Fonts unloading
    //for (int i = 0; i < MAX_FONTS; i++) UnloadFont(fonts[i]);

    CloseWindow();                 // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}