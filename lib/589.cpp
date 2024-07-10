#include "../include/589.h"
#include <vector>
#include <stack>
#include <queue>
#include "../include/Node.h"
using namespace std;
vector<int> preorder(Node *root){
  vector<int> answer;


  if(root == nullptr){
    return answer;
  }
  stack<Node*> s;
  s.push(root);

  while(!s.empty()){
    Node* current = s.top();
    s.pop();
    answer.push_back(current->val);
    s.pop();
    if(!current->children.empty()){
      for(int i = current->children.size() - 1; i >=0 ; i--){
	s.push(current->children[i]);
      }
    }
  }
  return answer;
    

}

