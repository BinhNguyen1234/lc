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
  TreeNode* next = root->left;
  while(!s.empty()){
    while(next != nullptr){
      s.push(next);
      next = next->left;
    }
    
    while(!s.empty()){
      TreeNode* top = s.top();
      s.pop();
      if(top->right != nullptr){

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

