#include "../include/110.h"
#include <algorithm>
#include "./543.cpp"
using namespace std;
bool isBalanced(TreeNode* root){
    if(root == nullptr){
      return true;
    }
   
    int leftH = Height(root->left);
    int rightH = Height(root->right);
    int diffH = abs(leftH - rightH); 
    return diffH <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

