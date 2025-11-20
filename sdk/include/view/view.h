#pragma once

#include "listener/tick_listener.h"

namespace ksdk
{
    class view : public tick_listener
    {
    public:
        virtual ~view() = default;
    };
}