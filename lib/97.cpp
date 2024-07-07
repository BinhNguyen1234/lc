#include "../include/97.h"
#include "../include/TreeNode.h"
#include <vector>
#include <stack>
using namespace std;

vector<int> inorderTraversal(TreeNode* root){
  vector<int> answer;
  stack<TreeNode*> stck;
  stck.push(root);

  while(!stck.empty()){

    TreeNode* left = stck.top()->left;
    while(left != nullptr){
      stck.push(left);
      left = stck.top()->left;
    }
    TreeNode* current = stck.top();

    answer.push_back(current->val);
    if(current->right != nullptr){
      stck.push(current->right);
    }
  }

  
  return answer;
}





