#include "model/main_model.h"
#include "controller/input_controller.h"
#include "model/keys.h"
#include <algorithm>
#include <tuple>

main_model::main_model(const class input_controller& input_controller) :
    input_controller(input_controller)
    , selected_menu(1)
{
}

int main_model::on_tick(void *userdata)
{
    std::ignore = userdata;
    const ksdk::keys down_keys = input_controller.get_pressed_keys();
    if (down_keys & ksdk::Up)
    {
        selected_menu--;
        selected_menu = std::max(selected_menu, 1);
    }
    if (down_keys & ksdk::Down)
    {
        selected_menu++;
        selected_menu = std::min(selected_menu, NUMBER_OF_MENUS);
    }
    return 0;
}