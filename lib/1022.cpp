#include "../include/1022.h"
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int convertPathToDecimal(TreeNode* node, int backtracking){
  if(node == nullptr){
    return backtracking;	
  }
  int currentValue = backtracking*2 + node->val;
  return convertPathToDecimal(node->left, currentValue)+ convertPathToDecimal(node->right,currentValue);
}
int sumRootToLeaf(TreeNode *root){
  int currentSum = 0;
  return convertPathToDecimal(root, currentSum);
}


