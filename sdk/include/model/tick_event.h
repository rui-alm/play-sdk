#pragma once

namespace ksdk {
    class tick_event
    {
    public:
        tick_event(float delta_seconds) : delta_seconds(delta_seconds) {}

        float get_delta_seconds() const { return delta_seconds; }
    private:
        float delta_seconds;
    };
}