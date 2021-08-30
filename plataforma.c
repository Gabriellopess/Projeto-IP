#include "raylib.h"
#include "plataforma.h"

void finalButtonsLogic(int *gameStage){
    Vector2 mousePosition = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousePosition.x >= 600 && mousePosition.x <= 750 && mousePosition.y >= 260 && mousePosition.y <= 310) {
        CloseWindow();
    }
}

void drawYouLose(Texture2D textura, int win, Texture2D exitButton, Texture2D whiteExitButton){
    Vector2 mousePosition = GetMousePosition();
    if(win == 0){
        DrawTextureRec(
            textura,
            (Rectangle){0.0f, 0.0f, textura.width, textura.height}, 
            (Vector2){0, 0},
            WHITE
        );
        DrawRectangleGradientH(292, 76, 457, 155, BLACK, BLANK);
        DrawRectangleGradientH(292, 76, 457, 155, BLANK, BLACK);
        DrawText(TextFormat("Que decepção, discípulo!\nVocê não conseguiu passar pelo\nchão de lava e entregar os livros\naté a princesa Anjolinda!"),
            300, 80, 26, WHITE);
    }
    else{
        DrawTextureRec(
            textura,
            (Rectangle){0.0f, 0.0f, textura.width, textura.height}, 
            (Vector2){0, 0},
            WHITE
        );
        DrawRectangleGradientH(320, 20, 453, 155, BLACK, BLANK);
        DrawRectangleGradientH(320, 20, 453, 155, BLANK, BLACK);
        DrawText(TextFormat("Parabéns, discípulo!\nVocê cumpriu sua missão e\nentregou os livros até Anjolinda,\nque agora conseguirá estudar!"),
            328, 24, 26, WHITE);
    }

    if(mousePosition.x >= 600 && mousePosition.x <= 750 && mousePosition.y >= 260 && mousePosition.y <= 310){
        DrawTextureRec(
            whiteExitButton,
            (Rectangle){0.0f, 0.0f, (float)whiteExitButton.width, (float)whiteExitButton.height},
            (Vector2){600, 260},
            WHITE
        );
    } else {
        DrawTextureRec(
            exitButton,
            (Rectangle){0.0f, 0.0f, (float)exitButton.width, (float)exitButton.height},
            (Vector2){600, 260},
            WHITE
        );
    }
    

}


void drawTimer(int *time){
    DrawRectangleGradientH(345, 20, 137, 22, RAYWHITE, BLANK);
    DrawRectangleGradientH(345, 20, 137, 22, BLANK, RAYWHITE);
    DrawText(TextFormat("Tempo: %d", 30 - (*time/60)), 350, 20, 25, BLACK);
}

void drawAnjolinda(Texture2D anjolinda){
    DrawTextureRec(
        anjolinda,
        (Rectangle){0.0f, 0.0f, anjolinda.width, anjolinda.height}, 
        (Vector2){760, 10},
        WHITE
    );
}

void drawHearts(Texture2D heart, int *lifes){
    if(*lifes == 5){
        DrawTextureRec(
            heart,
            (Rectangle){0.0f, 0.0f, heart.width, heart.height}, 
            (Vector2){650, 100},
            WHITE
        );
    }
    if(*lifes >= 4){
        DrawTextureRec(
            heart,
            (Rectangle){0.0f, 0.0f, heart.width, heart.height}, 
            (Vector2){680, 100},
            WHITE
        );
    }
    if(*lifes >= 3){
        DrawTextureRec(
            heart,
            (Rectangle){0.0f, 0.0f, heart.width, heart.height}, 
            (Vector2){710, 100},
            WHITE
        );
    }
    if(*lifes >= 2){
        DrawTextureRec(
            heart,
            (Rectangle){0.0f, 0.0f, heart.width, heart.height}, 
            (Vector2){740, 100},
            WHITE
        );
    }
    if(*lifes >= 1){
        DrawTextureRec(
            heart,
            (Rectangle){0.0f, 0.0f, heart.width, heart.height}, 
            (Vector2){770, 100},
            WHITE
        );
    }
}