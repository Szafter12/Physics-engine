#include "World.h"

void World_Init(World *this, const int width, const int height) {
    this->gravity = GRAVITY * 100.f;
    this->timeScale = 1.0f;
    this->activeBodies = 0;
    this->isPaused = false;
    this->boundingBox = (Rectangle){40.f, 40.f, width - 80, height - 80};

    World_AddBody(this);
}

void World_Update(World *this, const float dt) {
    const float finalDt = dt * this->timeScale;
    for (int i = 0; i < this->activeBodies; i++) {
        PhysicsBody *b = &this->bodies[i];

        if (b->isStatic) continue;

        Physics_ApplyGravity(b, this->gravity, finalDt);
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

void World_AddBody(World *this) {
    if (this->activeBodies >= MAX_BODIES) return;

    PhysicsBody *b = &this->bodies[this->activeBodies++];

    b->position = (Vector2){GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};
    b->velocity = (Vector2){15.0f, 0.0f};
    b->acceleration = (Vector2){0.0f, 0.0f};
    b->elasticity = 0.5f;
    b->isStatic = false;
    b->mass = 10.0f;
    b->radius = 20.0f;
    b->color = RED;
    b->friction = 0.f;
}

void World_SetCollision(World *this, PhysicsBody *b) {
    // Down
    float groundLevel = this->boundingBox.y + this->boundingBox.height;
    if ((b->position.y + b->radius) > groundLevel) {
        b->position.y = (groundLevel - b->radius);
        b->velocity.y *= -b->elasticity;
    }

    // Up
    float ceilingLevel = this->boundingBox.y;
    if ((b->position.y + b->radius) < ceilingLevel) {
        b->position.y = (ceilingLevel + b->radius);
        b->velocity.y *= -b->elasticity;
    }

    // Left
    float leftWall = this->boundingBox.x;
    if ((b->position.x + b->radius) < leftWall) {
        b->position.x = (leftWall + b->radius);
        b->velocity.x *= -b->elasticity;
    }

    // Right
    float rightWall = this->boundingBox.x + this->boundingBox.width;
    if ((b->position.x + b->radius) > rightWall) {
        b->position.x = (rightWall - b->radius);
        b->velocity.x *= -b->elasticity;
    }
}
