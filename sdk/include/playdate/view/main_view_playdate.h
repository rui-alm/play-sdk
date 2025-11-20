#pragma once

#include "model/main_model.h"
#include "view/main_view.h"

class main_view_playdate : public main_view
{
public:
    main_view_playdate(ksdk::system_graphics& graphics, const class main_model& main_model);
    virtual ~main_view_playdate() = default;
    
    virtual int on_tick(const ksdk::tick_event& tick_event) override;
private:
    const class main_model& main_model;
};