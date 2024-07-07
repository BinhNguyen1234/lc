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
    while(left != nullptr){
      stck.push(left);
      left = stck.top();
    }
    top = stck.top(); //get left
    answer.push_back(top->val);
    stck.pop(); // remove left from stack
    top = stck.top(); // get root
    answer.push_back(top->val);

    //get right if have
    if(top->right != nullptr){
      stck.push(top->right);
      top = stck.top();
      answer.push_back(top->val);
    }
  }
  return answer;
}





