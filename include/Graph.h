#ifndef Graph__
#define Graph__
#include <vector>

using namespace std;
class Node {
  public:
    int val;
    vector<Node*> neighbors;
    Node(){

    }
    Node(int _val){
      val = _val;
    }
    Node(int _val, vector<Node*> _children){
      val = _val;
      neighbors = _children;
    }
};


Node* buildGraph(vector<vector<int>> graph){
  vector<Node*> AllVertex(graph.size()+1); 

  for(int i = 1; i < graph.size() + 1; i++){
    Node* newNode = new Node(i);
    AllVertex[i] = newNode;
  }
  for(int i = 0; i < graph.size(); i++){
    int i1 = i + 1;
    for(auto& vertex : graph[i]){
      AllVertex[i1]->neighbors.push_back(AllVertex[vertex]);
    }
  }
  return AllVertex[1];
}

#endif


