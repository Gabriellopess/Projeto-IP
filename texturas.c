#include "raylib.h"
#include "texturas.h"

void venenoLogic(){
    


    // venenoFramesCounter++;
    // if(*venenoFramesCounter >= (20/venenoFramesSpeed)){
    //     *venenoFramesCounter = 0;
    //     (*venenoCurrentFrame)++;
    //     if(*venenoCurrentFrame > 1){
    //         *venenoCurrentFrame = 0;
    //     }

    //     (*venenoFrameRec).x = (float)*venenoCurrentFrame * (float)veneno.width/2;
        
    // }
}

void drawVeneno(){

}

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
            (Vector2){enemyPosition.x, enemyPosition.y - 22},
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

void drawDiagWall(Texture2D diagWall){
    Texture2D diagWall2 = LoadTexture("assets/24wall3.png");
    Texture2D diagWall3 = LoadTexture("assets/wall2.png");
    Texture2D diagWall4 = LoadTexture("assets/wall2.png");

    Texture2D diagWall5 = LoadTexture("assets/wall45.png");

    DrawTextureRec( //wall1
        diagWall,
        (Rectangle){0.0f, 0.0f, (float)diagWall.width, (float)diagWall.height},
        (Vector2){49, 92},
        WHITE
    );

    DrawTextureRec(//24wall3
        diagWall2,
        (Rectangle){0.0f, 0.0f, (float)diagWall2.width, (float)diagWall2.height},
        (Vector2){615, 155},
        WHITE
    );
    DrawTextureRec(//24wall3
        diagWall2,
        (Rectangle){0.0f, 0.0f, (float)diagWall2.width, (float)diagWall2.height},
        (Vector2){665, 215},
        WHITE
    );
    DrawTextureRec(//24wall3
        diagWall2,
        (Rectangle){0.0f, 0.0f, (float)diagWall2.width, (float)diagWall2.height}, //2.9 3.5
        (Vector2){676, 226},
        WHITE
    );

    DrawTextureRec(//wall1
        diagWall,
        (Rectangle){0.0f, 0.0f, (float)diagWall.width, (float)diagWall.height},
        (Vector2){-13, 124},
        WHITE
    );
    DrawTextureRec(//wall1
        diagWall,
        (Rectangle){0.0f, 0.0f, (float)diagWall.width/1.8, (float)diagWall.height/2.8},
        (Vector2){47, 174},
        WHITE
    );


    DrawTextureRec(
        diagWall3,
        (Rectangle){0.0f, 0.0f, (float)diagWall3.width/1.6, (float)diagWall3.height},
        (Vector2){39, 185},
        WHITE
    );

    DrawTextureRec(
        diagWall4,
        (Rectangle){0.0f, 0.0f, (float)-diagWall4.width/1.4, (float)-diagWall4.height},
        (Vector2){83, 244}, //73 233 //87, 244
        WHITE
    );


    // (float)535, (float)219
    DrawTextureRec(
        diagWall5,
        (Rectangle){0.0f, 0.0f, (float)diagWall5.width, (float)diagWall5.height},
        (Vector2){506, 280},
        WHITE
    );
    DrawTextureRec(
        diagWall5,
        (Rectangle){0.0f, 0.0f, (float)diagWall5.width, (float)diagWall5.height},
        (Vector2){460, 326},
        WHITE
    );

    DrawTextureRec(
        diagWall5,
        (Rectangle){0.0f, 0.0f, (float)diagWall5.width, (float)diagWall5.height},
        (Vector2){472, 215},
        WHITE
    );
    DrawTextureRec(
        diagWall5,
        (Rectangle){0.0f, 0.0f, (float)diagWall5.width, (float)diagWall5.height},
        (Vector2){465, 220},
        WHITE
    );
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
        (Rectangle){0.0f, 0.0f, (float)stoneHorizWall.width/1.2, (float)stoneHorizWall.height},
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