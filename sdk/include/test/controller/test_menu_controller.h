#pragma once

#include <list>
#include <queue>

#include "controller/controller.h"
#include "controller/input_controller.h"
#include "listener/input_listener.h"
#include "system/system.h"
#include "test/model/test.h"
#include "test/view/test_menu_view.h"

class test_menu_controller : public ksdk::controller, public ksdk::input_listener
{
public:
    test_menu_controller(class input_controller& input_controller, ksdk::system& system);
    int on_tick(const ksdk::tick_event& tick_event) override;
private:
    ksdk::system& system;
    std::queue<test*> test_queue;
    test root_test;
    std::list<std::unique_ptr<test_menu_view>> selected_test_menu_views;
    const test* selected_test;
};
