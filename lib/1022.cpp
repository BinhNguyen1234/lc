#include "../include/1022.h"
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int sumRootToLeaf(TreeNode *root){
  int answer = 0;
  vector<int> path;
  vector<vector<int>> allPath;
  if(root == nullptr){
    return answer;
  }
  stack<TreeNode*> s;
  s.push(root);
  path.push_back(root->val);
  TreeNode* visitor = root;

  while(!s.empty()){

    TreeNode* current = s.top();

    TreeNode* left = visitor->left;
    // go to dept left
    while(left!=nullptr){
      s.push(left);
      //write history path build path
      path.push_back(left->val);
      left = current->left;
    }

    while(!s.empty()){
      TreeNode* leftDeptFirst = s.top();
      TreeNode* right = leftDeptFirst->right;

      s.pop();
      path.pop_back();
      if(right != nullptr){
	s.push(right);
	visitor = s.top();
	path.push_back(right->val);	
	break;
      }else {
	allPath.push_back(path);
      }   
    }
  }

  for(int i =0; i < allPath.size(); i++){
    int decimalAtPath = 0;
    int sizeOfBinary = allPath[i].size();
    for(int j = 0; j < sizeOfBinary; j++){
	decimalAtPath += allPath[i][j] * pow(2,sizeOfBinary - i);
    }
    answer += decimalAtPath;
  }


  return answer;
}
