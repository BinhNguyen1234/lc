#include "../include/993.h"
#include <queue>

using namespace std;


bool findDept(TreeNode* root, int value1, int value2){
  if(root == nullptr ){
    return false;
  }
  return root->val == value1 || root->val == value2;
}
bool isCousins(TreeNode *root, int x, int y){
  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
     bool a = false;
     bool b = false;
    int size = q.size();
    for(int i = 0; i < size; i++){
      TreeNode* current = q.front();
      q.pop(); 
      if(findDept(current->left,x,y) && findDept(current->right,x,y)){
	return false;
      };  
      
      if(current->val == x){
	a = true;
      }
      if (current->val == y){
	b = true;
      }
      if(current->left != nullptr){
	q.push(current->left);
      }
      if(current->right != nullptr){
	q.push(current->right);
      }
    }
    if(a && b){
      return true;
    }

  }
  return false;
}
