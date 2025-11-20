#include "view/game_view.h"
#include "model/game_model.h"
#include "system/graphics.h"

game_view::game_view(ksdk::system_graphics& graphics): graphics(graphics)
    , bitmap_table(graphics.new_bitmap_table("bricks", 1, 32, 32))
{
}

int game_view::on_tick(void* userdata)
{
    graphics.clear();
    for (auto& actor_view: actors_views)
    {
        actor_view->on_tick(userdata);
    }
    return 0;
}