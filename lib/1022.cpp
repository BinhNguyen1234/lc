#include "../include/1022.h"
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int sumRootToLeaf(TreeNode *root){
  int answer = 0;
  if(root == nullptr){
    return answer;
  }
  int valueAtPath = 0;
  stack<TreeNode*> s;
  s.push(root);
  TreeNode* visitor = root;

  while(!s.empty()){

    TreeNode* current = s.top();

    TreeNode* left = visitor->left;
    // go to dept left
    while(left!=nullptr){
      s.push(left);
      //write history path build path
      valueAtPath = valueAtPath * 2 + left->val;
      left = current->left;
    }

    while(!s.empty()){
      TreeNode* leftDeptFirst = s.top();
      TreeNode* right = leftDeptFirst->right;

      s.pop();
      valueAtPath = (valueAtPath - leftDeptFirst->val)/2;
      if(right != nullptr){
	s.push(right);
	visitor = s.top();
	valueAtPath = (valueAtPath * 2) + right->val;	
	break;
      }else {
	  answer += valueAtPath;
      }   
    }
  }
  return answer;
}
