#pragma once

#include "listener/tick_listener.h"
#include <tuple>

namespace ksdk
{
    class view : public tick_listener
    {
    public:
        virtual ~view() = default;
        virtual int on_tick(void *userdata) override
        {
            std::ignore = userdata;
            return 0;
        }
    };
}