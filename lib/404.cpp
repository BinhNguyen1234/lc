#include "../include/404.h"
#include <queue>
using namespace std;

bool isLeaves(TreeNode* root){
  if(root->left == nullptr && root->right == nullptr) return true; 
  return false;
}
int SumOfLeftLeaves(TreeNode* root){
  int answer = 0;
  if(root->left != nullptr  ){
    if(isLeaves(root->left)){
      answer += root->left->val;
    }else {
      answer += SumOfLeftLeaves(root->left);
    }
  }
  if(root->right != nullptr){
    answer +=  SumOfLeftLeaves(root->right);
  }

  return answer;
};





