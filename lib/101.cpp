#include "../include/101.h"
#include <queue>
using namespace std;

bool isSymmetric(TreeNode* root){
  queue<TreeNode*> q1;
  queue<TreeNode*> q2;
  q1.push(root);
  q2.push(root);
  while(!q1.empty()){
   TreeNode* selected1 = q1.front();
   TreeNode* selected2 = q2.front();
  
   if(selected1 == nullptr && selected2 == nullptr){
    continue;
   }
   if((selected2 == nullptr) ^ (selected1 == nullptr)){
    return false;
   }

   if(selected1->val != selected2->val){
      return false;
   }
    q1.pop();
    q2.pop();

   
      q1.push(selected1->left);
      q2.push(selected2->right);
      q1.push(selected1->right);
      q2.push(selected2->left);

    
    

  }
  return true;
}
