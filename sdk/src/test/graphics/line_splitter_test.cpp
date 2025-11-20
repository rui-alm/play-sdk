#include "test/graphics/text/line_splitter_test.h"

#include "graphics/text/line_splitter.h"
#include "test/controller/test_menu_controller.h"
#include "test/model/test_macros.h"
#include "test/model/type_assertions.h"

const std::string ksdk::line_splitter_test::BIG_STRING = "A very big string to push the limits of the splitter"; // width ~359

// Explore the idea of having the root test as a static ptr

TEST(line_splitter_test, zero_line)
{
    std::ignore = tick_event;
    const ksdk::line_splitter line_splitter(system.graphics(), 0, ksdk::line_splitter_test::WIDTH);
    const std::vector<size_t> split_indexes = line_splitter.split(ksdk::line_splitter_test::BIG_STRING);
    ASSERT_EMPTY(split_indexes);
    return 1;
}

TEST(line_splitter_test, zero_width)
{
    std::ignore = tick_event;
    const size_t number_of_lines = 1;
    const ksdk::line_splitter line_splitter(system.graphics(), 1, 0);
    const std::vector<size_t> split_indexes = line_splitter.split(ksdk::line_splitter_test::BIG_STRING);
    ASSERT_EQ(split_indexes.size(), number_of_lines);
    return 1;
}

TEST(line_splitter_test, zero_length_width)
{
    std::ignore = tick_event;
    const ksdk::line_splitter line_splitter(system.graphics(), 1, ksdk::line_splitter_test::WIDTH);
    const std::vector<size_t> split_indexes = line_splitter.split("");
    ASSERT_EMPTY(split_indexes);
    return 1;
}

TEST(line_splitter_test, one_line_splitter)
{
    std::ignore = tick_event;
    const size_t number_of_lines = 1;
    const ksdk::line_splitter line_splitter(system.graphics(), number_of_lines, ksdk::line_splitter_test::WIDTH);
    const std::vector<size_t> split_indexes = line_splitter.split(ksdk::line_splitter_test::BIG_STRING);
    ASSERT_EQ(split_indexes.size(), number_of_lines);
    return 1;
}

TEST(line_splitter_test, two_line_splitter)
{
    std::ignore = tick_event;
    const size_t number_of_lines = 2;
    const ksdk::line_splitter line_splitter(system.graphics(), number_of_lines, ksdk::line_splitter_test::WIDTH);
    const std::vector<size_t> split_indexes = line_splitter.split(ksdk::line_splitter_test::BIG_STRING);
    ASSERT_EQ(split_indexes.size(), number_of_lines);
    return 1;
}


TEST(line_splitter_test, three_line_splitter)
{
    std::ignore = tick_event;
    const size_t number_of_lines = 3;
    const size_t expected_split_indexes = 2;
    const ksdk::line_splitter line_splitter(system.graphics(), number_of_lines, ksdk::line_splitter_test::WIDTH);
    const std::vector<size_t> split_indexes = line_splitter.split(ksdk::line_splitter_test::BIG_STRING);
    ASSERT_EQ(split_indexes.size(), expected_split_indexes);
    return 1;
}

ksdk::line_splitter_test::line_splitter_test(ksdk::system &system) : line_splitter_test(system, "line_splitter_test")
{
}

ksdk::line_splitter_test::line_splitter_test(ksdk::system& system, const std::string& title) : test(system, title)
{
    add_sub_test(std::move(std::make_unique<zero_line>(system)));
    add_sub_test(std::move(std::make_unique<zero_width>(system)));
    add_sub_test(std::move(std::make_unique<zero_length_width>(system)));
    add_sub_test(std::move(std::make_unique<one_line_splitter>(system)));
    add_sub_test(std::move(std::make_unique<two_line_splitter>(system)));
    add_sub_test(std::move(std::make_unique<three_line_splitter>(system)));
}
