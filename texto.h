#ifndef TEXTO_H
#define TEXTO_H

void drawText(Texture2D background, Texture2D castle, Vector2 castlePosition, Rectangle castleFrameRec, char *message, int framesCounter);
void textLogic(int *framesCounter, int *gameStage);

#endif