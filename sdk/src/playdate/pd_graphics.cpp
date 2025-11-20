#include "system/playdate/pd_graphics.h"

#include <memory>

#include "graphics/bitmap_table.h"
#include "graphics/types.h"
#include "pd_api/pd_api_gfx.h"
#include "playdate/graphics/pd_bitmap_table.h"
#include "playdate/system/pd_system.h"

using namespace ksdk::playdate;

graphics::graphics(const playdate_graphics& pd_graphics)
    : pd_graphics(const_cast<playdate_graphics&>(pd_graphics))
    , selected_font(nullptr, &graphics::free_font)
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
    selected_font = std::unique_ptr<LCDFont,void(*)(LCDFont*)>(font, &free_font);
    pd_graphics.setFont(font);
    return 0;
}

void graphics::free_font(LCDFont *font)
{
    std::ignore = font;
    // TODO check need to free loaded fonts
    // pd_system::system->pd.system->realloc(font, 0);
}

int graphics::get_font_height(const std::string &path, uint8_t& font_height) const
{
    const char* err;
    LCDFont* const font = pd_graphics.loadFont(path.c_str(), &err);
    font_height = pd_graphics.getFontHeight(font);
    return 0;
}

int graphics::get_text_width(const std::string& text) const
{
    const int width = pd_graphics.getTextWidth(selected_font.get(), text.c_str(), text.size(), kUTF8Encoding, 0);
    return width;
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

void graphics::set_draw_offset(int x, int y)
{
    pd_graphics.setDrawOffset(x, y);
}

ksdk::bitmap* graphics::get_framebuffer()
{
    ksdk::bitmap* frame = pd_graphics.copyFrameBufferBitmap();
    return frame;
}

void graphics::get_bitmap_data(ksdk::bitmap* bitmap, int* width, int* height, int* rowbytes, uint8_t** mask, uint8_t** data)
{
    pd_graphics.getBitmapData(bitmap, width, height, rowbytes, mask, data);
}
