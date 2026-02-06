#include "Physics.h"

void Physics_ApplyGravity(PhysicsBody *b, const float gravity, const float finalDt) {
    b->velocity.y += gravity * finalDt;
    b->position.x += b->velocity.x * finalDt;
    b->position.y += b->velocity.y * finalDt;
}
