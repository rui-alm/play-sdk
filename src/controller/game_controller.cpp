#include "controller/game_controller.h"
#include "controller/input_controller.h"
// #include "controller/wall_controller.h"
#include "system/system.h"
// #include "view/assets/walls/wall_view.h"
#include <memory>
#include <tuple>

game_controller::game_controller(const class input_controller& input_controller, ksdk::system& system)
    // : input_controller(input_controller), system(system)
    // , bitmap_table(nullptr)
    // , bitmap_table(system.graphics().new_bitmap_table("bricks", 1, 32, 32))
    : game_view(system.graphics(), game_model)
{
    std::ignore = input_controller;
    // wall& wall = game_model.add_actor<class wall>(100.0f,100.0f);
    // game_view.add_actor_view<wall_view>(wall.get_id(), system.graphics(), wall, *bitmap_table);
    // controllers.emplace_back(std::make_unique<wall_controller>(wall, events));
    // wall_controller& wall_controller = static_cast<class wall_controller&>(*controllers.back());
    // wall_controller.grab(input_controller);
}

int game_controller::on_tick(const ksdk::tick_event& tick_event)
{
    while (!events.empty())
    {
        auto& event = events.front();
        event->on_tick(tick_event);
        events.pop();
    }
    for (auto& controller: controllers)
    {
        controller->on_tick(tick_event);
    }
    game_model.on_tick(tick_event);
    game_view.on_tick(tick_event);
    return 0;
}

