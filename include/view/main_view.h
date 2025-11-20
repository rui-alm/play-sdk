#pragma once

#include "controller/input_controller.h"
#include "system/graphics.h"
#include "view/view.h"

class main_view : public ksdk::view
{
public:
    main_view(ksdk::system_graphics& graphics);
    virtual ~main_view() = default;
    
    virtual int on_tick(void* userdata) override;

protected:
    ksdk::system_graphics& graphics;
};