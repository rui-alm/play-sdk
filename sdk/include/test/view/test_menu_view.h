#pragma once

#include <sstream>
#include <string>
#include <vector>

#include <model/tick_event.h>
#include <system/graphics.h>
#include <view/view.h>
#include <test/model/test.h>

class test_menu_view : public ksdk::view
{
public:
    test_menu_view(ksdk::system_graphics& graphics, const class test& test);

    int on_tick(const ksdk::tick_event &tick_event) override;

    void select_up();
    void select_down();
    size_t get_selected_test_index() const { return selected_test_index; }
    const class test& get_test() { return test; }
private:
    static std::string test_to_string(const class test& test);
    static char state_to_char(const test_state state);
    ksdk::system_graphics& graphics;
    const class test& test;
    size_t selected_test_index;
};
