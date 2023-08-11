// Engine.cpp

#include "engine.h"

namespace VideoCapturer
{

    Engine* Engine::m_instance = nullptr;

    Engine* Engine::instance()
    {
    if (m_instance == nullptr)
        {
            m_instance = new Engine;
        }
    return m_instance;
    }

    Engine::Engine() : isVideoCapturing(false)
    {

    }

    void Engine::release()
    {
        // release resources in the future.
    }

    bool Engine::startVideoCapture() {
        std::lock_guard<std::mutex> lock(captureMutex);

        if (!isVideoCapturing) {
            capture.open(0);  // Open default camera (change if needed)
            if (capture.isOpened()) {
                isVideoCapturing = true;
                return true;
            }
        }

        return false;
    }

    void Engine::stopVideoCapture() {
        std::lock_guard<std::mutex> lock(captureMutex);

        if (isVideoCapturing) {
            capture.release();
            isVideoCapturing = false;
        }
    }

    cv::Mat Engine::getCapturedFrame() {
        cv::Mat frame;
        std::lock_guard<std::mutex> lock(captureMutex);

        if (isVideoCapturing) {
            capture >> frame;
        }

        return frame;
    }

    int Engine::getTestInt() const
    {
        return m_testInt;
    }

    void Engine::setTestInt(const int newValue)
    {
        this->m_testInt = newValue;

    }
}
