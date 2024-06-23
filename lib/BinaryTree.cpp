#include "../include/BinaryTree.h"
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
    int i = 0;
    int ListSize = listInt.size();
    while(i<ListSize){
      TreeNode* selectedNode = q.front();
      q.pop();
      
      ++i;
      if(i<ListSize){
	TreeNode* left = new TreeNode(listInt[i]);
	selectedNode->left = left;
	q.push(left);
      }

      
      ++i;
      if(i<ListSize){
	TreeNode* right = new TreeNode(listInt[i]);
	selectedNode->right = right;
	q.push(right);
      }
    }
    return newNode;

}



