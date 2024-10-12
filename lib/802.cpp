#include "../include/802.h"
#include <queue>


bool isSafe(vector<vector<int>>& graph, int index, vector<int>& visited){
  if(graph[index] == 0){
    return true;
  }
  for(auto& g : graph[index]){
    if(isSafe(graph, g, visited) == false){
      return false;
    }
  }
  return true;
}

// this graph is outdegree, cyclic
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
  vector<int> numberOfInDegree(graph.size());
  for(int i = 0; i < graph.size(); i++){
    numberOfInDegree[i] = graph[i].size();
  }
  vector<int> visited;
}
