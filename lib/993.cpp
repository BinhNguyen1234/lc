#include "../include/993.h"
#include <queue>

using namespace std;


bool isCousins(TreeNode *root, int x, int y){
  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();
    int a = -1;
    int b = -1;
    for(int i = 0; i < size; i++){
      TreeNode* current = q.front();
      q.pop();
      if(current->val == x){
	a = x;
      }
      if(current->val == y){
	b = y;
      }
    }
    if(a == x && b== y){
      return true;
    } else {
      a = -1;
      b = -1;
    }

  }
  return false;
}
int findDept(TreeNode* root, int value){
  if(root->val == value){
    return 1;
  }
  else {
    return 0;
  }
}
