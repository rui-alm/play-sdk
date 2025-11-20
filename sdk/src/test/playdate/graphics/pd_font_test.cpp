#include "test/graphics/font_test.h"

#include <string>
#include <unordered_map>
#include <vector>

ksdk::font_test::font_test(ksdk::system &system) : test(system, "Font test")
{
    auto test = std::make_unique<font_height_test>(system);
    add_sub_test(std::move(test));
}

int ksdk::font_test::on_tick(const tick_event &tick_event)
{
    while (test::on_tick(tick_event))
    {
        std::vector<std::string> font_list;
        const int status = system.file_system().list_files("/System/Fonts", font_list);
        const std::vector<std::string> expected_font_list = {
            "Asheville-Sans-14-Bold.pft",
            "Asheville-Sans-14-Light-Oblique.pft",
            "Asheville-Sans-14-Light.pft",
            "Asheville-Sans-24-Light.pft",
            "Roobert-10-Bold.pft"
        };
        state = status == 0 && font_list == expected_font_list ? PASSED : FAILED;
        return 1;
    }
    return 0;
}

ksdk::font_height_test::font_height_test(ksdk::system& system) : test(system, "Font height")
{
}

int ksdk::font_height_test::on_tick(const tick_event &tick_event)
{
    std::ignore = tick_event;
    std::vector<std::string> font_list;
    const int status = system.file_system().list_files("/System/Fonts", font_list);
    if (status != 0)
    {
        // log error
    }
    const std::unordered_map<std::string, uint8_t> expected_font_heights = {
        {"Asheville-Sans-14-Bold.pft", 20},
        {"Asheville-Sans-14-Light-Oblique.pft", 20},
        {"Asheville-Sans-14-Light.pft", 20},
        {"Asheville-Sans-24-Light.pft", 32},
        {"Roobert-10-Bold.pft", 14}
    };
    bool result = font_list.size() == expected_font_heights.size();
    for (const std::string& font_path: font_list)
    {
        uint8_t font_height = 0;
        system.graphics().get_font_height("/System/Fonts/" + font_path, font_height);
        const uint8_t expected_font_height = expected_font_heights.at(font_path);
        if (font_height != expected_font_height)
        {
            result = false;
        }
    }
    state = result ? PASSED : FAILED;
    return 1;
}
