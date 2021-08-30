#ifndef PLATAFORMA_H
#define PLATAFORMA_H

void drawTimer(int *time);
void drawHearts(Texture2D heart, int *lifes);
void drawFinal(Texture2D textura, int win, Texture2D exitButton, Texture2D whiteExitButton);
void finalButtonsLogic(int *gameStage);
void drawAnjolinda(Texture2D anjolinda);

#endif