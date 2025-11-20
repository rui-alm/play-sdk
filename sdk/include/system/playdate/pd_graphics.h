#pragma once

#include <pd_api.h>

#include "system/graphics.h"

namespace ksdk::playdate {

    class graphics : public ksdk::system_graphics
    {
    public:
        graphics(const playdate_graphics& pd_graphics);
        virtual ~graphics() = default;

        int clear() override;
        int draw_text(const std::string& text, int x, int y) override;
    private:
        playdate_graphics& pd_graphics;
    };
}