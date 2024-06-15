#include "../include/653.h"
#include <queue>
#include "../include/TreeNode.h"
using namespace std;

bool LookupValue(TreeNode* root, int lk){
  if(root == nullptr){
    return false;
  }
  
  if(lk == root->val) {
    return true;
  }
  else if (lk < root->val){
     return  LookupValue(root->left, lk);
  } else {
     return  LookupValue(root->right, lk);
  }
}

bool findTarget(TreeNode *root, int k){
  queue<TreeNode*> q;

  q.push(root);



  while(!q.empty()){
    auto FirstInQ = q.front();

    int val = FirstInQ->val;
    int lookupValue = k - val;

    // how to find value
    if(lookupValue == val ){
      q.pop();
    } else if (lookupValue < val){
      q.push(FirstInQ->left);
    } else {
      q.push(FirstInQ->right);
    }

    //
    if(FirstInQ->left != nullptr){
      q.push(FirstInQ->leftl);
    }

    if(FirstInQ->right != nullptr){
      q.push(FirstInQ->right);
    }


// check all element in queue
// 1. push element to check in queue
// 2. get value and get remain
// 3. if this node was be checke  before, we will ignore it to optimize the algorithm
//
    q.pop();
  }
  return true;
}







