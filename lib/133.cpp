#include "../include/133.h"

Node* cloneGraph(Node* node){
  int val = node->val;
  vector<Node*> newNeighbors(node->neighbors.size());
  for(int i = 0; i < newNeighbors.size(); i++){
    newNeighbors[i] = cloneGraph(node->neighbors[i]);
  }
  Node*  newNode = new Node(val);
  return newNode;
}
