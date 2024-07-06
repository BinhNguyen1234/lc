#include "../include/897.h"
#include "../include/TreeNode.h"
TreeNode* increasingBST(TreeNode* root){

  TreeNode* left = root->left;
  if(root->right != nullptr){
    root->right = increasingBST(root->right);
  }
  while(left != nullptr){
    
    if(left->right == nullptr){
      left->right = root;
      left = nullptr;
    }else {
      left = left->right;
    }
  }
  if(root->left == nullptr){
    return root;
  }
  return increasingBST(root->left);
}
