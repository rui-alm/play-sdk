#pragma once

#include "controller/input_controller.h"

class main_model
{
public:
    main_model(const class input_controller& input_controller);
    // virtual ~main_model() = default;
    int on_tick(void *userdata);
    int get_selected_menu() const { return selected_menu; }
private:
    const int NUMBER_OF_MENUS = 3;
    const class input_controller& input_controller;
    int selected_menu;
};