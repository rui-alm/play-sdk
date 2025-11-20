#pragma once

#include "graphics/types.h"
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
        virtual ksdk::bitmap* load_bitmap(const std::string& path) = 0;
        virtual void free_bitmap(ksdk::bitmap* bitmap) = 0;
        virtual void draw_bitmap(ksdk::bitmap* bitmap, int x, int y) = 0;
        virtual ksdk::bitmap_table* new_bitmap_table(int count, int width, int height) = 0;
        virtual ksdk::bitmap* get_table_bitmap(ksdk::bitmap_table* bitmap_table, int idx) = 0;
        virtual void load_into_bitmap_table(const std::string& path, ksdk::bitmap_table* bitmap_table) = 0;
        virtual void free_bitmap_table(ksdk::bitmap_table* bitmap_table) = 0;
    private:
    };
}