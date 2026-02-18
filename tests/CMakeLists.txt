
# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Enable testing
enable_testing()

# Project for tests
project(TONGUE_Core_Tests)

# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Project for tests
project(TONGUE_Core_Tests)

# Enable testing
enable_testing()


# Include Core headers
include_directories(${CMAKE_SOURCE_DIR}/../include)

# Gather all test sources
set(TEST_SOURCES
	CoreTests.cpp
	StatsTests.cpp
)

# Main core test executable
add_executable(CoreTests ${TEST_SOURCES})
target_link_libraries(CoreTests PUBLIC gtest_main TONGUE-Core)
add_test(NAME CoreTests COMMAND CoreTests)

# Advanced scenario tests
add_executable(AdvancedScenarioTests AdvancedScenarioTests.cpp)
target_link_libraries(AdvancedScenarioTests PUBLIC gtest_main TONGUE-Core)
add_test(NAME AdvancedScenarioTests COMMAND AdvancedScenarioTests)

# Scenario tests
add_executable(ScenarioTests ScenarioTests.cpp)
target_link_libraries(ScenarioTests PUBLIC gtest_main TONGUE-Core)
add_test(NAME ScenarioTests COMMAND ScenarioTests)
# Buff system tests
add_executable(BuffSystemTests BuffSystemTests.cpp)
target_link_libraries(BuffSystemTests PUBLIC gtest_main TONGUE-Core)
add_test(NAME BuffSystemTests COMMAND BuffSystemTests)
