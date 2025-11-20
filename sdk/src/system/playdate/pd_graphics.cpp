#include "system/playdate/pd_graphics.h"
#include "pd_api/pd_api_gfx.h"

using namespace ksdk::playdate;

graphics::graphics(const playdate_graphics& pd_graphics) : pd_graphics(pd_graphics)
{
}

int graphics::draw_text(const std::string& text, int x, int y)
{
    const int ret = const_cast<playdate_graphics&>(pd_graphics).drawText(text.c_str(), text.size(), kUTF8Encoding, x, y);
    return ret;
}