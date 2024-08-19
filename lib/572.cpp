#include "../include/572.h"
#include <iostream>
using namespace std;
bool isSubTree(TreeNode* root, TreeNode* subRoot, bool isCountinous){
  if(root == nullptr && subRoot == nullptr){
    cout << "n-n" << isCountinous << endl;
    return isCountinous;
  } else if (root == nullptr ^ subRoot == nullptr){
    cout << 0 << endl;
    return false;
  }
  
  bool isEqual = root->val == subRoot->val;
  cout << root->val << " " << subRoot->val << " " << endl;
  if(isEqual)  isSubTree(root->left, subRoot->left, true) && isSubTree(root->right,  subRoot->right, true);
  return isSubTree(root->left, subRoot, false) || isSubTree(root->right, subRoot, false);
}

bool isSame(TreeNode* root, TreeNode* subRoot){
  if(root == nullptr && subRoot == nullptr){
    return true;
  }
  return root != nullptr && subRoot != nullptr && root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot){
  if(subRoot == nullptr){
    return true;
  } 
  if(root == nullptr){
    return false;
  }
  if(isSame(root,subRoot)) return true;
  return isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
}

