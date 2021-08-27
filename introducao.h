#ifndef INTRODUCAO_H
#define INTRODUCAO_H

void introducao(Texture2D background, Texture2D castle, Texture2D playButton, Texture2D whitePlayButton, Texture2D controlsButton, Texture2D whiteControlsButton, Texture2D exitButton, Texture2D whiteExitButton, Rectangle *castleFrameRec, Vector2 castlePosition, char *message, int framesCounter);
void introducaoLogic(Texture2D castle, int *castleFramesCounter, int castleFramesSpeed, int *castleCurrentFrame, Rectangle *castleFrameRec, int *framesCounter,int *gameStage);

#endif