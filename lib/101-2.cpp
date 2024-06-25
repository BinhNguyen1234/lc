#include "../include/101-2.h"
#include "../include/TreeNode.h"

bool isEqual(TreeNode* left, TreeNode* right){
  if((left == nullptr) ^ (right == nullptr)) return false;
  if(left == nullptr && right == nullptr) return true;
  return left->val == right->val && isEqual(left->left, right->right) && isEqual(left->right, right->left);
}
bool isSymmetric(TreeNode* root){
  return isEqual(root, root);
}

