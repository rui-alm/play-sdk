#pragma once

#include "graphics/bitmap_table.h"
#include "model/game_model.h"
#include "system/graphics.h"
#include "view/view.h"
// #include <unordered_map>
class game_view : ksdk::view
{
public:
    game_view(ksdk::system_graphics& graphics, const class game_model& game_model);
    virtual ~game_view() = default;

    int on_tick(const ksdk::tick_event& tick_event) override;
    
    // template<class ACTOR_VIEW, class... ARGS>
    // void add_actor_view(const int id, ARGS&&... args)
    // {
    //     actors_views.emplace(id, std::make_unique<ACTOR_VIEW>(args...));
    // }
private:
    ksdk::system_graphics& graphics;
    // std::unique_ptr<ksdk::bitmap_table> bitmap_table;
    const class game_model& game_model;
    // std::unordered_map<int, std::unique_ptr<ksdk::view>> actors_views;
};
