#include "../include/653.h"
#include <queue>
#include "../include/TreeNode.h"
using namespace std;

bool LookupValue(TreeNode* root, int lk){
    if(root == nullptr) return false;
    if(root->val == lk) return true;
    else if(lk < root->val) return LookupValue(root->left, lk);
    else return LookupValue(root->right,  lk);
}

bool findTarget(TreeNode *root, int k){
  queue<TreeNode*> q;

  q.push(root);
  while(!q.empty()){
    auto FirstInQ = q.front();
    int lookupValue = k - FirstInQ->val;
    if(FirstInQ->left != nullptr){
      q.push(FirstInQ->left);
    }
    if(FirstInQ->right != nullptr){
      q.push(FirstInQ->right);
    }
    q.pop();
  }
  return true;
}







