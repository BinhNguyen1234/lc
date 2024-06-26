#include "../include/993.h"
#include <queue>

using namespace std;


bool isCousins(TreeNode *root, int x, int y){
  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    bool result = true;
    int size = q.size();
    for(int i = 0; i < size; i++){
      TreeNode* current = q.front();
      result = findDept(current->left,x,y) && findDept(current->right,x,y);  
      
      if(result == true){
	return false;
      }

      if(current->left != nullptr){
	q.push(current->left);
      }
      if(current->right != nullptr){
	q.push(current->right);
      }
    }

  }
}
bool findDept(TreeNode* root, int value1, int value2){
  if(root == nullptr ){
    return false;
  }
  return root->val == value1 || root->val == value2);
}
