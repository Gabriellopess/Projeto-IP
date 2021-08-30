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

void drawFireBall(Texture2D fireballUp, Texture2D fireballDown, Vector2 fire, float *aux){
    if(fire.y <= *aux){
        DrawTextureRec(
            fireballUp,
            (Rectangle){0.0f, 0.0f, fireballUp.width, fireballUp.height}, 
            (Vector2){fire.x - 22, fire.y - 32},
            WHITE
        );
    }
    if(fire.y > *aux){
        DrawTextureRec(
            fireballDown,
            (Rectangle){0.0f, 0.0f, fireballDown.width, fireballDown.height}, 
            (Vector2){fire.x - 22, fire.y - 45},
            WHITE
        );
    }
}

void drawDiagWall(Texture2D diagWall){
    Texture2D diagWall2 = LoadTexture("assets/24wall3.png");
    Texture2D diagWall3 = LoadTexture("assets/wall2.png");

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
        (Rectangle){0.0f, 0.0f, (float)diagWall2.width, (float)diagWall2.height},
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
        diagWall3,
        (Rectangle){0.0f, 0.0f, (float)-diagWall3.width/1.4, (float)-diagWall3.height},
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

void drawVertWall(Texture2D stoneVertWall){
    // paredes verticais 
    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 22}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 55}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 88}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 121}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 154}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 187}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 220}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 253}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){-13, 286}, // vertical grandona do lado esquerdo da tela
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){75, 288}, // lado direito do livro azul (tem que ser pequeninho)
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){185, 22}, // segunda coluna de cima pra baixo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){185, 55}, // segunda coluna de cima pra baixo2
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){185, 88}, // segunda coluna de cima pra baixo3
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){185, 121}, // segunda coluna de cima pra baixo4
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){185, 128}, // segunda coluna de cima pra baixo5
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){249, 290},  // a esquerda do livro amarelo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){249, 323}, // a esquerda do livro amarelo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){249, 347}, // a esquerda do livro amarelo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 111}, // vertical grandona do canto direito
        WHITE
    );
    
    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 144}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 177}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 210}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 243}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 276}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 309}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 342}, // vertical grandona do canto direito
        WHITE
    );


    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){790, 349}, // vertical grandona do canto direito
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){617, 90}, // a esquerda do livro marrom1
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){617, 123}, // a esquerda do livro marrom2
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){617, 139}, // a esquerda do livro marrom3
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){565, 311}, // segunda coluna de baixo pra cima
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){565, 344}, // segunda coluna de baixo pra cima
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){565, 350}, // segunda coluna de baixo pra cima
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){400, 20}, // terceira coluna de cima pra baixo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){400, 53}, // terceira coluna de cima pra baixo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){400, 62}, // terceira coluna de cima pra baixo
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){463, 154}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){463, 187}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){463, 220}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){463, 253}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){463, 274}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){534, 20}, 
        WHITE
    ); 

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){534, 53}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){534, 86}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){534, 100}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){383, 174}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){383, 195}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){409, 290}, 
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){409, 310},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){314, 116},
        WHITE
    );
    
    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){314, 122},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){314, 197},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){314, 230},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){314, 238},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){38, 247},
        WHITE
    );


    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){52, 71},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){52, 89},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){185, 225},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){185, 234},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){185, 250},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height/1.8},
        (Vector2){185, 252},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){249, 154},
        WHITE
    );

    DrawTextureRec(
        stoneVertWall,
        (Rectangle){0.0f, 0.0f, (float)stoneVertWall.width, (float)stoneVertWall.height},
        (Vector2){249, 170},
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