#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "raylib.h"

typedef struct {
    int screenWidth;
    int screenHeight;
    int targetFps;
} Game;

void InitWin(Game *this, int screenWidth, int screenHeight, int targetFps);

void run();

void update(float dt);

void draw();


#endif
