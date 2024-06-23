#include "../include/BinaryTree.h"
#include <iostream>
#include "../include/TreeNode.h"
#include <vector>
#include <queue>

using namespace std;



TreeNode* buildBinaryTree(vector<int>& listInt){
    if(listInt.empty()){
      return nullptr;
    }
    TreeNode* newNode = new  TreeNode(listInt[0]);
    queue<TreeNode*> q;
    q.push(newNode);
    int i = 0;
    int ListSize = listInt.size();
    while(!q.empty()){
      TreeNode* selectedNode = q.front();
      q.pop();
      cout   << selectedNode->val << endl;     
      ++i;
      if(i<ListSize){
	TreeNode* left = new TreeNode(listInt[i]);
	selectedNode->left = left;
	q.push(selectedNode->left);
      }

      
      ++i;
      if(i<ListSize){
	TreeNode* right = new TreeNode(listInt[i]);
	selectedNode->right = right;
	q.push(selectedNode->right);
      }
    }
    return newNode;

}
void BreathFirstPrint(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    TreeNode* selectedNode = q.front();
    q.pop();
    cout << selectedNode->val;
    if(selectedNode->left != nullptr){
      q.push(selectedNode->left);
    }
    
    if(selectedNode->right != nullptr){
      q.push(selectedNode->right);
    }
  }
}



