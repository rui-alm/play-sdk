#pragma once

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
    private:
    };
}