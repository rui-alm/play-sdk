#pragma once

#include "listener/tick_listener.h"
#include "model/tick_event.h"

namespace ksdk
{
    class controller : public tick_listener
    {
    public:
        controller() = default;
        virtual ~controller() = default;
        virtual int on_tick(const tick_event& tick_event) = 0;
    };
}
