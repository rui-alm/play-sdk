#pragma once

#include "graphics/bitmap_table.h"
#include "graphics/types.h"
#include <memory>
#include <string>

namespace ksdk
{
    class system_graphics
    {
    public:
        system_graphics() = default;
        virtual ~system_graphics() = default;

        virtual int clear() = 0;
        virtual int draw_text(const std::string& text, int x, int y) = 0;
        virtual int draw_rect(int x, int y, int width, int height) = 0;
        virtual int set_font(const std::string& path) = 0;
        virtual int get_font_height(const std::string& path, uint8_t& font_height) const = 0;
        virtual int get_text_width(const std::string& text) const = 0;
        virtual int get_text_width(const char* const text, const size_t size) const = 0;
        virtual ksdk::bitmap* load_bitmap(const std::string& path) = 0;
        virtual void free_bitmap(ksdk::bitmap* bitmap) = 0;
        virtual void draw_bitmap(const ksdk::bitmap& bitmap, int x, int y) = 0;
        virtual std::unique_ptr<ksdk::bitmap_table> new_bitmap_table(const std::string& path, int count, int width, int height) = 0;
        virtual void set_draw_offset(int x, int y) = 0;
        virtual ksdk::bitmap* get_framebuffer() = 0;
        virtual void get_bitmap_data(ksdk::bitmap* bitmap, int* width, int* height, int* rowbytes, uint8_t** mask, uint8_t** data) = 0;
    private:
    };
}
