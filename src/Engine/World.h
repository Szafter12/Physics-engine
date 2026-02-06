#ifndef ENGINE_WORLD_H
#define ENGINE_WORLD_H

#include "raylib.h"
#include "Physics.h"

#define MAX_BODIES 100
#define GRAVITY 9.81f

typedef struct {
    // Environment parameters
    float gravity;
    float timeScale;
    // Objects
    PhysicsBody bodies[MAX_BODIES];
    int activeBodies;
    // World area
    bool isPaused;
    Rectangle boundingBox;
} World;

void World_Init(World *this, const int width, const int height);

void World_Update(World *this, float dt);

void World_Draw(World *this);

void World_SetCollision(World *this, PhysicsBody *b);

void World_AddBody(World *this);


#endif //ENGINE_WORLD_H
