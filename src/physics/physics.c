#include "physics.h"

#include "box2d/box2d.h"

b2WorldId worldId;

void initPhysics()
{
    // create world
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.0f, 0.0f};
    worldId = b2CreateWorld(&worldDef);

    // create test circle
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.position = (b2Vec2){0.0f, 0.0f};
    const b2BodyId bodyId = b2CreateBody(worldId, &bodyDef);

    // add shape to the test circle
    const b2Circle bodyCircle = (b2Circle){0.0f, 0.0f, 0.2f};
    const b2ShapeDef bodyShapeDef = b2DefaultShapeDef();
    b2CreateCircleShape(bodyId, &bodyShapeDef, &bodyCircle);
}

void destroyPhysics()
{
    b2DestroyWorld(worldId);
}

b2WorldId getWorldId()
{
    return worldId;
}