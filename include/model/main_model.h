#pragma once

#include "controller/input_controller.h"
#include "model/main_state.h"

class main_model
{
public:
    main_model(const class input_controller& input_controller);
    // virtual ~main_model() = default;
    int on_tick(const ksdk::tick_event& tick_event);
    int get_selected_menu() const { return selected_menu; }
    main_state get_state() const { return state; }
    void set_state(const main_state state) { this->state = state; }
private:
    const int NUMBER_OF_MENUS = 3;
    main_state state;
    const class input_controller& input_controller;
    int selected_menu;
};