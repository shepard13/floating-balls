cmake_minimum_required(VERSION 2.8)
project(floating_balls)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(floating_balls ${SOURCE_FILES} Ball.cpp Ball.h Scene.cpp Scene.h)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

target_link_libraries(floating_balls ${OPENGL_LIBRARIES})
target_link_libraries(floating_balls ${GLUT_LIBRARY})
