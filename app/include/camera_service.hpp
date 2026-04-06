#ifndef CAMERA_TASK_HPP
#define CAMERA_TASK_HPP
#include "coal/communication.hpp"
#include "hal/camera.hpp"
#include "osal/queue.hpp"
#include "osal/timer.hpp"

enum class CameraTaskState { IDLE, RUNNING, STOPPED };

class CameraService {
 private:
  CameraTaskState state = CameraTaskState::IDLE;
  hal::Camera* camera;
  osal::Timer* timer;
  osal::Queue* queue;
  coal::Communication* communication;

  void idle();
  void running();
  void stopped();

 public:
  CameraTask(osal::Timer* timer, osal::Queue* queue, hal::Camera* camera,
             coal::Communication* communication);
  CameraTaskState get_state() const;
  void step(CameraTaskState state);
  void run(int iterations = -1);
  void start();
  void stop();
  ~CameraTask();
};  // class CameraTask

#endif  // CAMERA_TASK_HPP