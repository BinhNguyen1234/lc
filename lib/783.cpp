#include "../include/733.h"
#include "../include/TreeNode.h"
#include <cmath>
#include <cstddef>
#include <queue>
#include <vector>
#include <math.h>
int findDiff (int value, TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  int diff = abs(value - root->val);
  while(!q.empty()){
    TreeNode* last = q.front();
    q.pop();
    int currentDiff =  abs(last->val  - value);
    if(currentDiff < diff){
      diff = currentDiff;
    };
    if(last->left != nullptr){
      q.push(last->left);
    }
    if(last->right != nullptr){
      q.push(last->right);
    }
  }
  return diff; 
}

int findDiffInList(int value , vector<TreeNode*> rootList) { 
  int min = abs(value - rootList[0]->val);
  for(auto root:rootList ){
    int currentMin = findDiff(value, root);
    if(currentMin < min){
      min = currentMin;
    }
  }
  return min;
}
int minDiffInBST(TreeNode* root ){
  vector<TreeNode*> vt;
  int min = 0;
  if(root->left != nullptr){
    min =  abs(root->val - root->left->val);
  }
  if(root->right != nullptr){
    min = abs(root->val - root->right->val);
  }
  vt.push_back(root);
  while(!vt.empty()){
    int size = vt.size();

    TreeNode* last = vt[size - 1];
    vt.pop_back();
    int currentValue = last->val;
    if(last->left != nullptr){
      vt.push_back(last->left);
    }
    if(last->right !=nullptr){
      vt.push_back(last->right);
    }
    int a = findDiffInList(currentValue, vt);
    if(a < min){
      min = a;
    }
  }
  return min;
};


