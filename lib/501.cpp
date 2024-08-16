#include "../include/501.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <math.h>
#include <stack>
// check root->value = root->left->value || root->right> value
// increase frequently
int inorder(TreeNode* root, vector<int>& answer,int& currentFrequently ,int& maxFrequently){
  

  if(root == nullptr){
    return -1;
  }
  
  int leftVal = inorder(root->left, answer, currentFrequently, maxFrequently);
  if(leftVal == root->val){
    currentFrequently++;
  }


  if(currentFrequently == maxFrequently){
    answer.push_back(root->val);
  } else if ( currentFrequently > maxFrequently){
    maxFrequently = currentFrequently;
    answer = {root->val};
  }
  int rightVal = inorder(root->right, answer, currentFrequently, maxFrequently);
  if(rightVal == root->val){
    currentFrequently++;
  }

  if(leftVal != root->val && rightVal != root->val){
    currentFrequently = 0;
  }
  return root->val;
}

vector<int> findMode(TreeNode *root){
  vector<int> answer;
  stack<TreeNode*> s;
  TreeNode* current = root;
  int currentFrequently = 0;
  int maxFrequentlyCurrent = 0;
  inorder(root ,answer, currentFrequently, maxFrequentlyCurrent);
  return answer;
}
namespace Solution2 {
vector<int> findMode(TreeNode *root){
  vector<int> answer;
  stack<TreeNode*> s;
  TreeNode* current = root;
  int currentFrequently = 0;
  int maxFrequentlyCurrent = 0;
  while(!s.empty() || root != nullptr){
    while(root != nullptr){
      s.push(root);
      root = root->left;
    }

    while(!s.empty()){
      TreeNode* top = s.top();
      s.pop();

      if(top->right != nullptr){
	root = top->right;
	break;
      }
      if(currentFrequently == maxFrequentlyCurrent){
	  answer.push_back(top->val);
      } else if ( currentFrequently >  maxFrequentlyCurrent){
	  answer = {top->val};
	  maxFrequentlyCurrent = currentFrequently;
      }

      if(!s.empty()){
	TreeNode* pre = s.top();
	if(top->val == pre->val){
	  currentFrequently++;
	} else {
	  currentFrequently = 1;
	}

      }
    }

  }
  return answer;
}
}
