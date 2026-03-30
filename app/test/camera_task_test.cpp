#include "camera_task.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_camera.hpp"
#include "mock_communication.hpp"
#include "mock_queue.hpp"
#include "mock_timer.hpp"

class CameraTaskTest : public ::testing::Test {
 protected:
  MockTimer timer;
  MockQueue queue;
  MockCamera camera;
  MockCommunication communication;

  CameraTask camera_task{&timer, &queue, &camera, &communication};

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(CameraTaskTest, CheckStateAndStart) {
  // given
  EXPECT_EQ(camera_task.get_state(), CameraTaskState::IDLE);

  // when
  camera_task.start();

  // then
  EXPECT_EQ(camera_task.get_state(), CameraTaskState::RUNNING);
}

TEST_F(CameraTaskTest, StartAndStop) {
  // given
  EXPECT_CALL(timer, delay_ms(testing::_)).Times(testing::AtLeast(5));
  EXPECT_CALL(camera, get_raw_image()).Times(testing::AtLeast(5));
  EXPECT_CALL(communication, send_data(testing::_, testing::_))
      .Times(testing::AtLeast(5));

  // when
  camera_task.start();
  camera_task.run(5);
  camera_task.stop();
}