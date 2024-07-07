#include "../include/94.h"
#include "../include/TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
// sample [1,null,2,3]
vector<int> inorderTraversal(TreeNode* root){
  
  vector<int> answer;
  stack<TreeNode*> stck;
  stck.push(root);
  TreeNode* top = stck.top();
  while(top != nullptr){

    TreeNode* current = stck.top();
    while(!stck.empty()){
      TreeNode* left = current->left; // this casue inter loop
      while(left != nullptr){
	stck.push(left);
	left = stck.top()->left;
      }
    }
    top = stck.top();
    stck.pop();
    answer.push_back(top->val);
    if(top->right != nullptr){
      stck.push(current->right);
      top = stck.top();
    }
  }
  return answer;
}





