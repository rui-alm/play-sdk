#include "system/playdate/pd_graphics.h"
#include "pd_api/pd_api_gfx.h"

using namespace ksdk::playdate;

graphics::graphics(const playdate_graphics& pd_graphics) : pd_graphics(const_cast<playdate_graphics&>(pd_graphics))
{
}

int graphics::clear()
{
    pd_graphics.clear(kColorWhite);
    return 0;
}

int graphics::draw_text(const std::string& text, int x, int y)
{
    const int ret = pd_graphics.drawText(text.c_str(), text.size(), kUTF8Encoding, x, y);
    return ret;
}

int graphics::draw_rect(int x, int y, int width, int height)
{
    pd_graphics.drawRect(x, y, width, height, kColorBlack);
    return 0;
}

int graphics::set_font(const std::string& path)
{
    const char* err;
    LCDFont* const font = pd_graphics.loadFont(path.c_str(), &err);
    pd_graphics.setFont(font);
    return 0;
}