cmake_minimum_required(VERSION 3.14.1)
message(STATUS "Using CMake v${CMAKE_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PRODUCT_BUNDLE_IDENTIFIER "yildirimege")


# -------------------------------------------------------------------------------------------------
# add cmake module paths
# -------------------------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")


# -------------------------------------------------------------------------------------------------
# Generic CMake Settings
# -------------------------------------------------------------------------------------------------
#include(ProjectSettings)
#include(ProjectEnvironment)


# -------------------------------------------------------------------------------------------------
# Project settings
# -------------------------------------------------------------------------------------------------
project(VideoManager
    VERSION 1.0.0
    LANGUAGES CXX
    )


# -------------------------------------------------------------------------------------------------
# Platform Settings
# -------------------------------------------------------------------------------------------------
#include(CompilerSettings) TODO: Include later.
#include(PlatformSettings)

# -------------------------------------------------------------------------------------------------
# Project Definition (src)
# -------------------------------------------------------------------------------------------------
add_subdirectory(src)


# -------------------------------------------------------------------------------------------------
# Enable Test App. TODO: Uncomment this and get this as a CMake option.
# -------------------------------------------------------------------------------------------------
#if(VIDEO_MANAGER_TEST_APP)
# add_subdirectory(app)
#endif(VIDEO_MANAGER_TEST_APP)
