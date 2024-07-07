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

  while(!stck.empty()){

    TreeNode* current = stck.top();
    TreeNode* left = current->left;
    while(left != nullptr){
      stck.push(left);
      left = stck.top()->left;
    }
    stck.pop();
    current = stck.top();

    answer.push_back(current->val);
    if(current->right != nullptr){
      stck.push(current->right);
    }
  }

  
  return answer;
}





