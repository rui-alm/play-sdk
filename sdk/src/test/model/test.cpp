#include "test/model/test.h"

size_t test::id_counter = 0;

test::test(ksdk::system& system, const std::string& title)
    : id(id_counter++), system(system), title(title), state(INITIALIZED), result(true), sub_tests_passed(true)
{
}

int test::on_tick(const ksdk::tick_event &tick_event)
{
    constexpr float frame_time = 1.0f / 20.0f;
    const float tick_start_time = system.get_current_time_milliseconds();
    const float time_since_last_tick = tick_event.get_delta_seconds() / 1000.0f;

    while (!test_queue.empty())
    {
        auto& test = test_queue.front();
        const test_state sub_test_state = test->get_state();
        switch(sub_test_state)
        {
        case INITIALIZED:
        {
            test->set_state(RUNNING);
            const int finished = test->on_tick(tick_event);
            if (finished)
            {
                test->state = test->result ? PASSED : FAILED;
                sub_tests_passed &= test->result;
                result &= sub_tests_passed;
                test_queue.pop();
            }
            break;
        }
        case RUNNING:
        {
            const int finished = test->on_tick(tick_event);
            if (finished)
            {
                test->state = test->result ? PASSED : FAILED;
                sub_tests_passed &= test->result;
                result &= sub_tests_passed;
                test_queue.pop();
            }
            break;
        }
        case FAILED:
            sub_tests_passed = false;
            test_queue.pop();
            break;
        default:
            test_queue.pop();
        }
        const float current_time = system.get_current_time_milliseconds();
        const float elapsed_time = current_time - tick_start_time + time_since_last_tick;
        if (elapsed_time >= frame_time)
            break;
    }
    if (test_queue.empty())
    {
        state = sub_tests_passed ? PASSED : FAILED;
        return 1;
    }
    return 0;
}

void test::add_sub_test(std::unique_ptr<test>&& sub_test)
{
    test_queue.emplace(sub_test.get());
    sub_tests.emplace_back(std::move(sub_test));
}
