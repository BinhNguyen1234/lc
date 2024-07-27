#include "../include/144.h"
#include <stack>
using namespace std;
//root->left->right 
vector<int> preorderTraversal(TreeNode *root){  
  vector<int> answer;
  stack<TreeNode*> s;
  if(root == nullptr){
    return answer;
  }
 
  TreeNode* current = root;
  while(!s.empty() || current != nullptr){
    while(current != nullptr){
      s.push(current);
      answer.push_back(current->val);
      current = current->left;
    }
    while(!s.empty()){
      TreeNode* top = s.top();
      s.pop();
      if(top->right){
	current = top->right;
	break;
      }
    }
  }


  return answer;
}

