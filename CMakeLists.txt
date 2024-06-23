cmake_minimum_required(VERSION 3.16.3)

project (leetcode)

include_directories(include)
add_subdirectory(googletest)
# generate libary name 1436 (SHARED OR STATIC) with source is at lib/1466.cpp
add_library(1436 SHARED lib/1436.cpp)
add_library(257 SHARED lib/257.cpp)
add_library(266 SHARED lib/266.cpp)
add_library(463 SHARED lib/463.cpp)
add_library(733 SHARED lib/733.cpp)
add_library(653 STATIC lib/653-2.cpp)
add_library(404 STATIC lib/404.cpp)
add_library(637 SHARED lib/637.cpp)
add_library(783 SHARED lib/783.cpp)
# Entry of of is main cpp, and will build a fie name main.exe or main.so
add_executable(main main.cpp)
add_executable(MyTests test.cpp)
# add libary 1436 to main (must have been created by a command such as add_executable() or add_library())
target_link_libraries(main PRIVATE 1436)
# add many libaries add 
target_link_libraries(main PRIVATE 257 266 463 733 404 637)
target_link_libraries(main PRIVATE 653 783)
# Link Google Test to the test executable
target_link_libraries(MyTests gtest gtest_main)

# Enable testing and add tests
enable_testing()
add_test(NAME unittest  COMMAND MyTests)
