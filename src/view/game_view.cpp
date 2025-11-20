#include "view/game_view.h"
#include "system/graphics.h"
#include <tuple>

game_view::game_view(ksdk::system_graphics& graphics) : graphics(graphics), bitmap_table(graphics.new_bitmap_table(1, 32, 32))
{
    graphics.load_into_bitmap_table("bitmap", bitmap_table);
}

game_view::~game_view()
{
    graphics.free_bitmap_table(bitmap_table);
}

int game_view::on_tick(void* userdata)
{
    std::ignore = userdata;
    graphics.clear();
    const int idx = 0;
    ksdk::bitmap* bitmap = graphics.get_table_bitmap(bitmap_table, idx);
    graphics.draw_bitmap(bitmap, 0, 0);
    return 0;
}