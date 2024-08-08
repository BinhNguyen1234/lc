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
add_library(872 SHARED lib/872.cpp)
add_library(509 STATIC lib/509.cpp)
add_library(118 SHARED lib/118.cpp)
add_library(1025 SHARED lib/1025.cpp)
# Entry of of is main cpp, and will build a fie name main.exe or main.so
add_executable(main main.cpp)
add_executable(unittest test.cpp)
# add libary 1436 to main (must have been created by a command such as add_executable() or add_library())
target_link_libraries(main PRIVATE 1436 Binary)
# config cpp17 for some entry point
target_compile_features(main PRIVATE cxx_std_17)
target_compile_features(BinaryTree PRIVATE cxx_std_17)
target_compile_features(unittest PRIVATE cxx_std_17)
# set_property(TARGET main PROPERTY CXX_STANDARD 17)
# set_property(TARGET CommonTest PROPERTY CXX_STANDARD 17)
# set_property(TARGET unittest PROPERTY CXX_STANDARD 17)

# add many libaries add 
target_link_libraries(main PRIVATE 257 266 463 733 404 637)
target_link_libraries(main PRIVATE 653 783 BinaryTree 530)
# Link Google Test to the test executable
target_link_libraries(unittest 1025 509 118 144 145 94 872 Binary BinaryTree gtest gtest_main)
# Enable testing and add tests
enable_testing()
add_test(NAME unittest  COMMAND test)
