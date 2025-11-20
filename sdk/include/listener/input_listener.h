#pragma once

#include "controller/input_controller.h"

namespace ksdk
{
    class input_listener
    {
    public:
        input_listener() : input_controller(nullptr) {}
        ~input_listener() = default;

        void grab(const class input_controller& input_controller)
        {
            this->input_controller = &input_controller;
        }
    protected:
        const class input_controller* input_controller;
    };
}
