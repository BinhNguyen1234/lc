#include "../include/133.h"
#include <unordered_map>
#include <queue>
using namespace std;
Node* cloneGraph(Node* node, unordered_map<int, Node*>& cached){
  Node* newNode = new Node(node->val);

  for(auto& n : node->neighbors){
    if(cached[n->val] == nullptr){
      cached[n->val] = cloneGraph(n, cached);
    }
    newNode->neighbors.push_back(cached[n->val]);
  }
  return newNode;
}
Node* cloneGraph(Node* node){
  unordered_map<int,Node*> map;
  if(node == nullptr){
    return nullptr;
  }


  return cloneGraph(node, map);
}

