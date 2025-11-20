#pragma once

#include "system/graphics.h"

class main_view
{
public:
    main_view(ksdk::system_graphics& graphics);
    int on_tick();
private:
    ksdk::system_graphics& graphics;
};