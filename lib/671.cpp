#include "../include/671.h"
#include <algorithm>
#include <iostream>
using namespace std;
int findSecondMinimumValue(TreeNode *root){
  if(root->left == nullptr){
    return -1;
  }
  int biggerChild = max(root->left->val, root->right->val);
  if(root->left->val == root->right->val){
    int temp = min(findSecondMinimumValue(root->left),findSecondMinimumValue(root->right));
return temp;
  }else if (root->left->val < root->right->val){
    int temp = findSecondMinimumValue(root->left);
    return temp == -1 ? biggerChild : min(biggerChild, temp);
  }else  {
    int temp = findSecondMinimumValue(root->right);
    return temp == -1 ? biggerChild : min(biggerChild, temp);
  }

}
int draft(TreeNode*  root){
  if(root->left == nullptr){
    return -1;
  }
  return max(root->left->val, root->right->val);
}

