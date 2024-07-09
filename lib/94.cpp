#include "../include/94.h"
#include "../include/TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
// sample [1,null,2,3]
vector<int> inorderTraversal(TreeNode* root){
  
  vector<int> answer;
  if(root == nullptr){
    return answer;
  }

  stack<TreeNode*> stck;
  stck.push(root);
  TreeNode* top = stck.top();
  while(!stck.empty()){

    TreeNode* left = top->left;

    // put first-dept left to stack
    while(left != nullptr){
      stck.push(left);
      left = left->left;
    }

    while(!stck.empty()){

      top = stck.top(); //get first-dept left

      answer.push_back(top->val);
      stck.pop();// remove first-dept left from stack 
      if(top->right != nullptr){
	stck.push(top->right);	
	top = stck.top();
	break;
      }
    } 
  }
  return answer;
}





