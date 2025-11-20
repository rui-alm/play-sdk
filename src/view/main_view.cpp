#include "view/main_view.h"
#include "system/graphics.h"

#include <array>
#include <string>
#include <tuple>

main_view::main_view(ksdk::system_graphics& graphics, const class main_model& main_model)
    : graphics(graphics), main_model(main_model)
{
}

int main_view::on_tick(const ksdk::tick_event& tick_event)
{
    std::ignore = tick_event;
    const int selected_menu = main_model.get_selected_menu();
    std::array<std::string, 2> menus {"New game", "Tests"};

    graphics.clear();
    const std::string menu = menus.at(selected_menu);
    const int x = 100;
    const int y = 100;
    graphics.draw_text(menu, 100, 100);
    constexpr int height = 16;
    const int width = menu.size() * 10;
    graphics.draw_rect(x-2, y-1, width, height+2);
    return 0;
}
