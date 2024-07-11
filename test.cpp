#include "googletest/googletest/include/gtest/gtest.h" 
#include "./include/Binary.h"
#include <vector>

using namespace std;
// Sample function to test
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST(AdditionTest, HandlesPositiveInput) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(10, 20), 30);
}

TEST(AdditionTest, HandlesNegativeInput) {
    EXPECT_EQ(add(-1, -2), -3);
    EXPECT_EQ(add(-10, -20), -30);
}

TEST(AddtionTest, HandlesNegativeInput){
    vector<int> expectResult{1,1,0};
    EXPECT_EQ(convertToBinary(4), expectResult);
  
}

// Entry point for the test executable
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
