// YourLibrary.cpp
#include "include/IVideoManager.h"

#include "include/engine.h"

namespace VideoCapturer {

extern "C" {

void * createEngine() {
    Engine * engine = Engine::instance();
    return static_cast < void * > (engine);
}

void releaseEngine(void* engine) {
    static_cast<Engine*>(engine)->release();
    delete static_cast<Engine*>(engine);
}

/**
 * @brief Starts the Video Capture
 * @param engine: Previously created engine by createEngine();
 * @return State of the video capture.
 */
bool startVideoCapture(void * engine) {
    if (engine) {
        Engine * engine = static_cast < Engine * > (engine);
        return engine -> startVideoCapture();
    }
    return false;
}

void stopVideoCapture(void * engine) {
    if (engine) {
        Engine * engine = static_cast < Engine * > (engine);
        engine -> stopVideoCapture();
    }
}

void * getCapturedFrame(void * engine) {
    if (engine) {
        Engine * engine = static_cast < Engine * > (engine);
        cv::Mat * framePtr = new cv::Mat(engine -> getCapturedFrame()); // Copy the frame (?)
        return static_cast < void * > (framePtr);
    }
    return nullptr;
}

void releaseFrame(void * frame) {
    cv::Mat * framePtr = static_cast < cv::Mat * > (frame);
    delete framePtr; // Release the dynamically allocated frame
}

void setTestInt(void* engine, int value) {
    static_cast<Engine*>(engine)->setTestInt(value);
}

int getTestInt(void* engine) {
    return static_cast<Engine*>(engine)->getTestInt();
}

} // extern C

} // namespace VideoCapturer
