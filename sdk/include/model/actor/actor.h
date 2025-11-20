#pragma once

#include <tuple>

#include "listener/tick_listener.h"
#include "model/tick_event.h"

namespace ksdk {
    class actor : public tick_listener
    {
    public:
        actor() : actor(0.0f, 0.0f) {}
        actor(float x, float y) : id(id_counter++), x(x), y(y) {}
        virtual ~actor() = default;
        virtual int on_tick(const tick_event& tick_event) override
        {
            std::ignore = tick_event;
            return 0;
        }
        int get_id() const { return id; }
        float get_x() const { return x; }
        float get_y() const { return y; }
        void set_x(float x) { this->x = x; }
    private:
        static int id_counter;
        const int id;
    protected:
        float x;
        float y;
    };
}
