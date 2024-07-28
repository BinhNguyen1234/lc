#include "../include/BinaryTree.h"
#include <iostream>
#include "../include/TreeNode.h"
#include <vector>
#include <queue>
#include <optional>
using namespace std;



TreeNode* buildBinaryTree(vector<optional<int>>& listInt){
    if(listInt.empty()){
      return nullptr;
    }
    TreeNode* newNode = new TreeNode(listInt[0].value());
    queue<TreeNode*> q;
    q.push(newNode);
    int i = 0;
    int ListSize = listInt.size();

    while(!q.empty()){
      TreeNode* selectedNode = q.front();
      q.pop();
      ++i;
      if(i<ListSize){
	TreeNode* left = nullptr; 
	if(listInt[i].has_value()){
	  left = new TreeNode(listInt[i].value());
	  q.push(left);
	}
	selectedNode->left = left;
      }

      ++i;
     if(i<ListSize){
	TreeNode* right = nullptr; 
	if(listInt[i].has_value()){
	  right = new TreeNode(listInt[i].value());
	  q.push(right);
	}
	selectedNode->right = right;
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
    cout << selectedNode->val << endl;
    if(selectedNode->left != nullptr){
      q.push(selectedNode->left);
    }
    
    if(selectedNode->right != nullptr){
      q.push(selectedNode->right);
    }
  }
}



