#include "test/graphics/framebuffer_test.h"

ksdk::framebuffer_test::framebuffer_test(ksdk::system &system) : test(system, "Framebuffer test")
{
}

int ksdk::framebuffer_test::on_tick(const ksdk::tick_event &tick_event)
{
    std::ignore = tick_event;
    system.graphics().clear();
    system.graphics().draw_rect(0, 0, 2, 2);
    ksdk::bitmap* frame = system.graphics().get_framebuffer();
    int width;
    int height;
    int rowbytes;
    uint8_t* mask;
    uint8_t* data;
    system.graphics().get_bitmap_data(frame, &width, &height, &rowbytes, &mask, &data);
    state = FAILED;
    return 0;
}
