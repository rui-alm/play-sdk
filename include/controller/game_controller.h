#pragma once

#include "controller/controller.h"
#include "controller/input_controller.h"
class game_controller : public ksdk::controller
{
public:
    game_controller(class input_controller& input_controller);
    int on_tick(void *userdata) override;
private:
    class input_controller& input_controller;
};