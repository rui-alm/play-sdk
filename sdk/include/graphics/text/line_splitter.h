#pragma once

#include <string>
#include <vector>

#include "system/graphics.h"

namespace ksdk
{
    class line_splitter
    {
    public:
        line_splitter(const ksdk::system_graphics& graphics, const size_t number_of_lines, const int max_width);

        std::vector<size_t> split(const std::string& text) const;
    private:
        const ksdk::system_graphics& graphics;
        const size_t number_of_lines;
        const int max_width;

        size_t max_index_that_fits(const char* text, const size_t start_index, const size_t end_index) const;
    };
}
