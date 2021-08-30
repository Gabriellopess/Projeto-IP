#ifndef TEXTURAS_H
#define TEXTURAS_H

void drawContadores(int books);
void drawFireBall(Texture2D fireballUp, Texture2D fireballDown, Vector2 fire, float *aux);
void drawFantasma(Texture2D fantasma1, Texture2D fantasma2, Vector2 enemyPosition, float *temporary);
void drawHorizontalWall(Texture2D stoneHorizWall);
void drawDiagWall(Texture2D diagWall);
void drawVertWall(Texture2D stoneVertWall);
void drawGrass(Texture2D mapGrass);

#endif