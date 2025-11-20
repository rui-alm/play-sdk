#pragma once

#include <cstddef>
#include <memory>
#include <queue>
#include <string>
#include <vector>

#include <listener/tick_listener.h>
#include <model/tick_event.h>
#include <system/system.h>
#include "test_state.h"

class test : public ksdk::tick_listener
{
public:
    test(ksdk::system& system, const std::string& title);
    virtual ~test() = default;

    virtual int on_tick(const ksdk::tick_event &tick_event) override;

    size_t get_id() const { return id; }
    std::string get_title() const { return title; }
    test_state get_state() const { return state; }
    void set_state(const test_state state) { this->state = state; }
    const std::vector<std::unique_ptr<test>>& get_sub_tests() const { return sub_tests; }

    void add_sub_test(std::unique_ptr<test>&& sub_test);
protected:
    const size_t id;
    ksdk::system& system;
    const std::string title;
    test_state state;
    bool sub_tests_passed;
    std::vector<std::unique_ptr<test>> sub_tests;
    std::queue<test*> test_queue;
private:
    static size_t id_counter;
};
