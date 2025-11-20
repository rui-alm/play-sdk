#pragma once

#include "model/main_state.h"
#include "system/system.h"
#include "views/main_view.h"

class main_controller {
public:
    main_controller(ksdk::system& system);
    int on_tick(void* userdata);
private:
    ksdk::system& system;
    main_state state;
    main_view main_view_;
};