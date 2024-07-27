#include "../include/145.h"
#include <stack>
#include <iostream>
using namespace std;
//left->right->root
vector<int> postorderTraversal(TreeNode *root){
  vector<int> answer;
  stack<TreeNode*> s;
  TreeNode* current = root;
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
      if(top->right !=  nullptr && !s.empty()){
	TreeNode* right = top->right;
	TreeNode* nextNode = s.top();
	if(right == nextNode){
	  s.pop();
	  s.push(top);
	  current = nextNode;
	  break;
	}
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

