#pragma once

#include "model/tick_event.h"
#include "system/system.h"
#include "test/model/test.h"

namespace ksdk
{
    class line_splitter_test : public test
    {
    public:
        line_splitter_test(ksdk::system& system);
        virtual int on_tick(const ksdk::tick_event& tick_event) override;
    };
}
