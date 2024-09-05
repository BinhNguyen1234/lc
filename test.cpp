#include "googletest/googletest/include/gtest/gtest.h" 
#include "./include/Binary.h"
#include <vector>
#include <queue>
#include <list>
#include <optional>
#include "./include/BinaryTree.h"
#include "./include/94.h"
#include "./include/145.h"
#include "./include/144.h"
#include "./include/118.h"
#include "./include/872.h"
#include "./include/563.h"
#include "./include/1025.h"
#include "./include/509.h"
#include "./include/543.h"
#include "./include/501.h"
#include "./include/572.h"
#include "./include/110.h"
#include "./include/1791.h"
#include "./include/671.h"
#include "./include/1971.h"
#include "./include/997.h"
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
  vector<optional<int>> argrument{1};
  vector<int> expect{1,3,2};
  TreeNode* tree = buildBinaryTree(argrument);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);
  EXPECT_EQ(inorderTraversal(tree), expect);
}

TEST(DFS, 145){
  vector<optional<int>> argrument{1};
  vector<int> expect{3,2,1};
  TreeNode* tree = buildBinaryTree(argrument);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);
  EXPECT_EQ(useRecursiveToPostorderTraversal(tree),expect);
  EXPECT_EQ(postorderTraversal(tree), expect);
}

TEST(DFS, 144){
  vector<optional<int>> argrument{1};
  vector<int> expect{1,2,3};
  TreeNode* tree = buildBinaryTree(argrument);
  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);
  EXPECT_EQ(preorderTraversal(tree), expect);
}

TEST(DFS,872){
  vector<optional<int>> initial1{3,5,1,6,2,9,8,nullopt,nullopt,7,4};
  TreeNode* root1 = buildBinaryTree(initial1);
  vector<optional<int>> initial2{3,5,1,6,7,4,2,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,9,8};
  TreeNode* root2 = buildBinaryTree(initial2);
  
  EXPECT_EQ(leafSimilar(root1,root2), true);


  vector<optional<int>> initial3{3,5,1,6,7,4,2,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,9,11,nullopt,nullopt,8,10};
  TreeNode* root3 = buildBinaryTree(initial3);
  vector<optional<int>> initial4{3,5,1,6,2,9,8,nullopt,nullopt,7,4};
  TreeNode* root4 = buildBinaryTree(initial4);
  EXPECT_EQ(leafSimilar(root3,root4), false);
}
TEST(DFS,543){
  
  vector<optional<int>> element1{1,2,3,4,5};
  TreeNode* node1 = buildBinaryTree(element1);
  EXPECT_EQ(diameterOfBinaryTree(node1),3);
  EXPECT_EQ(Solution2::diameterOfBinaryTree(node1),3);

  vector<optional<int>> element2{1,2};
  TreeNode* node2 = buildBinaryTree(element2);
  EXPECT_EQ(diameterOfBinaryTree(node2),1);
  EXPECT_EQ(Solution2::diameterOfBinaryTree(node2),1);

  vector<optional<int>> element3{4,-7,-3,nullopt,nullopt,-9,-3,9,-7,-4,nullopt,6,nullopt,-6,-6,nullopt,nullopt,0,6,5,nullopt,9,nullopt,nullopt,-1,-4,nullopt,nullopt,nullopt,-2};
  TreeNode* node3 = buildBinaryTree(element3);
  EXPECT_EQ(diameterOfBinaryTree(node3),8);
  EXPECT_EQ(Solution2::diameterOfBinaryTree(node3),8);
}
TEST(DFS,563){
  vector<optional<int>> element1{1,2,3};
  TreeNode* node1 = buildBinaryTree(element1);
  EXPECT_EQ(findTilt(node1), 1);

  vector<optional<int>> element2{4,2,9,3,5,nullopt,7};
  TreeNode* node2 = buildBinaryTree(element2);
  EXPECT_EQ(findTilt(node2), 15);

  vector<optional<int>> element3{21,7,14,1,1,2,2,3,3};
  TreeNode* node3 = buildBinaryTree(element3);
  EXPECT_EQ(findTilt(node3), 9);
}
TEST(DFS, 501){
  
  vector<optional<int>> element1{1,nullopt,2,2};
  TreeNode* node1 = buildBinaryTree(element1);
  vector<int> expect1{2};
  EXPECT_EQ(Solution2::findMode(node1), expect1);

  vector<optional<int>> element2{0};
  TreeNode* node2 = buildBinaryTree(element2);
  vector<int> expect2{0};  
  EXPECT_EQ(Solution2::findMode(node2), expect2);
  
  vector<optional<int>> element3{1,0,1,0,0,1,1,0};
  TreeNode* node3 = buildBinaryTree(element3);
  vector<int> expect3{0,1}; 
  EXPECT_EQ(Solution2::findMode(node3), expect3);

  vector<optional<int>> element4{2,1,2};
  TreeNode* node4 = buildBinaryTree(element4);
  vector<int> expect4{2}; 
  EXPECT_EQ(Solution2::findMode(node4), expect4);

  vector<optional<int>> element5{1,nullopt,2};
  TreeNode* node5 = buildBinaryTree(element5);
  vector<int> expect5{1,2}; 
  EXPECT_EQ(Solution2::findMode(node5), expect5);
}
TEST(DFS,110){
  vector<optional<int>> element1{3,9,20,nullopt,nullopt,15,7};
  TreeNode* node1 = buildBinaryTree(element1);
  EXPECT_TRUE(isBalanced(node1));

  vector<optional<int>> element2{1,2,2,3,3,nullopt,nullopt,4,4};
  TreeNode* node2 = buildBinaryTree(element2);
  EXPECT_FALSE(isBalanced(node2));

  vector<optional<int>> element3;
  TreeNode* node3 = buildBinaryTree(element3);
  EXPECT_TRUE(isBalanced(node3));

}

TEST(DFS,572){
  vector<optional<int>> root1{3,4,5,1,2};
  vector<optional<int>> subRoot1{4,1,2};
  TreeNode* node1 = buildBinaryTree(root1);
  TreeNode* subNode1 = buildBinaryTree(subRoot1);
  EXPECT_TRUE(isSubtree(node1, subNode1));


  vector<optional<int>> root2{3,4,5,1,2,nullopt,nullopt,nullopt,nullopt,0};
  vector<optional<int>> subRoot2{4,1,2};
  TreeNode* node2 = buildBinaryTree(root2);
  TreeNode* subNode2 = buildBinaryTree(subRoot2);
  EXPECT_FALSE(isSubtree(node2, subNode2));


  vector<optional<int>> root3{3,4,5,1,2,nullopt,nullopt,nullopt,nullopt,4,nullopt,1,2};
  vector<optional<int>> subRoot3{4,1,2};
  TreeNode* node3 = buildBinaryTree(root3);
  TreeNode* subNode3 = buildBinaryTree(subRoot3);
  EXPECT_TRUE(isSubtree(node3, subNode3));

  vector<optional<int>> root4{3,4,5,1,nullopt,2};
  vector<optional<int>> subRoot4{3,1,2};
  TreeNode* node4 = buildBinaryTree(root4);
  TreeNode* subNode4 = buildBinaryTree(subRoot4);
  EXPECT_FALSE(isSubtree(node4, subNode4));
}

TEST(DFS,671){

  vector<optional<int>> root1{2,2,5,nullopt,nullopt,5,7};
  TreeNode* node1 = buildBinaryTree(root1); 
  EXPECT_EQ(findSecondMinimumValue(node1),5);

  vector<optional<int>> root2{2,2,2};
  TreeNode* node2 = buildBinaryTree(root2);
  EXPECT_EQ(findSecondMinimumValue(node2),-1);

  vector<optional<int>> root3{1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1};
  TreeNode* node3 = buildBinaryTree(root3);
  EXPECT_EQ(findSecondMinimumValue(node3),2);
}

TEST(GRAPH, 1791){
  vector<vector<int>> test1{{1,2},{2,3},{4,2}};
  EXPECT_EQ(findCenter(test1), 2);
}

TEST(GRAPH, 1971){
  vector<vector<int>> test1{{0,1},{0,2},{3,5},{5,4},{4,3}};
  EXPECT_FALSE(validPath(6,test1,0,5));
  EXPECT_FALSE(Solution2::validPath(6,test1,0,5));
  EXPECT_FALSE(Solution3::validPath(6,test1,0,5));
}

TEST(GRAPH, 997){
  vector<vector<int>> input1 {{1,2}};
  EXPECT_EQ(findJudge(2, input1), 2);
  vector<vector<int>> input2 {{1,3},{2,3}};
  EXPECT_EQ(findJudge(3, input2), 3);
  vector<vector<int>> input3 {{1,3},{2,3},{3,1}};
  EXPECT_EQ(findJudge(3, input3), -1);
}
TEST(DP,118){
  vector<vector<int>> expect{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
  EXPECT_EQ(generate(5), expect);
}
TEST(DP,509){
  EXPECT_EQ(fib(2),1);
  EXPECT_EQ(fib(3),2);
  EXPECT_EQ(fib(4),3);
}
TEST(DP,1025){
 EXPECT_EQ(divisorGame(3),false);
 EXPECT_EQ(divisorGame(2),true);
}
// Entry point for the test executable
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
