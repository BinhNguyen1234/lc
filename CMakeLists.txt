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
add_library(530 STATIC lib/530.cpp)
add_library(637 SHARED lib/637.cpp)
add_library(783 SHARED lib/783.cpp)
add_library(Binary SHARED lib/Binary.cpp)
add_library(BinaryTree SHARED lib/BinaryTree.cpp)
add_library(145 SHARED lib/145.cpp)
add_library(94 SHARED lib/94.cpp)
add_library(144 SHARED lib/144.cpp)
# Entry of of is main cpp, and will build a fie name main.exe or main.so
add_executable(main main.cpp)
add_executable(CommonTest CommonTest.cpp)
add_executable(unittest test.cpp)
# add libary 1436 to main (must have been created by a command such as add_executable() or add_library())
target_link_libraries(main PRIVATE 1436 Binary)
# add many libaries add 
target_link_libraries(main PRIVATE 257 266 463 733 404 637)
target_link_libraries(main PRIVATE 653 783 BinaryTree 530)
# Link Google Test to the test executable
target_link_libraries(unittest 144 145 gtest gtest_main Binary BinaryTree 94)
target_link_libraries(CommonTest gtest gtest_main)
# Enable testing and add tests
enable_testing()
add_test(NAME unittest  COMMAND utest)
