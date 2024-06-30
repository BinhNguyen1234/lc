#include "../include/993.h"
#include <vector>
using namespace std;

vector<vector<int>> pathSum(TreeNode *root, int targetSum){

                                    
}
void buildingPath(TreeNode* root, int targetSum, vector<vector<int>> Sum, vector<int> path){
  if(root == nullptr){
    return ;
  }
  if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
  WZECAXDZ]
    Sum.push_back(path);
  }
  buildingPath(root->left, targetSum - root->val, Sum, path);
  buildingPath(root->right, targetSum - root->val, Sum, path);
}

