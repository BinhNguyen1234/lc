#include "../include/671.h"
#include <algorithm>
#include <iostream>
using namespace std;
int findSecondMinimumValue(TreeNode *root){
  if(root->left == nullptr){
    return -1;
  }
  int currentSecondMinium = max(root->left->val, root->right->val);
  if(root->left->val == root->right->val){

    int left = findSecondMinimumValue(root->left);
    int right = findSecondMinimumValue(root->right);
    return (left == -1 ^ right == -1) ? max(left,right): min(left,right);
  }else if (root->left->val == root->val){
    int left = findSecondMinimumValue(root->left);
    return left == -1 ? currentSecondMinium : min(left, currentSecondMinium);
  }else  {
    int right = findSecondMinimumValue(root->right);
    return right == -1 ? currentSecondMinium : min(right, currentSecondMinium);
  }

}

