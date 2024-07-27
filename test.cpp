#include "googletest/googletest/include/gtest/gtest.h" 
#include "./include/Binary.h"
#include <vector>
#include <queue>
#include <list>
#include "./include/BinaryTree.h"
#include "./include/94.h"
#include "./include/145.h"
#include "./include/144.h"
#include "./include/872.h"
using namespace std;
// Sample function to test
//int add(int a, int b) {
  //  return a + b;
//}

// Test case for the add function
//TEST(AdditionTest, HandlesPositiveInput) {
//    EXPECT_EQ(add(1, 2), 3);
//    EXPECT_EQ(add(10, 20), 30);
//}

//TEST(AdditionTest, HandlesNegativeInput) {
    //EXPECT_EQ(add(-1, -2), -3);
  //  EXPECT_EQ(add(-10, -20), -30);
//}

TEST(BinaryTest, convertToBi){
    vector<int> expectResult{1,0,0};
    EXPECT_EQ(convertToBinary(4), expectResult);
    vector<int> expectResult2{0};
    EXPECT_EQ(convertToBinary(0), expectResult2);
    vector<int> expectResult3{1,1,0,0,1,0};
    EXPECT_EQ(convertToBinary(50), expectResult3);
}
TEST(BinaryTest, convertToDec){
    vector<int> argument{1,0,0};
    EXPECT_EQ(convertToDecimal(argument),4);
    vector<int> argument2{0};
    EXPECT_EQ(convertToDecimal(argument2), 0);
    vector<int> argurment3{1,1,0,0,1,0};
    EXPECT_EQ(convertToDecimal(argurment3),50);
}
TEST(BinaryTest, convertToDecByBacktracking){
    queue<int> argument;
    argument.push(1);
    argument.push(0);
    argument.push(0);
    EXPECT_EQ(convertToDecimal(argument, 0),4);
    queue<int> argument2;
    argument.push(0);
    EXPECT_EQ(convertToDecimal(argument2, 0), 0);
    queue<int> argurment3;
    argurment3.push(1);
    argurment3.push(1);
    argurment3.push(0);
    argurment3.push(0);
    argurment3.push(1);
    argurment3.push(0);
    EXPECT_EQ(convertToDecimal(argurment3, 0),50);
}
TEST(DFS, 94){
  vector<int> argrument{1};
  vector<int> expect{1,3,2};
  TreeNode* tree = buildBinaryTree(argrument);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);
  EXPECT_EQ(inorderTraversal(tree), expect);
}

TEST(DFS, 145){
  vector<int> argrument{1};
  vector<int> expect{3,2,1};
  TreeNode* tree = buildBinaryTree(argrument);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);
  EXPECT_EQ(useRecursiveToPostorderTraversal(tree),expect);
  EXPECT_EQ(postorderTraversal(tree), expect);
}

TEST(DFS, 144){
  vector<int> argrument{1};
  vector<int> expect{1,2,3};
  TreeNode* tree = buildBinaryTree(argrument);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);
  EXPECT_EQ(preorderTraversal(tree), expect);
}
TEST(DFS,872){
  vector<int> initial1{3,5,1,6,2,9,8,nullptr,nullptr,7,4};
  TreeNode* root1 = buildBinaryTree(initial);
  
  TreeNode* root2 = buildBinaryTree(initial);

  EXPECT_EQ(leafSimilar(root1,root2), true);
}

// Entry point for the test executable
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
