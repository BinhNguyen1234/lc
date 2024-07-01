#include "../include/993.h"
#include <vector>
using namespace std;

void buildingPath(TreeNode* root, int targetSum, vector<vector<int>> Sum, vector<int> path){
  if(root == nullptr){
    return ;
  }
  path.push_back(root->val);
  if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
    Sum.push_back(path);
  }
  buildingPath(root->left, targetSum - root->val, Sum, path);  
  buildingPath(root->right, targetSum - root->val, Sum, path);
  path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum){
  vector<int> path;
  vector<vector<int>> answer;
  buildingPath(root, targetSum, answer,  path) ;
  return answer;
                                    
}
