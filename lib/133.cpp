#include "../include/133.h"
#include <unordered_map>
#include <queue>
using namespace std;
Node* cloneGraph(Node* node, unordered_map<int, Node*>& cached){
  Node* newNode = cached[node->val];
  if(newNode == nullptr){
    newNode = new Node(node->val);
    vector<Node*> cloneNeighbors(node->neighbors.size());

    newNode->neighbors = cloneNeighbors;
  }
  for(int i = 0; i < newNode->neighbors.size(); i++){
    newNode->neighbors[i] = cloneGraph(node->neighbors[i], cached); 
  }
  return newNode;
}

Node* cloneGraph(Node* node){
  if(node == nullptr){
    return nullptr;
  }
  unordered_map<int,Node*> cached;
  return cloneGraph(node, cached);
}

