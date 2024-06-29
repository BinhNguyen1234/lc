#include "../include/993.h"
#include "../include/TreeNode.h"


int rangeSumBST(TreeNode *root, int low, int high){
  int total = 0;
  if(root == nullptr){
    return total;
  }
  if(root->val <= high && root->val >= low){
    total += root->val;
  }
  if(root->val > high){
    total+= rangeSumBST(root->left, low, high);
  } 
  if(root->val < low){
    total += rangeSumBST(root->right, low, high);
  }
  return total;
}





