#include "../include/897.h"
#include "../include/TreeNode.h"
TreeNode* increasingBST(TreeNode* root){
  if(root->right != nullptr){
    root->right = increasingBST(root->right);
  }
  if(root->left == nullptr){
    return root;
  } 
  TreeNode* left = root->left;
  left->right = root;
  root->left = nullptr;
  return increasingBST(temp);
}


