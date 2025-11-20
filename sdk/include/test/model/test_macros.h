#pragma once

#include <test/model/test.h>

#ifndef TEST
#define TEST(test_class, sub_test) \
class sub_test : public test \
{ \
        public: \
        sub_test(ksdk::system& system) : test(system, #sub_test) {\
    }\
        virtual int on_tick(const ksdk::tick_event& tick_event) override;\
};\
    int sub_test::on_tick(const ksdk::tick_event& tick_event)
#endif
