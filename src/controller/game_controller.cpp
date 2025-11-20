#include "controller/game_controller.h"
#include "controller/input_controller.h"
#include "system/system.h"

game_controller::game_controller(const class input_controller& input_controller, ksdk::system& system)
    : input_controller(input_controller), system(system), game_view(system.graphics())
{
}

int game_controller::on_tick(void* userdata)
{
    game_view.on_tick(userdata);
    return 0;
}

