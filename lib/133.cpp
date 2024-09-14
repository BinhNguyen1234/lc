#include "../include/133.h"
#include <unordered_map>
#include <queue>
using namespace std;
Node* cloneGraph(Node* node, unordered_map<int, Node*>& cached){
  Node* newNode = cached[node->val];
  if(newNode == nullptr){
    newNode = new Node(node->val);
    cached[node->val] = newNode;
  }else {
    return newNode;
  }
  for(int i = 0; i < node->neighbors.size(); i++){
     newNode->neighbors.push_back(cloneGraph(node->neighbors[i], cached));
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

