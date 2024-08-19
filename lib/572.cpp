#include "../include/572.h"
#include <iostream>
using namespace std;


bool isSubTree(TreeNode* root, TreeNode* subRoot){
  if(root == nullptr && subRoot == nullptr){
    return true;
  }
  return root != nullptr && subRoot != nullptr && root->val == subRoot->val && isSubTree(root->left, subRoot->left) && isSubTree(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot){
  if(root == nullptr){
    return false;
  }
  bool result = isSubTree(root, subRoot);
  return result || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

