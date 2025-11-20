#pragma once

// #include <array>
// #include <memory>
// #include <unordered_map>

// #include <box2d-lite/World.h>
#include <box2d/box2d.h>
// #include <box2cpp/box2cpp.h>

#include "model/actor/actor.h"
class game_model
{
public:
    game_model();
    ~game_model();

    // template<class ACTOR, class... ARGS>
    // ACTOR& add_actor(ARGS&&... args)
    // {
    //     std::unique_ptr<ACTOR> actor = std::make_unique<ACTOR>(args...);
    //     const int id = actor->get_id();
    //     const int x = actor->get_x();
    //     const int y = actor->get_y();
    //     actors_map[x/CELL_SIZE_X][y/CELL_SIZE_Y].emplace(id, std::move(actor));
    //     ACTOR& actor_ref = static_cast<ACTOR&>(*actors_map[x/CELL_SIZE_X][y/CELL_SIZE_Y].at(id));
    //     return actor_ref;
    // }

    // const auto& get_actors_cell(int x, int y) const
    // {
    //     return actors_map[x/CELL_SIZE_X][y/CELL_SIZE_Y];
    // }

    const ksdk::actor& get_camera() const { return camera; }

    // const World& get_world() const { return world; }

    int on_tick(const ksdk::tick_event& tick_event);
private:
    // static constexpr int CELL_SIZE_X = 100;
    // static constexpr int CELL_SIZE_Y = 100;
    // std::array<std::array<std::unordered_map<int, std::unique_ptr<ksdk::actor>>, 10>, 10> actors_map;
    ksdk::actor camera;
    // World world;
public:
    b2WorldId world_id;
    b2BodyId groundId;
    b2BodyId bodyId;
    // b2::World w;
    // b2::Body b;
    // b2::Body ground_box;
};
