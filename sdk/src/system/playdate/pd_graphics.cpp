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