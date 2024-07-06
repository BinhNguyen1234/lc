#include "../include/897.h"
#include "../include/TreeNode.h"
TreeNode* increasingBST(TreeNode* root){
  TreeNode* temp = root;


  while(temp != nullptr){
    if(temp->right == nullptr){
      temp->right == root;
    } 
    temp = temp->right;
  }
  if(root->left != nullptr){
    return increasingBST(root->left);
  }
   
  return root;
}
