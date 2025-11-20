#pragma once

#include <memory>
#include <queue>

#include "event.h"

namespace ksdk
{
    class event_producer
    {
    public:
        event_producer(std::queue<std::unique_ptr<event>>& event_queue) : event_queue(event_queue) {}
    protected:
        std::queue<std::unique_ptr<event>>& event_queue;
    };
}
