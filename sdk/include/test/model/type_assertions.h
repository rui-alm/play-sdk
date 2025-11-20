#pragma once

#include <logger/logger.h>
#include <test/model/test.h>

#ifndef ASSERT_EQ
#define ASSERT_EQ(actual, expected)\
{\
        const bool result = assert_eq(actual, expected);\
        this->result &= result;\
        if (!result)\
    {\
            ERR("Assertion error, expected: %s, got: %s", ksdk::to_string(expected).c_str(), ksdk::to_string(actual).c_str());\
    }\
}
#endif

#ifndef ASSERT_EMPTY
#define ASSERT_EMPTY(container)\
{\
        const bool result = assert_empty(container);\
        this->result &= result;\
        if (!result)\
    {\
            ERR("Assertion error, expected empty, got size: %s", ksdk::to_string(container.size()).c_str());\
    }\
}
#endif
