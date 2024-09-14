#include "../include/133.h"
#include <unordered_map>
#include <queue>
using namespace std;
Node* cloneGraph(Node* node, unordered_map<int, Node*>& cached){
  Node* newNode = cached[node->val];
  if(newNode == nullptr){
    newNode = new Node(node->val);
    newNode->neighbors = vector<Node*>(node->neighbors.size());
    cached[node->val] = newNode;
  }
  for(int i = 0; i < newNode->neighbors.size(); i++){
     cloneGraph(node, cached); 
  }
  return newNode;
}

Node* cloneGraph(Node* node){
  std::cout << node->val;
  if(node == nullptr){
    return nullptr;
  }
  unordered_map<int,Node*> cached;
  return cloneGraph(node, cached);
}

