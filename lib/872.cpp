#include "../include/872.h"
#include <stack>
#include <string>
#include <iostream>
using namespace std;
bool leafSimilar(TreeNode *root1, TreeNode *root2){
  stack<TreeNode*> s1;
  stack<TreeNode*> s2;
  bool answer = true;
  TreeNode* current1 = root1;
  TreeNode* current2 = root2;
  string string1;
  string string2;
  while(!s1.empty()||current1!=nullptr) {
    while(current1!= nullptr){
      if(current1->right){
	s1.push(current1->right);
      }
      s1.push(current1);
      current1 = current1->left;
    }
    
    if(!s1.empty() && s1.top()->right == nullptr){
      string1 = string1.append(to_string(s1.top()->val)).append(";");
    }

    while(!s1.empty()){
      TreeNode* top = s1.top();
      s1.pop();
      if(top->right){
	if(!s1.empty()&& s1.top() == top->right){
	  TreeNode* right = s1.top();
	  s1.pop();
	  s1.push(top);
	  current1 = right;
	  break;
	}	
      }
    }
  };
  
  while(!s2.empty() || current2 != nullptr) {
    while(current2!= nullptr){
      if(current2->right){
	s2.push(current2->right);
      }
      s2.push(current2);
      current2 = current2->left;
    }
    if(!s2.empty() && s2.top()->right == nullptr){
      string2 = string2.append(to_string(s2.top()->val)).append(";");
    }
    while(!s2.empty()) {
      TreeNode* top = s2.top();
      s2.pop();
      if(top->right){
	if(!s2.empty()&& s2.top() == top->right){
	  TreeNode* right = s2.top();
	  s2.pop();
	  s2.push(top);
	  current2 = right;
	  break;
	}	
      }
    }
  };
  return string1 == string2;
}
