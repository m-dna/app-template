#ifndef MOCK_COMMUNICATION_HPP
#define MOCK_COMMUNICATION_HPP

#include "gmock/gmock.h"
#include "coal/communication.hpp"

class MockCommunication : public coal::Communication {
public:
    MOCK_METHOD(void, send_data, (const void* data, uint32_t size), (override));
    MOCK_METHOD(void, receive_data, (void* data, uint32_t size), (override));
}; // class MockCommunication

#endif // MOCK_COMMUNICATION_HPP