#ifndef ENGINE_PHYSICS_H
#define ENGINE_PHYSICS_H

#include "raylib.h"

typedef enum {
    CIRCLE, RECTANGLE
} BodyShape;

typedef struct {
    // 1. Kinematics
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    // 2. Physic properties
    float mass;
    float inverseMass;
    float elasticity;
    float friction;
    // Shape
    BodyShape shape;
    float radius;
    // 4. State & Debug
    Color color;
    bool isStatic;
    bool isSelected;
} PhysicsBody;

#endif //ENGINE_PHYSICS_H
