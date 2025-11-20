#pragma once

#include "test.h"

namespace ksdk
{
    class location_test : public test
    {
    public:
        location_test(const ksdk::system& system) : test(system, "get_location") {}
        virtual int on_tick(const ksdk::tick_event& tick_event) override
        {
            std::ignore = tick_event;
            state = PASSED;
            return 1;
        }
    };

    class actor_test : public test
    {
    public:
        actor_test(const ksdk::system& system) : test(system, "Actor test")
        {
            auto test = std::make_unique<location_test>(system);
            add_sub_test(std::move(test));
        }
        virtual int on_tick(const ksdk::tick_event &tick_event) override;
    };
}
