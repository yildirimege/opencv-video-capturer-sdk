// Engine.h
#ifndef ENGINE_H
#define ENGINE_H

#include <opencv2/opencv.hpp>
#include <mutex>  // For thread safety

namespace VideoCapturer
{
class Engine {
public:
    static Engine* instance(); // Gets the singleton instance of Engine object. If doesn't exist, creates it.


    /**
    * @brief Starts the Video Capture
    * @param engine: Previously created engine by createEngine();
    * @return State of the video capture.
    */
    bool startVideoCapture();

    /**
     * @brief Stops video capturing.
     */
    void stopVideoCapture();

    /**
     * @brief Returns the current captured frame.
     * @return Currently captured cv::Mat obj.
     */
    cv::Mat getCapturedFrame();

    /**
     * @brief Deleted Copy Constructor
     */
    Engine(const Engine&) = delete;

    /**
     * @brief Deleted operator =
     */
    Engine& operator=(const Engine&) = delete;

    /**
     * @brief Deallocates the Engine obj.
     */
    void release();

    // functions for testing
    void setTestInt(int value);
    int getTestInt() const;



private:
    static Engine* m_instance;

    Engine();
    cv::VideoCapture capture;
    bool isVideoCapturing;
    std::mutex captureMutex;
    int m_testInt;


};

#endif // ENGINE_H
}
