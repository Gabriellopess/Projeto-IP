#ifndef INTRODUCAO_H
#define INTRODUCAO_H

void introducao(Texture2D castle, Rectangle *castleFrameRec, Vector2 castlePosition, char *message, int framesCounter);
void introducaoLogic(Texture2D castle, int *castleFramesCounter, int castleFramesSpeed, int *castleCurrentFrame, Rectangle *castleFrameRec, int *framesCounter);

#endif