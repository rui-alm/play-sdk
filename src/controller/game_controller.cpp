#include "controller/game_controller.h"
#include "controller/input_controller.h"
#include "system/system.h"
#include "view/assets/walls/wall_view.h"
#include <memory>

game_controller::game_controller(const class input_controller& input_controller, ksdk::system& system)
    : input_controller(input_controller), system(system)
    , bitmap_table(system.graphics().new_bitmap_table("bricks", 1, 32, 32))
    , game_view(system.graphics())
{
    auto& actors = game_model.get_actors();
    actors.emplace_back(std::make_unique<wall>(10, 10));
    auto& actors_views = game_view.get_actors_views();
    actors_views.emplace_back(std::make_unique<wall_view>(system.graphics(), static_cast<wall&>(*actors.back()), *bitmap_table));
}

int game_controller::on_tick(void* userdata)
{
    game_model.on_tick(userdata);
    game_view.on_tick(userdata);
    return 0;
}

