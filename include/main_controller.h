#pragma once

#include "system/system.h"
#include <tuple>

class main_controller {
public:
    main_controller(ksdk::system& system);
    int on_tick(void* userdata);
private:
    ksdk::system& system_;
};