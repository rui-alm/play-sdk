#include "playdate/view/main_view_playdate.h"
#include "model/main_model.h"
#include "pd_api/pd_api_gfx.h"
#include "view/main_view.h"
#include <string>
#include <sys/types.h>
#include <tuple>

main_view_playdate::main_view_playdate(ksdk::system_graphics& graphics, const class main_model& main_model) :
    main_view(graphics)
    , main_model(main_model)
{
}

int main_view_playdate::on_tick(void* userdata)
{
    std::ignore = userdata;
    const int selected_menu = main_model.get_selected_menu();
    graphics.clear();
    const std::string menu = "Menu " + std::to_string(selected_menu);
    graphics.draw_text(menu, 100, 100);
    return 0;
}
