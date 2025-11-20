#pragma once

#include "listener/tick_listener.h"
#include "model/tick_event.h"
#include <tuple>

namespace ksdk
{
    class view : public tick_listener
    {
    public:
        virtual ~view() = default;
        virtual int on_tick(const tick_event& tick_event) override
        {
            std::ignore = tick_event;
            return 0;
        }
    };
}