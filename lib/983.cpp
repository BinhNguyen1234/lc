#include "../include/993.h"
#include "../include/TreeNode.h"


int rangeSumBTS(TreeNode *root, int low, int high){
  if( root->val > high || root->val < low){
    return 0;
  }
  return root-> val + rangeSumBTS(root->left, low, high) + rangeSumBTS(root->right, low, high);
}





