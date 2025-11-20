#pragma once

#include "assets/walls/wall.h"
#include "graphics/bitmap_table.h"
#include "graphics/types.h"
#include "system/graphics.h"
#include "view/view.h"
#include <tuple>
class wall_view : public ksdk::view
{
public:
    wall_view(ksdk::system_graphics& graphics, const wall& wall,
            const ksdk::bitmap_table& bitmap_table)
            : graphics(graphics), wall(wall)
            , bitmap_table(bitmap_table) {}
    virtual ~wall_view() = default;
    virtual int on_tick(const ksdk::tick_event& tick_event) override
    {
        std::ignore = tick_event;
        const int idx = 0;
        ksdk::bitmap& bitmap = bitmap_table.get(idx);
        graphics.draw_bitmap(bitmap, wall.get_x(), wall.get_y());
        return 0;
    }
private:
    ksdk::system_graphics& graphics;
    const class wall& wall;
    const ksdk::bitmap_table& bitmap_table;
};