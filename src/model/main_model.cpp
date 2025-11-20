#include "model/main_model.h"
#include "controller/input_controller.h"
#include "model/keys.h"
#include "model/main_state.h"
#include <algorithm>
#include <tuple>

main_model::main_model(const class input_controller& input_controller) :
    state(main_menu)
    , input_controller(input_controller)
    , selected_menu(0)
{
}

int main_model::on_tick(const ksdk::tick_event& tick_event)
{
    std::ignore = tick_event;
    const ksdk::keys pressed_keys = input_controller.get_pressed_keys();
    switch(state)
    {
    case main_menu:
        if (pressed_keys & ksdk::Up)
        {
            selected_menu--;
            selected_menu = std::max(selected_menu, 0);
        }
        if (pressed_keys & ksdk::Down)
        {
            selected_menu++;
            selected_menu = std::min(selected_menu, NUMBER_OF_MENUS - 1);
        }
        if (pressed_keys & ksdk::Enter)
        {
            if (selected_menu == 0)
                state = load_game;
            else
                state = test_menu;
        }
        break;
    case load_game:
        break;
    case run_game:
    case test_menu:
        // if (pressed_keys & ksdk::Back)
        // {
        //     state = main_menu;
        // }
        break;
    }
    return 0;
}
