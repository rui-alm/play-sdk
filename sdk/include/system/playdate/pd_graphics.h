#pragma once

#include <pd_api.h>

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
    private:
        playdate_graphics& pd_graphics;
    };
}