
# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Project for tests
project(TONGUE_Core_Tests)

# Enable testing
enable_testing()

# Find Google Test via vcpkg
find_package(GTest CONFIG REQUIRED)

# Include Core headers
include_directories(${CMAKE_SOURCE_DIR}/../include)

# Gather all test sources
set(TEST_SOURCES
	CoreTests.cpp
	StatsTests.cpp
	# Add other test files here as you create them
)

# Create the test executable
add_executable(CoreTests ${TEST_SOURCES})

# Link Core library and GTest
target_link_libraries(CoreTests PRIVATE
	TONGUE-Core           # Your main core library
	GTest::gtest_main
)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(CoreTests)
