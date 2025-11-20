#pragma once

#include "test/model/test.h"
#include <model/tick_event.h>
#include <system/system.h>

namespace ksdk
{
    class text_test : public test
    {
    public:
        text_test(ksdk::system& system);
        virtual int on_tick(const ksdk::tick_event& tick_event) override;
    };
}
