#include "model/main_model.h"
#include "controller/input_controller.h"
#include "model/keys.h"
#include "model/main_state.h"
#include <algorithm>
#include <tuple>

main_model::main_model(const class input_controller& input_controller) :
    state(main_menu)
    , input_controller(input_controller)
    , selected_menu(1)
{
}

int main_model::on_tick(void *userdata)
{
    std::ignore = userdata;
    const ksdk::keys pressed_keys = input_controller.get_pressed_keys();
    switch(state)
    {
    case main_menu:
        if (pressed_keys & ksdk::Up)
        {
            selected_menu--;
            selected_menu = std::max(selected_menu, 1);
        }
        if (pressed_keys & ksdk::Down)
        {
            selected_menu++;
            selected_menu = std::min(selected_menu, NUMBER_OF_MENUS);
        }
        if (pressed_keys & ksdk::Enter)
        {
            state = load_game;
        }
        break;
    case load_game:
        break;
    case run_game:
        if (pressed_keys & ksdk::Back)
        {
            state = main_menu;
        }
        break;
    }
    return 0;
}