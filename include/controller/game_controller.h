#pragma once

#include "controller/controller.h"
#include "controller/input_controller.h"
#include "system/system.h"
#include "view/game_view.h"
class game_controller : public ksdk::controller
{
public:
    game_controller(const class input_controller& input_controller, ksdk::system& system);
    int on_tick(void *userdata) override;
private:
    const class input_controller& input_controller;
    ksdk::system& system;
    class game_view game_view;
};