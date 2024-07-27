#include "../include/94.h"
#include "../include/TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
// sample [1,null,2,3]
// left -> root -> right
vector<int> inorderTraversal(TreeNode* root){
  
  vector<int> answer;
  if(root == nullptr){
    return answer;
  }

  stack<TreeNode*> s;  
  TreeNode* current = root;
  while(!s.empty() || current != nullptr){
    while(current != nullptr){
      s.push(current);
      current = current->left;
    }
    while(!s.empty()){
      TreeNode* top = s.top();
      s.pop();
      answer.push_back(top->val);
      if(top->right != nullptr){
	current = top->right;
	break;
      }
    }

  }
  return answer;
}





