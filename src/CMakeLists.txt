# -------------------------------------------------------------------------------------------------
# Library settings
# -------------------------------------------------------------------------------------------------
set(${PROJECT_NAME}_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/engine.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/IVideoManager.cpp"

)

set(${PROJECT_NAME}_HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/include/engine.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/IVideoManager.h"
)

#add_library(${PROJECT_NAME} SHARED
set(LIBRARY_BUILD_TYPE SHARED)

add_library(${PROJECT_NAME} ${LIBRARY_BUILD_TYPE}
    ${${PROJECT_NAME}_SOURCES}
    ${${PROJECT_NAME}_HEADERS}
)

# Set the library version
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Set the output directory for artifacts
set(ARTIFACTS_OUT_DIR "${CMAKE_BINARY_DIR}/artifactsOut")

# Export the library to the "artifactsOut" directory
if(WIN32)
    set(LIBRARY_OUTPUT_DIRECTORY "${ARTIFACTS_OUT_DIR}")
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${ARTIFACTS_OUT_DIR}"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${ARTIFACTS_OUT_DIR}"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${ARTIFACTS_OUT_DIR}"
    )
endif()

# macOS-specific settings
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".dylib"
    )
endif()

# Windows-specific settings
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        PREFIX ""
    )
endif()


# include will include the public API of our component and is PUBLIC
# all additional include paths should be marked as private
target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# -------------------------------------------------------------------------------------------------
# Library Installation
# -------------------------------------------------------------------------------------------------
#include(ProjectInstallation) Add if necessary.

#install(${PROJECT_NAME}) TODO: Enable

install(
    DIRECTORY "./CMake"
    DESTINATION "${ARTIFACTS_OUT_DIR}/.."
)

# CMake-generated
install(
    DIRECTORY "${PROJECT_BINARY_DIR}/src/include/"
    DESTINATION "${ARTIFACTS_OUT_DIR}/include"
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

# -------------------------------------------------------------------------------------------------
# Find packages
# -------------------------------------------------------------------------------------------------
find_package(OpenCV REQUIRED)

# -------------------------------------------------------------------------------------------------
# Include directories
# -------------------------------------------------------------------------------------------------
target_include_directories(${PROJECT_NAME} SYSTEM
    PUBLIC ${OPENCV_INCLUDE_DIRS}
)

# -------------------------------------------------------------------------------------------------
# Library dependencies
# -------------------------------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC
    ${OpenCV_LIBS}
)

# -------------------------------------------------------------------------------------------------
# Linker flags for library size decrease
# -------------------------------------------------------------------------------------------------
#set (CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} -Wl,--version-script=$#{CMAKE_SOURCE_DIR}/src/export.map -Wl,-s -O3 -Wl,--gc-sections")
#set (CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -Wl,--version-script=$#{CMAKE_SOURCE_DIR}/src/export.map -Wl,-s -Wl,--gc-sections")


message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
message(STATUS "OpenCV Directories: ${OpenCV_INCLUDE_DIRS}")



# -------------------------------------------------------------------------------------------------
# Set Alias of Library to reach from parent executable
# -------------------------------------------------------------------------------------------------
add_library(sub::VideoCapturer ALIAS ${PROJECT_NAME})
