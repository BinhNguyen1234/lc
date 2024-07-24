#include "../include/145.h"
#include <stack>
#include <iostream>
using namespace std;

vector<int> postorderTraversal(TreeNode *root){
  vector<int> answer;
  if(root == nullptr){
    return answer;
  }

  stack<TreeNode*> s;
  TreeNode* current = root;
  TreeNode* visited = nullptr;
  while(!s.empty() || current != nullptr){
    while(current != nullptr){
      if(current->right != nullptr){
	s.push(current->right);
      }
      s.push(current);
      current = current->left;
    }
    while(!s.empty()){
      TreeNode* top = s.top();
      s.pop(); 
      if(top->right != s.top()){
	  s.pop();
	  s.push(top);
	  current = top->right;
	  break;
      }
      answer.push_back(top->val);
    }
  }
  return answer;
}
void postOrderRecursive(TreeNode* root, vector<int>& answer){
  if(root == nullptr){
    return ;
  }
  postOrderRecursive(root->left, answer);
  postOrderRecursive(root->right, answer);
  answer.push_back(root->val);
}
vector<int> useRecursiveToPostorderTraversal(TreeNode* root){
  vector<int> answer;
  if(root == nullptr){
    return answer;
  }
  postOrderRecursive(root, answer);
  return answer;
}

