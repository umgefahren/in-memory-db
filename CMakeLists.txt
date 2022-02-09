cmake_minimum_required(VERSION 3.21)
project(in_memory_db)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCEA)
FetchContent_MakeAvailable(googletest)

add_executable(in_memory_db main.cpp objects.cpp objects.h)

add_library(objects objects.h objects.cpp)

enable_testing()

add_executable(
        all_test
        all_test.cpp
        hello_test.cpp
        objects_test.cpp
)

target_link_libraries(
        all_test
        gtest_main
        objects
)

include(GoogleTest)
# gtest_discover_tests(hello_test)
# gtest_discover_tests(objects_test)
gtest_discover_tests(all_test)