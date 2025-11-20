#pragma once

#include "graphics/types.h"

namespace ksdk {
    class bitmap_table
    {
    public:
        bitmap_table() = default;
        virtual ~bitmap_table() = default;
        virtual ksdk::bitmap& get(int idx) const = 0;
    };
}