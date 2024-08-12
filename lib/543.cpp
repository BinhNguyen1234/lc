#include "../include/543.h"
#include <algorithm>
using namespace std;
int Height(TreeNode* root){
  if(root == nullptr){
    return 0;
  }
  return  1 + max(Height(root->left), Height(root->right));
};
int diameter(TreeNode* root, int max){
   if(root == nullptr){
    return max;
  }
  int leftHight = Height(root->left);
  int rightHeight = Height(root->right);
  int sumDiameter = leftHight + rightHeight;
  if(sumDiameter > max){
    max = sumDiameter;
  }
  return std::max(diameter(root->left, max), diameter(root->right, max));
}
int diameterOfBinaryTree(TreeNode *root){
  if(root == nullptr){
    return 0;
  }
  return diameter(root, 0);
}

