#include "../include/637.h"
#include <queue>

using namespace std;


vector<double> averageOfLevels(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    vector<double> aswer;
    while(!q.empty()){

      TreeNode* firstInQ = q.front();
      int totalAtLevel = 0;
      int size = q.size();
      while(--size >= 0){
	totalAtLevel += q.front()->val ;
	q.pop();
      }
      if(firstInQ->left != nullptr){
	q.push(firstInQ->left);	
      }
      if(firstInQ->right != nullptr){
	q.push(firstInQ->right);
      }
    }
    return aswer;  
}
