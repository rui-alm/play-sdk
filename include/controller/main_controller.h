#pragma once

#include "controller/controller.h"
#include "controller/input_controller.h"
#include "model/main_model.h"
#include "model/main_state.h"
#include "playdate/view/main_view_playdate.h"
#include "system/system.h"

class main_controller : public ksdk::controller
{
public:
    main_controller(ksdk::system& system);
    virtual ~main_controller() = default;

    virtual int on_tick(void* userdata) override;

    // input_controller
    // virtual int key_pressed(uint32_t key) override;
private:
    ksdk::system& system;
    main_state state;
    input_controller input_controller_;
    main_model main_model_;
    main_view_playdate main_view_;
};
