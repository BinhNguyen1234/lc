#include <queue>
#include <vector>
#include "../include/TreeNode.h"


using namespace std;
bool LookupValue(TreeNode* root, int lk){
  if (root == nullptr) return false;
  if(root->val== lk) return true;
  else if(lk < root->val) return LookupValue(root->left, lk);
  else return LookupValue(root->right, lk);
}
bool LookupValueInVector(vector<TreeNode*> vtTree,int lk){
   bool result = false;
   for(auto i:vtTree){
     result = LookupValue(i,lk);
     if(result == true){
      return result;
     }
   }
   return result;
}
bool findTarget(TreeNode* root, int k){
  vector<TreeNode*> vt; 
  bool answer = false;
  vt.push_back(root);
  while(!vt.empty()){

    int size = vt.size();
    TreeNode* last = vt[size - 1];
    vt.pop_back();
    int lkVl = k- last->val;
    if(last->right != nullptr){
      vt.push_back(last->right);
    }
    if(last->left != nullptr){
      vt.push_back(last->left);
    }
    answer = LookupValueInVector(vt, lkVl);
    if(answer == true) return answer;
  }
  return answer;
}
