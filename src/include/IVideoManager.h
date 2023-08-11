// YourLibrary.h
#ifdef _WIN32
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API
#endif

#include <opencv2/opencv.hpp>

/**
 * Video Manager SDK Interface.
 */
extern "C" {
/**
 * @brief Creates an Engine
 * @return void pointer to the singleton Engine
 */
LIBRARY_API void* createEngine();


LIBRARY_API bool startVideoCapture(void* engine);

/**
 * @brief Stops the video capturing.
 * @param engine: Previously created engine by createEngine();
 */
LIBRARY_API void stopVideoCapture(void* engine);

/**
 * @brief Gets typecasted void pointer the current captures frame (Typecasted from cv::Mat)
 * @param engine:  Previously created engine by createEngine();
 * @returns typecasted void pointer the current captures frame (Typecasted from cv::Mat)
 */
LIBRARY_API void* getCapturedFrame(void* engine);

/**
 * @brief Releases the memory of given frame.
 * @param frame: Frame to be released
 */
LIBRARY_API void releaseFrame(void* frame);

// Debug Functions, will delete later.
LIBRARY_API void setTestInt(void* engine, int value);
LIBRARY_API int getTestInt(void* engine);
}
