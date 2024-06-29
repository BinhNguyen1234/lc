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
  
  return total + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low,high);
}





