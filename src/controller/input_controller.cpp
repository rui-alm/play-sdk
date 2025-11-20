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

int input_controller::on_tick(const ksdk::tick_event& tick_event)
{
    std::ignore = tick_event;
    system.button_state(down_keys, pressed_keys, released_keys);
    return 0;
}