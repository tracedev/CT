project(CompressiveTracking)

cmake_minimum_required(VERSION 2.6)

find_package(OpenCV REQUIRED highgui video videoio imgproc imgcodecs)

set(CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES (${OpenCV_INCLUDE_DIRS})

add_library(ct CompressiveTracker.cpp)
add_executable(CT RunTracker.cpp)

target_link_libraries(ct ${OpenCV_LIBS})
target_link_libraries(CT ct)
