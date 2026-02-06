#include "Engine.h"

void InitWin(Engine *this, const int screenWidth, const int screenHeight, const int targetFps) {
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
    this->targetFps = targetFps;

    World_Init(&this->world, this->screenWidth, this->screenHeight);
    InitWindow(this->screenWidth, this->screenHeight, "raylib");
    SetTargetFPS(this->targetFps);
}

void run(Engine *this) {
    // Main game loop
    while (!WindowShouldClose()) {
        const float dt = GetFrameTime();
        update(this, dt);
        draw(this);
    }
}

void update(Engine *this, float dt) {
    if (this->world.isPaused) return;
}

void draw(Engine *this) {
    BeginDrawing();
    ClearBackground(BLACK);
    World_Draw(&this->world);
    DrawFPS(10, 10);
    EndDrawing();
}
