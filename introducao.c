#include "raylib.h"
#include "introducao.h"

void introducao(Texture2D background, Texture2D castle, Rectangle *castleFrameRec, Vector2 castlePosition, char *message, int framesCounter) {  
    
    DrawTextureRec(
        background,
        (Rectangle){0.0f, 0.0f, (float)background.width, (float)background.height},
        (Vector2){0, 0},
        WHITE
    );
    DrawTextureRec(
        castle,
        *castleFrameRec,
        castlePosition,
        WHITE
    );
    DrawText(TextSubtext(message, 0, framesCounter/10), 420, 50, 20, MAROON);
    DrawText("PRESSIONE [ESPAÇO] PARA ADIANTAR!", 392, 265, 20, LIGHTGRAY);
    DrawText("PRESSIONE [PLAY] PARA JOGAR!", 390, 290, 20, LIGHTGRAY);
}

void introducaoLogic(Texture2D castle, int *castleFramesCounter, int castleFramesSpeed, int *castleCurrentFrame, Rectangle *castleFrameRec, int *framesCounter, int *gameStage){
    (*castleFramesCounter)++;
    if(*castleFramesCounter >= (20/castleFramesSpeed)){
        *castleFramesCounter = 0;
        (*castleCurrentFrame)++;
        if(*castleCurrentFrame > 1){
            *castleCurrentFrame = 0;
        }

        (*castleFrameRec).x = (float)*castleCurrentFrame * (float)castle.width/2;
        
    }

    if (IsKeyDown(KEY_SPACE)) (*framesCounter) += 8;
    else (*framesCounter)++;

    if(IsKeyDown(KEY_ENTER)) *gameStage = 1;
}