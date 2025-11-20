#include "system/playdate/pd_graphics.h"
#include "graphics/bitmap_table.h"
#include "graphics/types.h"
#include "pd_api/pd_api_gfx.h"
#include "playdate/graphics/pd_bitmap_table.h"
#include <memory>

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

ksdk::bitmap* graphics::load_bitmap(const std::string& path)
{
    const char* err;
    LCDBitmap* bitmap = pd_graphics.loadBitmap(path.c_str(), &err);
    return bitmap;
}

void graphics::free_bitmap(ksdk::bitmap* bitmap)
{
    pd_graphics.freeBitmap(bitmap);
}

void graphics::draw_bitmap(const ksdk::bitmap& bitmap, int x, int y)
{
    pd_graphics.drawBitmap(const_cast<ksdk::bitmap*>(&bitmap), x, y, kBitmapUnflipped);
}

std::unique_ptr<ksdk::bitmap_table> graphics::new_bitmap_table(const std::string& path, int count, int width, int height)
{
    auto bitmap_table = std::make_unique<ksdk::playdate::bitmap_table>(pd_graphics, path, count, width, height);
    return bitmap_table;
}