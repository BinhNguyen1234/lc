#include "../include/145.h"
#include <stack>

using namespace std;

vector<int> postorderTraversal(TreeNode *root){
  vector<int> answer;
  if(root == nullptr){
    return answer;
  }

  stack<TreeNode*> s;
  TreeNode* current = root;

  while(!s.empty() || current != nullptr){
    while(current != nullptr){
      s.push(current);
      if(current->right != nullptr){
	s.push(current->right);
      }
      current = current->left;
    }
    
    while(!s.empty()){
      TreeNode* top = s.top();
      answer.push_back(top->val);
      s.pop();
      if(top->right != nullptr){
	current = top->right;
	s.pop();
	break;
      }
    }
  }
  return answer;
}
