#include "../include/543.h"
#include <algorithm>
using namespace std;
int Height(TreeNode* root){
  if(root == nullptr){
    return 0;
  }
  return  1 + max(Height(root->left), Height(root->right));
};
int diameterOfBinaryTree(TreeNode *root){
  if(root == nullptr){
    return 0;
  }
  int leftHight = Height(root->left);
  int rightHeight = Height(root->right);
  return leftHight + rightHeight;
}

