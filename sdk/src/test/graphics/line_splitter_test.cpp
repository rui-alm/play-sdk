#include "test/graphics/text/line_splitter_test.h"

#include "graphics/text/line_splitter.h"
#include "playdate/system/logger.h"

ksdk::line_splitter_test::line_splitter_test(ksdk::system &system) : test(system, "line_splitter_test")
{
}

int ksdk::line_splitter_test::on_tick(const ksdk::tick_event& tick_event)
{
    std::ignore = tick_event;
    const std::string big_string = "A very big string to push the limits of the splitter"; // width ~359
    const int width = 200;
    bool result = true;
    // Test zero line splitter
    {
        const ksdk::line_splitter line_splitter(system.graphics(), 0, width);
        const std::vector<size_t> split_indexes = line_splitter.split(big_string);
        const bool assert = split_indexes.empty();
        result &= assert;
        if (!assert)
        {
            ERR("Expected: 0, got: %u", split_indexes.size());
        }
    }
    // Test zero width splitter
    {
        const size_t number_of_lines = 1;
        const ksdk::line_splitter line_splitter(system.graphics(), 1, 0);
        const std::vector<size_t> split_indexes = line_splitter.split(big_string);
        const bool assert = split_indexes.size() == number_of_lines;
        result &= assert;
        if (!assert)
        {
            ERR("Expected: %u, got: %u", number_of_lines, split_indexes.size());
        }
    }
    // Test zero length string
    {
        const ksdk::line_splitter line_splitter(system.graphics(), 1, width);
        const std::vector<size_t> split_indexes = line_splitter.split("");
        const bool assert = split_indexes.empty();
        result &= assert;
        if (!assert)
        {
            ERR("Expected: 0, got: %u", split_indexes.size());
        }
    }
    // Test 1 line splitter
    {
        const size_t number_of_lines = 1;
        const ksdk::line_splitter line_splitter(system.graphics(), number_of_lines, width);
        const std::vector<size_t> split_indexes = line_splitter.split(big_string);
        const bool assert = split_indexes.size() == number_of_lines;
        result &= assert;
        if (!assert)
        {
            ERR("Expected: %u, got: %u", number_of_lines, split_indexes.size());
        }
    }
    // Test 2 line splitter
    {
        const size_t number_of_lines = 2;
        const ksdk::line_splitter line_splitter(system.graphics(), number_of_lines, width);
        const std::vector<size_t> split_indexes = line_splitter.split(big_string);
        const bool assert = split_indexes.size() == number_of_lines;
        result &= assert;
        if (!assert)
        {
            ERR("Expected: %u, got: %u", number_of_lines, split_indexes.size());
        }
    }
    // Test 3 line splitter
    {
        const size_t number_of_lines = 3;
        const size_t expected_split_indexes = 2;
        const ksdk::line_splitter line_splitter(system.graphics(), number_of_lines, width);
        const std::vector<size_t> split_indexes = line_splitter.split(big_string);
        const bool assert = split_indexes.size() == expected_split_indexes;
        result &= assert;
        if (!assert)
        {
            ERR("Expected: %u, got: %u", expected_split_indexes, split_indexes.size());
        }
    }
    state = result ? PASSED : FAILED;
    return 1;
}
