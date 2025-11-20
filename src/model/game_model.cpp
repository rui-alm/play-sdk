#include "model/game_model.h"
// #include <box2d-lite/Body.h>
// #include <playdate/system/logger.h>
// #include <box2cpp/box2cpp.h>

game_model::game_model() : camera(0.0f, 0.0f)
    // , world({0.0f, 10.0f}, 10)
    // , w(b2::World::Params{})
{
    // LOG("Creating body: %d", 0);
    // Body* body = new Body();
    // LOG("Deleting body: %d", 0);
    // body->Set({10.0f, 10.0f}, 10.0f);
    // body->position = {10.0f, 10.0f};
    // world.Add(body);
    // Body* ground_body = new Body();
    // ground_body->Set({15.0f, 20.0f}, std::numeric_limits<float>::max());
    // ground_body->position = {10.0f, 40.0f};
    // world.Add(ground_body);

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = b2Vec2{0.0f, 10.0f};
    world_id = b2CreateWorld(&worldDef);
    b2BodyDef groundBodyDef = b2DefaultBodyDef();
    groundBodyDef.position = b2Vec2{100.0f, 100.0f};
    groundId = b2CreateBody(world_id, &groundBodyDef);
    b2Polygon groundBox = b2MakeBox(50.0f, 10.0f);
    b2ShapeDef groundShapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = b2Vec2{100.0f, 4.0f};
    bodyId = b2CreateBody(world_id, &bodyDef);

    b2Polygon dynamicBox = b2MakeBox(10.0f, 10.0f);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    shapeDef.friction = 0.3f;

    b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);

    // box2cpp
    // b2::World::Params world_params {};
    // world_params.gravity = {0.0f, 10.0f};
    // w = b2::World(world_params);

    // b2::Body::Params bp;
    // bp.type = b2_dynamicBody;
    // bp.position = b2Vec2(200.0f, 4.0f);

    // b = w.CreateBody(b2::OwningHandle, bp);

    // b.CreateShape(
    //     b2::DestroyWithParent,
    //     b2::Shape::Params{},
    //     b2Circle{.center = b2Vec2(), .radius = 3}
    //     );

    // bp.type = b2_staticBody;
    // bp.position = b2Vec2(200.0f, 100.0f);

    // ground_box = w.CreateBody(b2::OwningHandle, bp);

    // ground_box.CreateShape(
    //     b2::DestroyWithParent,
    //     b2::Shape::Params{},
    //     b2MakeBox(50.0f, 10.0f)
    //     );
}

game_model::~game_model()
{
    b2DestroyWorld(world_id);
}

int game_model::on_tick(const ksdk::tick_event& tick_event)
{
    std::ignore = tick_event;
    // for (auto& cell_x: actors_map)
    // {
    //     for (auto& cell_y: cell_x)
    //     {
    //         for (auto& actor_entry: cell_y)
    //         {
    //             auto& actor = actor_entry.second;
    //             actor->on_tick(tick_event);
    //         }
    //     }
    // }
    float timeStep = 1.0f / 60.0f;
    // world.Step(timeStep);

    int subStepCount = 4;
    b2World_Step(world_id, timeStep, subStepCount);

    // w.Step(timeStep, subStepCount);
    // b2Vec2 position = b2Body_GetPosition(bodyId);
    // b2Rot rotation = b2Body_GetRotation(bodyId);
    return 0;
}
