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
  TreeNode* top = stck.top();
  while(top != nullptr){

    TreeNode* left = top->left;

    // put first-dept left to stack
    while(left != nullptr){
      stck.push(left);
      left = stck.top();
    }
    top = stck.top(); //get first-dept left
    answer.push_back(top->val);
    stck.pop(); // remove first-dept left from stack  
    //get right if have
    while(top->right == nullptr){
      stck.pop();
      top = stck.top();
    }
    if(top->right !=nullptr){
      top = stck.top();
    }
  }
  return answer;
}





