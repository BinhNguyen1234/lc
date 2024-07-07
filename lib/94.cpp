#include "../include/94.h"
#include "../include/TreeNode.h"
#include <vector>
#include <stack>
using namespace std;
// sample [1,null,2,3]
vector<int> inorderTraversal(TreeNode* root){
  
  vector<int> answer;
  if(root == nullptr) return answer;
  stack<TreeNode*> stck;
  stck.push(root);

  while(!stck.empty()){

    TreeNode* current = stck.top();
    while(!stck.empty()){

      TreeNode* left = current->left; // this casue inter loop
      while(left != nullptr){
	stck.push(left);
	left = stck.top()->left;
      }
      current = stck.top();
      stck.pop();
      answer.push_back(current->val);
      if(current->right != nullptr){
	stck.push(current->right);
      }
    }
  }
  return answer;
}





