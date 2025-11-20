#include "playdate/view/main_view_playdate.h"
#include <string>
#include <tuple>
#include "model/main_model.h"
#include "view/main_view.h"

main_view_playdate::main_view_playdate(ksdk::system_graphics& graphics,
    const class main_model& main_model) :
    main_view(graphics)
    , main_model(main_model)
{
    graphics.set_font("/System/Fonts/Asheville-Sans-14-Bold.pft");
}

int main_view_playdate::on_tick(void* userdata)
{
    std::ignore = userdata;
    const int selected_menu = main_model.get_selected_menu();
    graphics.clear();
    const std::string menu = "New Game " + std::to_string(selected_menu);
    const int x = 100;
    const int y = 100;
    graphics.draw_text(menu, 100, 100);
    constexpr int height = 16;
    const int width = menu.size() * 10;
    graphics.draw_rect(x-2, y-1, width, height+2);
    return 0;
}
