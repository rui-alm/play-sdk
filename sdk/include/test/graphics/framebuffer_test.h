#pragma once

#include "test/model/test.h"

namespace ksdk
{
    class framebuffer_test : public test
    {
    public:
        framebuffer_test(ksdk::system& system);
        virtual int on_tick(const ksdk::tick_event& tick_event) override;
    };
}
