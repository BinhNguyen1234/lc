#include "../include/404.h"
#include <queue>
using namespace std;

bool isLeaves(TreeNode* root){
  if(root->left == nullptr && root->right == nullptr) return true; 
  return false;
}
int sumOfLeftLeaves(TreeNode* root){
  int answer = 0;
  if(root->left != nullptr  ){
    if(isLeaves(root->left)){
      answer += root->left->val;
    }else {
      answer += sumOfLeftLeaves(TreeNode *root)mmOfLeftLeaves(root->left);
    }
  }
  if(root->right != nullptr){
    answer +=  sumOfLeftLeaves(root->right);
  }

  return answer;
};





