#include "controller/game_controller.h"
#include "controller/input_controller.h"
#include "system/system.h"
#include "view/assets/walls/wall_view.h"
#include <memory>

game_controller::game_controller(const class input_controller& input_controller, ksdk::system& system)
    : input_controller(input_controller), system(system)
    , bitmap_table(system.graphics().new_bitmap_table("bricks", 1, 32, 32))
    , game_view(system.graphics(), game_model)
{
    wall& wall = game_model.add_actor<class wall>(100,100);
    game_view.add_actor_view<wall_view>(wall.get_id(), system.graphics(), wall, *bitmap_table);
}

int game_controller::on_tick(void* userdata)
{
    game_model.on_tick(userdata);
    game_view.on_tick(userdata);
    return 0;
}

