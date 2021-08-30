#include "raylib.h"
#include "texto.h"

void drawText(Texture2D background, Texture2D castle, Vector2 castlePosition, Rectangle castleFrameRec, char *message, int framesCounter){
    ClearBackground(BLACK);
    DrawTextureRec(
        background,
        (Rectangle){0.0f, 0.0f, (float)background.width, (float)background.height},
        (Vector2){0, 0},
        WHITE
    );
    DrawTextureRec(
        castle,
        castleFrameRec,
        castlePosition,
        WHITE
    );

    DrawRectangleGradientH(0, 0, 800, 400, BLACK, BLANK);
    DrawRectangleGradientH(0, 0, 800, 400, BLANK, BLACK);

    DrawText(TextSubtext(message, 0, framesCounter/5), 30, 30, 25, RAYWHITE);
    DrawText("PRESSIONE [ESPAÇO] PARA ADIANTAR!", 200, 330, 20, LIGHTGRAY);
    DrawText("PRESSIONE [ENTER] PARA JOGAR!", 215, 358, 20, LIGHTGRAY);
}

void textLogic(int *framesCounter, int *gameStage){
    if (IsKeyDown(KEY_SPACE)) (*framesCounter) += 8;
    else (*framesCounter)++;

    if(*gameStage == 1){
        if(IsKeyDown(KEY_ENTER)) {
            *gameStage = 2;
            *framesCounter = 0;
        }
    }
    if(*gameStage == 3){
        if(IsKeyDown(KEY_ENTER)) {
            *gameStage = 4;
            *framesCounter = 0;
        }
    }

    
}