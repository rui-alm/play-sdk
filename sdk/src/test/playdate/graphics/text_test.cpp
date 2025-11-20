#include "test/graphics/text_test.h"

ksdk::text_test::text_test(ksdk::system &system) : test(system, "Text test")
{
}

int ksdk::text_test::on_tick(const ksdk::tick_event &tick_event)
{
    std::ignore = tick_event;
    const int text_width = system.graphics().get_text_width("Hello world");
    state = text_width == 64 ? PASSED : FAILED;
    return 1;
}
