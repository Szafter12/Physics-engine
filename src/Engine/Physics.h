#ifndef ENGINE_PHYSICS_H
#define ENGINE_PHYSICS_H

#include "raylib.h"

typedef struct {
    // 1. Kinematics
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    // 2. Physic properties
    float mass;
    float elasticity;
    float friction;
    // Shape
    float radius;
    // 4. State & Debug
    Color color;
    bool isStatic;
    bool isSelected;
} PhysicsBody;

void Physics_ApplyGravity(PhysicsBody *b, float gravity, const float finalDt);

#endif //ENGINE_PHYSICS_H
