#include "../include/993.h"
#include "../include/TreeNode.h"


int rangeSumBST(TreeNode *root, int low, int high){
  if( root->val > high || root->val < low){
    return 0;
  }
  return root-> val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}





