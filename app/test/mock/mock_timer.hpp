#ifndef MOCK_TIMER_HPP
#define MOCK_TIMER_HPP

#include "gmock/gmock.h"
#include "osal/timer.hpp"

class MockTimer : public osal::Timer {
public:
    MOCK_METHOD(void, delay_ms, (uint32_t milliseconds), (override));
}; // class MockTimer

#endif // MOCK_TIMER_HPP