#include "World.h"

void World_Init(World *this, const int width, const int height) {
    this->gravity = GRAVITY;
    this->timeScale = 1.0f;
    this->activeBodies = 0;
    this->isPaused = false;
    this->boundingBox = (Rectangle){40.f, 40.f, width - 80, height - 80};
}

void World_Step(World *this, const float dt) {
    const float finalDt = dt * this->timeScale;
    for (int i = 0; i < this->activeBodies; i++) {
        PhysicsBody *b = &this->bodies[i];

        if (b->isStatic) continue;

        World_SetGravity(this, finalDt, b);
        World_SetCollision(this, b);
    }
}

void World_Draw(World *this) {
    if (this->isPaused) return;
    DrawRectangleLinesEx(this->boundingBox, 2.0f, DARKGRAY);

    for (int i = 0; i < this->activeBodies; i++) {
        PhysicsBody *b = &this->bodies[i];
        DrawCircleV(b->position, b->radius, b->color);
    }
}

void World_SetGravity(World *this, const float finalDt, PhysicsBody *b) {
    b->velocity.y += this->gravity * finalDt;
    b->position.x += b->velocity.x * finalDt;
    b->position.y += b->velocity.y * finalDt;
}

void World_SetCollision(World *this, PhysicsBody *b) {
    // Down
    float groundLevel = this->boundingBox.y + this->boundingBox.height;
    if (b->position.y > groundLevel) {
        b->position.y = groundLevel;
        b->velocity.y *= b->elasticity;
    }

    // Up
    float ceilingLevel = this->boundingBox.y;
    if (b->position.y < ceilingLevel) {
        b->position.y = ceilingLevel;
        b->velocity.y *= -b->elasticity;
    }

    // Left
    float leftWall = this->boundingBox.x;
    if (b->position.x < leftWall) {
        b->position.x = leftWall;
        b->velocity.x *= -b->elasticity;
    }

    // Right
    float rightWall = this->boundingBox.x + this->boundingBox.width;
    if (b->position.x > rightWall) {
        b->position.x = rightWall;
        b->velocity.x *= -b->elasticity;
    }
}
