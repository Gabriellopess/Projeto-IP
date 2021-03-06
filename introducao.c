#include "raylib.h"
#include "introducao.h"

void introducao(Texture2D background, Texture2D castle, Texture2D playButton, Texture2D whitePlayButton,  
    Texture2D controlsButton, Texture2D whiteControlsButton, Texture2D exitButton, Texture2D whiteExitButton,
    Rectangle *castleFrameRec, Vector2 castlePosition, char *message, int framesCounter)
{  
    Vector2 mousePosition = GetMousePosition();

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
    if(mousePosition.x >= 500 && mousePosition.x <= 650 && mousePosition.y >= 150 && mousePosition.y <= 200){
        DrawTextureRec(
            whitePlayButton,
            (Rectangle){0.0f, 0.0f, (float)whitePlayButton.width, (float)whitePlayButton.height},
            (Vector2){500, 150},
            WHITE
        );
    } else{
        DrawTextureRec(
            playButton,
            (Rectangle){0.0f, 0.0f, (float)playButton.width, (float)playButton.height},
            (Vector2){500, 150},
            WHITE
        );
    }
    if(mousePosition.x >= 500 && mousePosition.x <= 650 && mousePosition.y >= 205 && mousePosition.y <= 255){
        DrawTextureRec(
            whiteControlsButton,
            (Rectangle){0.0f, 0.0f, (float)whiteControlsButton.width, (float)whiteControlsButton.height},
            (Vector2){500, 205},
            WHITE
        );    
    } else {
        DrawTextureRec(
            controlsButton,
            (Rectangle){0.0f, 0.0f, (float)controlsButton.width, (float)controlsButton.height},
            (Vector2){500, 205},
            WHITE
        );
    }

    if(mousePosition.x >= 500 && mousePosition.x <= 650 && mousePosition.y >= 260 && mousePosition.y <= 310){
        DrawTextureRec(
            whiteExitButton,
            (Rectangle){0.0f, 0.0f, (float)whiteExitButton.width, (float)whiteExitButton.height},
            (Vector2){500, 260},
            WHITE
        );
    } else {
        DrawTextureRec(
            exitButton,
            (Rectangle){0.0f, 0.0f, (float)exitButton.width, (float)exitButton.height},
            (Vector2){500, 260},
            WHITE
        );
    }
    DrawText(TextSubtext(message, 0, framesCounter/5), 480, 30, 40, BLACK);
}

void introducaoLogic(Texture2D castle, int *castleFramesCounter, int castleFramesSpeed, int *castleCurrentFrame,
    Rectangle *castleFrameRec, int *framesCounter, int *gameStage){
    Vector2 mousePosition = GetMousePosition();
    
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

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousePosition.x >= 500 && mousePosition.x <= 650 && mousePosition.y >= 150 && mousePosition.y <= 200) {
        *gameStage = 1;
        *framesCounter = 0;
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousePosition.x >= 500 && mousePosition.x <= 650 && mousePosition.y >= 205 && mousePosition.y <= 255){
        *gameStage = 6;
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousePosition.x >= 500 && mousePosition.x <= 650 && mousePosition.y >= 260 && mousePosition.y <= 310) CloseWindow();
}

void drawControls(Texture2D controls,Texture2D background, Texture2D castle, Vector2 castlePosition, Rectangle castleFrameRec,
                Texture2D backButton, Texture2D whiteBackButton)
{
    Vector2 mousePosition = GetMousePosition();
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

    DrawTextureRec(
        controls,
        (Rectangle){0.0f, 0.0f, (float)controls.width, (float)controls.height},
        (Vector2){0, 0},
        WHITE
    );

    if(mousePosition.x >= 10 && mousePosition.x <= 160 && mousePosition.y >= 10 && mousePosition.y <= 60){
        DrawTextureRec(
            whiteBackButton,
            (Rectangle){0.0f, 0.0f, (float)whiteBackButton.width, (float)whiteBackButton.height},
            (Vector2){10, 10},
            WHITE
        );
    } else {
        DrawTextureRec(
            backButton,
            (Rectangle){0.0f, 0.0f, (float)backButton.width, (float)backButton.height},
            (Vector2){10, 10},
            WHITE
        );
    }
}

void controlsLogic(int *gameStage){
    Vector2 mousePosition = GetMousePosition();
    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousePosition.x >= 10 && mousePosition.x <= 160 && mousePosition.y >= 10 && mousePosition.y <= 60) {
        *gameStage = 0;
    }
}