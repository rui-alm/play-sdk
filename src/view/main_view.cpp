#include "view/main_view.h"
#include "system/graphics.h"
#include <tuple>

main_view::main_view(ksdk::system_graphics& graphics) : graphics(graphics)
{
}

int main_view::on_tick(void* userdata)
{
    std::ignore = userdata;
    return 0;
}