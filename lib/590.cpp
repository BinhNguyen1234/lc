#include "../include/530.h"
#include "../include/Node.h"
#include <vector>

using namespace std;


void postOrder(Node* root, vector<int>& result){
  if(root->children.size() != 0){
    for(int i = 0; i < root->children.size(); i++){
      postOrder(root->children[i], result);
    }
  }else{
    result.push_back(root->val);
  }
}
vector<int> postorder(Node *root){

  vector<int> answer;
  postOrder(root, answer);

  return answer;
    
  
}

