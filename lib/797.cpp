#include "../include/797.h"

void DFS(vector<vector<int>>& graph, vector<vector<int>>& answer, vector<int> currentPath, int vertex){
  currentPath.push_back(vertex);
  if(vertex == graph.size() - 1){
    answer.push_back(currentPath);
    return;
  }
  for(auto& g : graph[vertex]){
    DFS(graph, answer, currentPath, g);
  }
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
  vector<vector<int>> answer;
  vector<int> currentPath;
  DFS(graph,answer,currentPath,0);
  return answer;
}
