#include "test/controller/test_menu_controller.h"

#include "model/tick_event.h"
#include "test/graphics/font_test.h"
#include "test/graphics/framebuffer_test.h"
#include "test/graphics/text/line_splitter_test.h"
#include "test/graphics/text_test.h"
#include "test/model/actor_test.h"
#include "test/model/test_state.h"

test_menu_controller::test_menu_controller(class input_controller& input_controller, ksdk::system& system)
    : system(system)
    , root_test(system, "Test results")
    , selected_test(&root_test)
{
    selected_test_menu_views.emplace_back(std::make_unique<test_menu_view>(system.graphics(), root_test));
    root_test.add_sub_test(std::move(std::make_unique<ksdk::actor_test>(system)));
    root_test.add_sub_test(std::move(std::make_unique<ksdk::font_test>(system)));
    root_test.add_sub_test(std::move(std::make_unique<ksdk::framebuffer_test>(system)));
    root_test.add_sub_test(std::move(std::make_unique<ksdk::text_test>(system)));
    root_test.add_sub_test(std::move(std::make_unique<ksdk::line_splitter_test>(system)));
    const std::vector<std::unique_ptr<test>>& sub_tests = root_test.get_sub_tests();
    for (size_t i=0; i<sub_tests.size(); i++)
    {
        class test* test = root_test.get_sub_tests()[i].get();
        test_queue.emplace(test);
    }
    grab(input_controller);
}

int test_menu_controller::on_tick(const ksdk::tick_event& tick_event)
{
    if (input_controller)
    {
        if (input_controller->get_pressed_keys() & ksdk::keys::Enter)
        {
            const size_t selected_test_index = selected_test_menu_views.back()->get_selected_test_index();
            const test* const selected_sub_test = selected_test->get_sub_tests()[selected_test_index].get();
            if (!selected_sub_test->get_sub_tests().empty())
            {
                selected_test = selected_sub_test;
                selected_test_menu_views.emplace_back(std::make_unique<test_menu_view>(system.graphics(), *selected_test));
            }
        }
        if (input_controller->get_pressed_keys() & ksdk::keys::Back)
        {
            if (selected_test_menu_views.size() == 1)
            {
                return 1;
            }
            selected_test_menu_views.pop_back();
            selected_test = &selected_test_menu_views.back()->get_test();
        }
        if (input_controller->get_pressed_keys() & ksdk::keys::Up)
        {
            selected_test_menu_views.back()->select_up();
        }
        if (input_controller->get_pressed_keys() & ksdk::keys::Down)
        {
            selected_test_menu_views.back()->select_down();
        }
    }
    root_test.on_tick(tick_event);
    selected_test_menu_views.back()->on_tick(tick_event);
    return 0;
}
