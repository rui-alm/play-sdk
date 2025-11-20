#include "view/game_view.h"
#include "model/game_model.h"
#include "system/graphics.h"

game_view::game_view(ksdk::system_graphics& graphics, const class game_model& game_model): graphics(graphics)
    , bitmap_table(graphics.new_bitmap_table("bricks", 1, 32, 32))
    , game_model(game_model)
{
}

int game_view::on_tick(const ksdk::tick_event& tick_event)
{
    graphics.clear();
    const auto& camera = game_model.get_camera();
    graphics.set_draw_offset(-camera.get_x(), -camera.get_y());
    const auto& actors_cell = game_model.get_actors_cell(100, 100);
    for (const auto& actor_entry: actors_cell)
    {
        const auto& actor = actor_entry.second;
        const auto& actor_view = actors_views.at(actor->get_id());
        actor_view->on_tick(tick_event);
    }
    ksdk::bitmap* bmp = graphics.load_bitmap("tick");
    graphics.draw_bitmap(*bmp, 200, 200);
    bmp = graphics.load_bitmap("tick_outline");
    graphics.draw_bitmap(*bmp, 220, 200);
    bmp = graphics.load_bitmap("cross_outline");
    graphics.draw_bitmap(*bmp,240,200);
    bmp = graphics.load_bitmap("cross");
    graphics.draw_bitmap(*bmp,260,200);
    return 0;
}
