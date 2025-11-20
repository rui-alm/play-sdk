#pragma once

#include "model/tick_event.h"
namespace ksdk {
    class tick_listener
    {
    public:
        tick_listener() = default;
        virtual ~tick_listener() = default;
        virtual int on_tick(const tick_event& tick_event) = 0;
    };
}
