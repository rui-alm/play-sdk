#pragma once

#include "listener/tick_listener.h"

namespace ksdk
{
    class controller : public tick_listener
    {
    public:
        controller() = default;
        virtual ~controller() = default;
        virtual int on_tick(void* userdata) = 0;
    };
}
