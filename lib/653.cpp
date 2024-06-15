#include "../include/653.h"
#include <queue>
#include "../include/TreeNode.h"
using namespace std;
bool findTarget(TreeNode *root, int k){
  queue<TreeNode*> q;

  q.push(root);

  int val = root->val;

  while(!q.empty()){
    int size = q.size();
    TreeNode* current = q.front();    

    if(current->left != nullptr){

    }

    if(current->right !=nullptr){

    }

    for(int i = 0; i< size; i++){
      
    }

    q.pop();
  }

}






