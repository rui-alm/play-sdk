#include "test/graphics/font_test.h"

#include <string>
#include <vector>

ksdk::font_test::font_test(ksdk::system &system) : test(system, "Font test")
{
}

int ksdk::font_test::on_tick(const tick_event &tick_event)
{
    std::ignore = tick_event;
    std::vector<std::string> font_list;
    const int status = system.file_system().list_files("/System/Fonts", font_list);
    const std::vector<std::string> expected_font_list = {
        ""
    };
    state = status == 0 && font_list == expected_font_list ? PASSED : FAILED;
    return 0;
}
