#ifndef MOCK_CAMERA_HPP
#define MOCK_CAMERA_HPP

#include "gmock/gmock.h"
#include "hal/camera.hpp"

class MockCamera : public hal::Camera {
public:
    MOCK_METHOD(uint8_t*, get_raw_image, (), (override));
}; // class MockCamera

#endif // MOCK_CAMERA_HPP