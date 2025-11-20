#pragma once

#include "graphics/bitmap_table.h"
#include "model/game_model.h"
#include "system/graphics.h"
#include "view/view.h"
class game_view : ksdk::view
{
public:
    game_view(ksdk::system_graphics& graphics);
    ~game_view() = default;

    int on_tick(void* userdata) override;
    std::vector<std::unique_ptr<ksdk::view>>& get_actors_views() { return actors_views; }
private:
    ksdk::system_graphics& graphics;
    std::unique_ptr<ksdk::bitmap_table> bitmap_table;
    // const class game_model& game_model;
    std::vector<std::unique_ptr<ksdk::view>> actors_views;
};