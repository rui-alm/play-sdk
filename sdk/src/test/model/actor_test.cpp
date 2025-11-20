#include "test/model/actor_test.h"

#include <model/actor/actor.h>

int ksdk::actor_test::on_tick(const ksdk::tick_event &tick_event)
{
    while (test::on_tick(tick_event))
    {
        actor a(0.0f, 0.0f);
        const float x = a.get_x();
        const float y = a.get_y();
        const bool assert_x = x == 0.0f;
        const bool assert_y = y == 0.0f;
        const bool result = assert_x && assert_y;
        state = (!result || !sub_tests_passed) ? FAILED : PASSED;
        return 1;
    }
    return 0;
}
