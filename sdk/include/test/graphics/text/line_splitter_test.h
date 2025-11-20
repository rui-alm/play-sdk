#pragma once

#include <string>

#include "model/tick_event.h"
#include "system/system.h"
#include "test/model/test.h"

namespace ksdk
{
    class line_splitter_test : public test
    {
    public:
        static constexpr int WIDTH = 200;
        static const std::string BIG_STRING;

        line_splitter_test(ksdk::system& system);
        line_splitter_test(ksdk::system& system, const std::string& title);
    };
}
