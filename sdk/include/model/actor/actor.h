#pragma once

#include <tuple>

#include "listener/tick_listener.h"

namespace ksdk {
    class actor : public tick_listener
    {
    public:
        actor() : actor(0, 0) {}
        actor(int x, int y) : x(x), y(y) {}
        virtual ~actor() = default;
        virtual int on_tick(void *userdata) override
        {
            std::ignore = userdata;
            return 0;
        }
        int get_x() const { return x; }
        int get_y() const { return y; }
    protected:
        int x;
        int y;
    private:
    };
}