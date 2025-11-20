#include "view/game_view.h"
#include "graphics/types.h"
#include "model/game_model.h"
#include "system/graphics.h"
#include "view/assets/walls/wall_view.h"
#include "view/view.h"
#include <tuple>

game_view::game_view(ksdk::system_graphics& graphics): graphics(graphics)
    , bitmap_table(graphics.new_bitmap_table("bricks", 1, 32, 32))
{
}

int game_view::on_tick(void* userdata)
{
    std::ignore = userdata;
    graphics.clear();
    const int idx = 0;
    ksdk::bitmap& bitmap = bitmap_table->get(idx);
    graphics.draw_bitmap(bitmap, 0, 0);
    return 0;
}