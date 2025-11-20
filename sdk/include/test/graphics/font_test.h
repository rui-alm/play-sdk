#pragma once

#include "test/model/test.h"

namespace ksdk
{
    class font_test : public test
    {
    public:
        font_test(ksdk::system& system);
        virtual int on_tick(const ksdk::tick_event &tick_event) override;
    };
}
