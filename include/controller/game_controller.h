#pragma once

#include <queue>

#include "controller/controller.h"
#include "controller/input_controller.h"
#include "event/event.h"
#include "graphics/bitmap_table.h"
#include "model/actor/actor.h"
#include "model/game_model.h"
#include "system/system.h"
#include "view/game_view.h"

class game_controller : public ksdk::controller
{
public:
    game_controller(const class input_controller& input_controller, ksdk::system& system);
    int on_tick(const ksdk::tick_event& tick_event) override;
private:
    const class input_controller& input_controller;
    ksdk::system& system;
    std::unique_ptr<ksdk::bitmap_table> bitmap_table;
    class game_model game_model;
    class game_view game_view;
    std::queue<std::unique_ptr<ksdk::event>> events;
    std::vector<std::unique_ptr<ksdk::controller>> controllers;
};
