project(CompressiveTracking)
cmake_minimum_required(VERSION 2.6)

find_package(OpenCV REQUIRED highgui video videoio imgproc imgcodecs)
include_directories (${OpenCV_INCLUDE_DIRS})

add_library(ct src/CompressiveTracker.cpp)
target_link_libraries(ct ${OpenCV_LIBS})
