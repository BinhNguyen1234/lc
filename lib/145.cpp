#include "../include/145.h"
#include <stack>

using namespace std;

vector<int> postorderTraversal(TreeNode *root){
  vector<int> answer;
  if(root == nullptr){
    return answer;
  }

  stack<TreeNode*> s;

  s.push(root);
  TreeNode* current = s.top();


  while(!s.empty()){
    while(current->right != nullptr){
      s.push(current->right);
      current = current->right;
    }
    
    while(!s.empty()){
      TreeNode* top = s.top();
      if(top->left != nullptr){
	s.push(top->left);
	current = top->left;
	break;
      }
      s.pop();
      answer.push_back(top->val);
    }
  }
  return answer;
}
