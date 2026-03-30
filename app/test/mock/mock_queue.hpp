#ifndef MOCK_QUEUE_HPP
#define MOCK_QUEUE_HPP

#include "gmock/gmock.h"
#include "osal/queue.hpp"

class MockQueue : public osal::Queue {
public:
    MOCK_METHOD(void, send, (const void* data, uint32_t size), (override));
    MOCK_METHOD(void, receive, (void* data, uint32_t size), (override));
}; // class MockQueue

#endif // MOCK_QUEUE_HPP