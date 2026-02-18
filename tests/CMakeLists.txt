
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
)

# Main core test executable
add_executable(CoreTests ${TEST_SOURCES})
target_link_libraries(CoreTests PRIVATE TONGUE-Core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(CoreTests)

# Advanced scenario tests
add_executable(AdvancedScenarioTests AdvancedScenarioTests.cpp)
target_link_libraries(AdvancedScenarioTests PRIVATE TONGUE-Core GTest::gtest_main)
add_test(NAME AdvancedScenarioTests COMMAND AdvancedScenarioTests)

# Scenario tests
add_executable(ScenarioTests ScenarioTests.cpp)
target_link_libraries(ScenarioTests PRIVATE TONGUE-Core GTest::gtest_main)
add_test(NAME ScenarioTests COMMAND ScenarioTests)
