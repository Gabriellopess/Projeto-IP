#include "raylib.h"
#include "plataforma.h"

void drawTimer(int *time){
    DrawRectangleGradientH(345, 20, 137, 22, RAYWHITE, BLANK);
    DrawRectangleGradientH(345, 20, 137, 22, BLANK, RAYWHITE);
    DrawText(TextFormat("Tempo: %d", 30 - (*time/60)), 350, 20, 25, BLACK);
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