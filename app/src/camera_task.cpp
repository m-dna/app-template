#include "camera_task.hpp"

CameraTask::CameraTask(osal::Timer* timer, osal::Queue* queue, hal::Camera* camera, coal::Communication* communication)
    : timer(timer), queue(queue), camera(camera), communication(communication) {
        state = CameraTaskState::IDLE;
}

CameraTask::~CameraTask() {
}

CameraTaskState CameraTask::get_state() const {
    return state;
}

void CameraTask::step(CameraTaskState state) {
    switch (state) {
        case CameraTaskState::IDLE:
            idle();
            break;
        case CameraTaskState::RUNNING:
            running();
            break;
        case CameraTaskState::STOPPED:
            stopped();
            break;
    }
}

void CameraTask::run(int iterations) {
    int count = 0;
    while (iterations < 0 || count < iterations && state != CameraTaskState::STOPPED) {
        step(state);
        count++;
        timer->delay_ms(100);
    }
}

void CameraTask::start() {
    state = CameraTaskState::RUNNING;
}

void CameraTask::stop() {
    state = CameraTaskState::STOPPED;
}

void CameraTask::idle() {
    // Perform any necessary idle operations
}

void CameraTask::running() {
    // Perform any necessary operations while running
    if (camera && communication) {
        uint8_t* image = camera->get_raw_image();
        communication->send_data(image, hal::IMAGE_SIZE);
    }
}

void CameraTask::stopped() {
    // Perform any necessary cleanup when stopped
}