#include "view/game_view.h"
#include "model/game_model.h"
#include "system/graphics.h"
#include "graphics/text/line_splitter.h"
// #include <box2d-lite/Body.h>

game_view::game_view(ksdk::system_graphics& graphics, const class game_model& game_model): graphics(graphics)
    // , bitmap_table(nullptr)
    // , bitmap_table(graphics.new_bitmap_table("bricks", 1, 32, 32))
    , game_model(game_model)
{
}

int game_view::on_tick(const ksdk::tick_event& tick_event)
{
    std::ignore = tick_event;
    graphics.clear();
    const auto& camera = game_model.get_camera();
    graphics.set_draw_offset(-camera.get_x(), -camera.get_y());
    // const auto& actors_cell = game_model.get_actors_cell(100, 100);
    // for (const auto& actor_entry: actors_cell)
    // {
    //     const auto& actor = actor_entry.second;
    //     const auto& actor_view = actors_views.at(actor->get_id());
    //     actor_view->on_tick(tick_event);
    // }
    // const std::string big_string = "Very big string to reach the edge of the display. The quick brown fox jumps over the lazy dog.";
    // const ksdk::line_splitter splitter(graphics, 4, 200);
    // const std::vector<size_t> lines = splitter.split(big_string);
    // if (!lines.empty())
    // {
    //     std::string line = big_string.substr(0, lines[0]);
    //     graphics.draw_text(line, 0, 20);
    //     for (size_t i = 1; i < lines.size(); i++)
    //     {
    //         line = big_string.substr(lines[i-1], lines[i]-lines[i-1]);
    //         graphics.draw_text(line, 0, (i+1) * 20);
    //     }
    // }

    // ksdk::bitmap* bmp = graphics.load_bitmap("tick");
    // graphics.draw_bitmap(*bmp, 200, 200);
    // bmp = graphics.load_bitmap("tick_outline");
    // graphics.draw_bitmap(*bmp, 220, 200);
    // bmp = graphics.load_bitmap("cross_outline");
    // graphics.draw_bitmap(*bmp,240,200);
    // bmp = graphics.load_bitmap("cross");
    // graphics.draw_bitmap(*bmp,260,200);

    // for (Body* body: game_model.get_world().bodies)
    // {
    //     const int w = body->width.x;
    //     const int h = body->width.y;
    //     const int x = body->position.x - w/2;
    //     const int y = body->position.y - h/2;
    //     graphics.draw_rect(x, y, w, h);
    // }
    b2Vec2 position = b2Body_GetPosition(game_model.bodyId);
    graphics.draw_rect(position.x - 5, position.y - 5, 20, 20);

    position = b2Body_GetPosition(game_model.groundId);
    graphics.draw_rect(position.x - 25, position.y - 5, 100, 20);

    // box2cpp
    // position = game_model.b.GetPosition();
    // graphics.draw_ellipse(position.x + 3, position.y + 3, 6, 6, 1, 0.0f, 0.0f);

    // position = game_model.ground_box.GetPosition();
    // graphics.draw_rect(position.x - 25, position.y - 5, 100, 20);

    return 0;
}
