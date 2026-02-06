#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "raylib.h"
#include "World.h"

typedef struct {
    int screenWidth;
    int screenHeight;
    int targetFps;
    World world;
} Engine;

void InitWin(Engine *this, int screenWidth, int screenHeight, int targetFps);

void run(Engine *this);

void update(Engine *this, float dt);

void draw(Engine *this);


#endif
