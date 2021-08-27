#include "raylib.h"
#include "texturas.h"

void drawContadores(int books){
    DrawRectangleGradientH(612, 360, 175, 20, RAYWHITE, BLANK);
    DrawRectangleGradientH(612, 360, 175, 20, BLANK, RAYWHITE);
    DrawText(TextFormat("Qtd. de Livros: %d", books), 615, 360, 20, BLACK);
}

void drawFantasma(Texture2D fantasma1, Texture2D fantasma2, Vector2 enemyPosition, float *temporary){
    if(enemyPosition.x >= *temporary){
        DrawTextureRec(
            fantasma1,
            (Rectangle){0.0f, 0.0f, (float)fantasma1.width, (float)fantasma1.height},
            (Vector2){enemyPosition.x - 25, enemyPosition.y - 22},
            WHITE
        );
    }
    else if(enemyPosition.x < *temporary){
        DrawTextureRec(
            fantasma2,
            (Rectangle){0.0f, 0.0f, (float)fantasma2.width, (float)fantasma2.height},
            (Vector2){enemyPosition.x - 25, enemyPosition.y - 22},
            WHITE
        );
    }
}

void drawHorizontalWall(Texture2D stoneHorizWall){
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){0, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){80, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){160, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){240, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){320, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){400, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){480, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){560, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){640, 380},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){720, 380},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){0, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){80, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){160, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){240, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){320, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){400, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){480, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){560, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){640, 0},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){720, 0},
        WHITE
    );


    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){0, 315},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){80, 315},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){127, 315},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){0, 203},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){20, 203},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){250, 269},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){330, 269},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){350, 269},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){250, 94},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){330, 94},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){390, 94},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){384, 152},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width/1.7, (float)stoneHorizWall.height},
        (Vector2){484, 213}, //IMAGEM MT GRANDE PARA O RETANGULO 484
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){565, 289},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){618, 89},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){698, 89},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){726, 89},
        WHITE
    );

    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){186, 203},
        WHITE
    );
    DrawTextureRec(
        stoneHorizWall,
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width, (float)stoneHorizWall.height},
        (Vector2){190, 203},
        WHITE
    );
}
void drawGrass(Texture2D mapGrass){
    //coluna 1
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){0, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){0, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){0, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){0, 345},
        WHITE
    );

    //coluna2
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){116, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){116, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){116, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){116, 345},
        WHITE
    );

    //coluna3
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){232, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){232, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){232, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){232, 345},
        WHITE
    );

    //coluna 4
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){348, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){348, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){348, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){348, 345},
        WHITE
    );

    //coluna 5
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){464, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){464, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){464, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){464, 345},
        WHITE
    );

    //coluna 6
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){580, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){580, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){580, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){580, 345},
        WHITE
    );

    //coluna 7
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){696, 0},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){696, 115},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){696, 230},
        WHITE
    );
    DrawTextureRec(
        mapGrass,
        (Rectangle){0.0f, 0.0f, (float)mapGrass.width, (float)mapGrass.height},
        (Vector2){696, 345},
        WHITE
    );
}