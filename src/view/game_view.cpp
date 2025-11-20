#include "view/game_view.h"
#include "model/game_model.h"
#include "system/graphics.h"

game_view::game_view(ksdk::system_graphics& graphics, const class game_model& game_model): graphics(graphics)
    , bitmap_table(graphics.new_bitmap_table("bricks", 1, 32, 32))
    , game_model(game_model)
{
}

int game_view::on_tick(void* userdata)
{
    graphics.clear();
    const auto& camera = game_model.get_camera();
    graphics.set_draw_offset(-camera.get_x(), -camera.get_y());
    const auto& actors_cell = game_model.get_actors_cell(100, 100);
    for (const auto& actor_entry: actors_cell)
    {
        const auto& actor = actor_entry.second;
        const auto& actor_view = actors_views.at(actor->get_id());
        actor_view->on_tick(userdata);
    }
    return 0;
}
