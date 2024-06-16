#include "../include/653.h"
#include <queue>
#include "../include/TreeNode.h"
using namespace std;

bool LookupValue(TreeNode* root, int lk){
    if(root == nullptr) return false;
    if(root->val == lk) return true;
    return LookupValue(root->right, lk) || LookupValue(root->left, lk);
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







