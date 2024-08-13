#include "../include/501.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <math.h>
// check root->value = root->left->value || root->right> value
// increase frequently
int getVal(TreeNode* root, vector<int>& answer,int& currentFrequently ,int& maxFrequently){
  if(root == nullptr){
    return NULL;
  }
  int leftValue = getVal(root->left, answer, currentFrequently, maxFrequently);
  int rightValue = getVal(root->right, answer, currentFrequently ,maxFrequently);
  if(leftValue == root->val){
    currentFrequently++;
  }
  if(rightValue == root->val){
    currentFrequently++;
  }
  if(root->val != leftValue && root->val != rightValue){
    currentFrequently = 0;
  }
  if(currentFrequently == maxFrequently){
    answer.push_back(root->val);
  } else if (currentFrequently > maxFrequently){
    maxFrequently = currentFrequently;
    answer.clear();
    answer.push_back(root->val);
  }
  return root->val;
}
vector<int> findMode(TreeNode *root){
  vector<int> answer;
  int currentFrequently = 0;
  int maxFrequently = 0;
  getVal(root, answer, currentFrequently , maxFrequently);  



  return answer;
}
