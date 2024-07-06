#include "../include/897.h"
#include "../include/TreeNode.h"
TreeNode* increasingBST(TreeNode* root){
  TreeNode* temp = root;

  while(temp != nullptr){
    if(temp->right == nullptr){
      temp->right = root;
    }
    else
    {
    temp = temp->right;
    } 
  }
  if(root->left ==  nullptr){
    return root;
  }
   
  return increasingBST(root->left);
}
