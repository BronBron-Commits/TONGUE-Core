file(GLOB TEST_SOURCES *.cpp)

add_executable(CoreTests ${TEST_SOURCES})

target_link_libraries(CoreTests TONGUE-Core gtest gtest_main)

add_test(NAME CoreTests COMMAND CoreTests)
