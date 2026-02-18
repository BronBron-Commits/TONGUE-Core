cmake_minimum_required(VERSION 3.10)
project(TONGUE-Core)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB CORE_HEADERS include/Core/*.h)
file(GLOB CORE_SOURCES src/*.cpp)

add_library(TONGUE-Core ${CORE_HEADERS} ${CORE_SOURCES})

enable_testing()
add_subdirectory(tests)
