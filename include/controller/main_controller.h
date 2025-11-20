#pragma once
#include <memory>

#include "controller/controller.h"
#include "controller/game_controller.h"
#include "controller/input_controller.h"
#include "model/main_model.h"
#include "playdate/view/main_view_playdate.h"
#include "system/system.h"

#include "test/controller/test_menu_controller.h"

class main_controller : public ksdk::controller
{
public:
    main_controller(ksdk::system& system);
    virtual ~main_controller() = default;

    virtual int on_tick(const ksdk::tick_event& tick_event) override;

    // input_controller
    // virtual int key_pressed(uint32_t key) override;
private:
    ksdk::system& system;
    class input_controller input_controller;
    class main_model main_model;
    main_view_playdate main_view_;
    std::unique_ptr<class game_controller> game_controller;
    std::unique_ptr<class test_menu_controller> test_menu_controller;
};
