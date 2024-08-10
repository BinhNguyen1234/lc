#include "../include/563.h"
#include "../include/TreeNode.h"
#include <math.h>
  int findTotalValue(TreeNode* root){
    if(root == nullptr){
      return 0;
    }
    return root->val + findTotalValue(root->left) + findTotalValue(root->right);
  }

  int findTilt(TreeNode *root){
    if(root == nullptr){
      return 0;
    }
    int answer = 0;
    TreeNode* temp;
    int leftValue = findTotalValue(root->left);
    int rightValue = findTotalValue(root->right);
    return abs(leftValue - rightValue) + findTilt(root->left) + findTilt(root->right);
  }

