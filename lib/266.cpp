#include "../include/266.h"
#include <queue>


extern "C" {
    TreeNode* invertTree(TreeNode* root){
	

      if(root == nullptr) return root;

      TreeNode* temp = root->right;
      root->right = invertTree(root->left);
      root->left = invertTree(temp);
      return root;
    }
}
