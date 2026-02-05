#include "Engine.h"

void InitWin(Engine *this, const int screenWidth, const int screenHeight, const int targetFps) {
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
    this->targetFps = targetFps;

    InitWindow(this->screenWidth, this->screenHeight, "raylib");
    SetTargetFPS(this->targetFps);
}

void run() {
    // Main game loop
    while (!WindowShouldClose()) {
        const float dt = GetFrameTime();
        // Update
        update(dt);
        // Draw
        draw();
    }
}

void update(float dt) {
}

void draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    EndDrawing();
}
