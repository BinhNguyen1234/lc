#include "../include/501.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <math.h>
// check root->value = root->left->value || root->right> value
// increase frequently
int inorder(TreeNode* root, vector<int>& answer,int& currentFrequently ,int& maxFrequently){
  

  if(root == nullptr){
    return -1;
  }
  
  int leftVal = inorder(root->left, answer, currentFrequently, maxFrequently);
  int rightVal = inorder(root->right, answer, currentFrequently, maxFrequently);

  if(leftVal != root->val && rightVal != root->val){
    currentFrequently = 0;
  }
  if(rightVal == root->val){
    currentFrequently++;
  }
  if(leftVal == root->val){
    currentFrequently++;
  }
  if(currentFrequently == maxFrequently){
    answer.push_back(root->val);
  } else if ( currentFrequently > maxFrequently){
    maxFrequently = currentFrequently;
  }
  return root->val;
}
vector<int> findMode(TreeNode *root){
  vector<int> answer;
  int currentFrequently = 0;
  int maxFrequently = 0;
  inorder(root, answer, currentFrequently , maxFrequently);  



  return answer;
}
