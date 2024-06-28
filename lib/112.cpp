#include "../include/112.h"

bool hasPathSum(TreeNode* root, int targetSum){
  if(root == nullptr){
    return false;
  }
  int remain = targetSum - root->val;
  if(remain == 0){
    return true;
  }

  return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
}
