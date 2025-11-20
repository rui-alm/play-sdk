#pragma once

#include <pd_api.h>

#include "graphics/types.h"
#include "system/graphics.h"

namespace ksdk::playdate {

    class graphics : public ksdk::system_graphics
    {
    public:
        graphics(const playdate_graphics& pd_graphics);
        virtual ~graphics() = default;

        virtual int clear() override;
        virtual int draw_text(const std::string& text, int x, int y) override;
        virtual int draw_rect(int x, int y, int width, int height) override;
        virtual int set_font(const std::string& path) override;
        virtual ksdk::bitmap* load_bitmap(const std::string& path) override;
        virtual void free_bitmap(ksdk::bitmap* bitmap) override;
        virtual void draw_bitmap(ksdk::bitmap* bitmap, int x, int y) override;
        virtual ksdk::bitmap_table* new_bitmap_table(int count, int width, int height) override;
        virtual ksdk::bitmap* get_table_bitmap(ksdk::bitmap_table* bitmap_table, int idx) override;
        virtual void load_into_bitmap_table(const std::string& path, ksdk::bitmap_table* bitmap_table) override;
        virtual void free_bitmap_table(ksdk::bitmap_table* bitmap_table) override;
    private:
        playdate_graphics& pd_graphics;
    };
}