#include "graphics/text/line_splitter.h"

ksdk::line_splitter::line_splitter(const ksdk::system_graphics& graphics, const size_t number_of_lines, const int max_width)
    : graphics(graphics), number_of_lines(number_of_lines), max_width(max_width)
{
    // Warn if width or number of lines is zero
}

std::vector<size_t> ksdk::line_splitter::split(const std::string& text) const
{
    std::vector<size_t> indexes;
    size_t search_start_index = 0;
    const size_t search_end_index = text.size();
    while(search_start_index < search_end_index && indexes.size() < number_of_lines)
    {
        const size_t index = max_index_that_fits(text.c_str(), search_start_index, search_end_index);
        indexes.emplace_back(index);
        search_start_index = index;
    }
    return indexes;
}

size_t ksdk::line_splitter::max_index_that_fits(const char* text, const size_t start_index, const size_t end_index) const
{
    size_t search_start_ptr = start_index;
    size_t search_end_ptr = end_index;
    size_t previous_search_end_ptr = search_end_ptr;
    size_t last_fitting_end_index = search_end_ptr;
    int width;
    while (search_start_ptr < search_end_ptr)
    {
        width = graphics.get_text_width(text+start_index, search_end_ptr-start_index);
        if (width > max_width)
        {
            previous_search_end_ptr = search_end_ptr;
            search_end_ptr = search_start_ptr + (search_end_ptr-search_start_ptr) / 2;
        }
        else
        {
            search_start_ptr = search_end_ptr;
            last_fitting_end_index = search_end_ptr;
            search_end_ptr += (previous_search_end_ptr - search_end_ptr) / 2;
        }
    }
    return last_fitting_end_index;
}
