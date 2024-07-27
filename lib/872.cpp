#include "../include/872.h"
#include <stack>
#include <string>
using namespace std;
bool leafSimilar(TreeNode *root1, TreeNode *root2){
  stack<TreeNode*> s1;
  stack<TreeNode*> s2;
  bool answer = true;
  TreeNode* current1 = root1;
  TreeNode* current2 = root2;
  string string1;
  string string2;
  do {
    while(current1!= nullptr){
      if(current1->right){
	s1.push(current1->right);
      }
      s1.push(current1);
      current1 = current1->left;
    }
    
    if(!s1.empty() && s1.top()->right == nullptr){
      string1 += s1.top()->val ;
      string1 += " ";
    }

    while(!s1.empty()){
      TreeNode* top = s1.top();
      s1.pop();
      if(top->right){
	if(!s1.empty()&& s1.top()->right == top){
	  s1.pop();
	  s1.push(s1.top()->right);
	  current1 = top;
	  break;
	}	
      }
    }

  }while(!s1.empty());
  
  do {
    while(current2!= nullptr){
      if(current2->right){
	s2.push(current2->right);
      }
      s2.push(current2);
      current2 = current2->left;
    }
    
    if(!s2.empty() && s2.top()->right == nullptr){
      string2 += s2.top()->val ;
      string2 += " ";
    }

    while(!s2.empty()){
      TreeNode* top = s2.top();
      s2.pop();
      if(top->right){
	if(!s2.empty()&& s2.top()->right == top){
	  s2.pop();
	  s2.push(s2.top()->right);
	  current2 = top;
	  break;
	}	
      }
    }

  }while(!s2.empty());
  return string1 == string2;
}
