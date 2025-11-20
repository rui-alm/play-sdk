#include "controller/game_controller.h"
#include "controller/input_controller.h"
#include <tuple>

game_controller::game_controller(class input_controller& input_controller)
    : input_controller(input_controller)
{
}

int game_controller::on_tick(void* userdata)
{
    std::ignore = userdata;
    return 0;
}

