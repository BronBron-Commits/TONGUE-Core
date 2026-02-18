
# Enable testing
enable_testing()

# Add test executable
add_executable(CoreTests CoreTests.cpp)

# Link GoogleTest and Core library
find_package(GTest CONFIG REQUIRED)
target_link_libraries(CoreTests PRIVATE GTest::gtest GTest::gtest_main TONGUE-Core)

# Register tests
include(GoogleTest)
gtest_discover_tests(CoreTests)
