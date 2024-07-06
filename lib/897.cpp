#include "../include/897.h"
#include "../include/TreeNode.h"
TreeNode* increasingBST(TreeNode* root){

  TreeNode* left = root->left;
  if(root->right != nullptr){
    root->right = increasingBST(root->right);
  }

  if(left == nullptr){
    return root;
  }else {
    TreeNode* temp = root->left;
    while(temp != nullptr){
      if(temp->right == nullptr){
	temp->right = root;
	root->left = nullptr;
	break;
      }    
  
      temp = temp->right;
    }
  }
  return increasingBST(left);
}
