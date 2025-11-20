#include "test/view/test_menu_view.h"

test_menu_view::test_menu_view(ksdk::system_graphics& graphics, const class test& test)
    : graphics(graphics)
    , test(test)
    , selected_test_index(0)
{
}

int test_menu_view::on_tick(const ksdk::tick_event &tick_event)
{
    std::ignore = tick_event;
    graphics.clear();
    int x = 15;
    int y = 15;
    std::string str = test_to_string(test);
    graphics.draw_text(str, x, y);
    x += 15;
    size_t idx = 0;
    for (auto& sub_test: test.get_sub_tests())
    {
        y += 16;
        str = test_to_string(*sub_test);
        if (selected_test_index == idx)
        {
            graphics.draw_text("->", x-15, y);
        }
        graphics.draw_text(str, x, y);
        idx++;
    }
    return 0;
}

void test_menu_view::select_up()
{
    selected_test_index = selected_test_index == 0 ? test.get_sub_tests().size() - 1: selected_test_index - 1;
}

void test_menu_view::select_down()
{
    selected_test_index = (selected_test_index == test.get_sub_tests().size() - 1) ? 0 : selected_test_index + 1;
}

std::string test_menu_view::test_to_string(const class test& test)
{
    std::stringstream ss;
    const int test_id = test.get_id();
    const std::string test_title = test.get_title();
    const char test_passed = state_to_char(test.get_state());
    const char breadcrumb = test.get_sub_tests().empty() ? '-' : '+';
    ss << breadcrumb << '[' << test_passed << ']' << '[' << test_id << "] " << test_title;
    std::string str = ss.str();
    return str;
}

char test_menu_view::state_to_char(const test_state state)
{
    switch(state)
    {
    case INITIALIZED:
        return 'I';
    case RUNNING:
        return 'R';
    case PASSED:
        return 'P';
    case FAILED:
        return 'F';
    }
    return 'E';
}
