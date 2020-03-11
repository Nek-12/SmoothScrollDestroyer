cmake_minimum_required(VERSION 3.15)
project(SmoothScrollDestroyer)

set(CMAKE_CXX_STANDARD 20)

set(GCC_COVERAGE_COMPILE_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(SmoothScrollDestroyer main.cpp)