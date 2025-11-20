#include "controller/input_controller.h"
#include <cstdint>
#include <tuple>

input_controller::input_controller(ksdk::system& system) : system(system)
{
}

int input_controller::key_pressed(uint32_t key)
{
    std::ignore = key;
    return 0;
}

int input_controller::on_tick(void* userdata)
{
    std::ignore = userdata;
    system.button_state(down_keys, pressed_keys, released_keys);
    return 0;
}