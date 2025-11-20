#include "views/main_view.h"
#include "system/graphics.h"

main_view::main_view(ksdk::system_graphics& graphics) : graphics(graphics)
{
}

int main_view::on_tick()
{
    graphics.draw_text("Hello world", 100, 100);
    return 0;
}