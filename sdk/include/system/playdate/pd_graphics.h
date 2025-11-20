#pragma once

#include <memory>
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
        virtual void draw_bitmap(const ksdk::bitmap& bitmap, int x, int y) override;
        virtual std::unique_ptr<ksdk::bitmap_table> new_bitmap_table(const std::string& path, int count, int width, int height) override;
        virtual void set_draw_offset(int x, int y) override;
    private:
        playdate_graphics& pd_graphics;
    };
}