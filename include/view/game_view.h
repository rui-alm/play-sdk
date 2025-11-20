#pragma once

#include "system/graphics.h"
#include "view/view.h"
#include "graphics/types.h"
class game_view : ksdk::view
{
public:
    game_view(ksdk::system_graphics& graphics);
    virtual ~game_view();

    int on_tick(void* userdata) override;
private:
    ksdk::system_graphics& graphics;
    ksdk::bitmap_table* bitmap_table;
};