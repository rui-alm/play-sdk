#pragma once

#include <cstdint>

#include "controller/controller.h"
#include "system/system.h"

class input_controller : public ksdk::controller
{
public:
    input_controller(ksdk::system& system);
    virtual ~input_controller() = default;
    virtual int key_pressed(uint32_t key);

    virtual int on_tick(void* userdata) override;

    virtual inline ksdk::keys get_down_keys() const { return down_keys; }
    virtual inline ksdk::keys get_pressed_keys() const { return pressed_keys; }
private:
    ksdk::system& system;
    ksdk::keys down_keys;
    ksdk::keys pressed_keys;
    ksdk::keys released_keys;
};