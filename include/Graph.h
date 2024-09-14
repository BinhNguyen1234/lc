#ifndef Graph__
#define Graph__
#include <vector>
#include <iostream>
#include <queue>
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


bool isGraphClone(Node* graph1, Node* graph2){
  bool isEqualVal = graph1->val == graph2->val && graph1->neighbors.size() == graph2->neighbors.size();
  for(int i = 0; i < graph1->neighbors.size(); i++){
    isEqualVal = isEqualVal && isGraphClone(graph1->neighbors[i],graph2->neighbors[i]);
  }
  return isEqualVal;
}

void printGraph(Node* node){
  queue<Node*> q;
  vector<bool> visited;
  vector<vector<int>> graph;

  q.push(node);
  while(!q.empty()){
    Node* current = q.front();
    q.pop();

    
    while(visited.size() < current->val){
      visited.push_back(false);
      graph.push_back({});
    }
    if(visited[current->val -1] == false){

      for(auto& n : current->neighbors){
	if(visited[n->val - 1] == false){
	  q.push(n);
	}
	cout << n->val << "-";
	graph[current->val - 1].push_back(n->val);
      }
    }
    visited[current->val - 1] = true;
  }


  std::cout << "[";
  for(auto& g : graph){
    std::cout<< "[";
      for(auto& a : g){
 	std::cout << a << ",";
     }
    std::cout << "]";
  }
  std::cout << "]";
}

Node* buildGraph(vector<vector<int>> graph){
  vector<Node*> AllVertex(graph.size()); 
  for(int i = 0; i < graph.size(); i++){
    Node* newNode = new Node(i+1);
    AllVertex[i] = newNode;
  }
  for(int i = 0; i < graph.size(); i++){
    for(auto& vertex : graph[i]){
      AllVertex[i]->neighbors.push_back(AllVertex[vertex - 1]);
    }
  }
  return AllVertex[0];
}

#endif


