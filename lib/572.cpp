#include "../include/572.h"
#include <iostream>
using namespace std;


bool isTheSame(TreeNode* root, TreeNode* subRoot){
  if(root == nullptr && subRoot == nullptr){
    return true;
  }
  return root != nullptr && subRoot != nullptr && root->val == subRoot->val && isTheSame(root->left, subRoot->left) && isTheSame(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot){
  if(root == nullptr){
    return false;
  }
  bool result = isTheSame(root, subRoot);
  return result || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

