cmake_minimum_required(VERSION 3.10)
project(TONGUE-Core)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


# Core headers and sources
file(GLOB CORE_HEADERS include/Core/*.h)
file(GLOB CORE_SOURCES src/*.cpp)


add_library(TONGUE-Core ${CORE_HEADERS} ${CORE_SOURCES})


# Optionally fetch GoogleTest if not using vcpkg
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable and add tests
enable_testing()
add_subdirectory(tests)
