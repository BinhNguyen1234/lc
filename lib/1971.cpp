#include "../include/1971.h"
#include <algorithm>
#include <unordered_map>
#include <queue>
    
bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
  vector<vector<int>> graph;
  for(auto e: edges){
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[1]);
  }
  vector<bool> visited(n,0);
  queue<int> q;
  q.push(source);
  visited[source] = 1;
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    if(curr == destination){
      return true;
    }
    for(auto &node : graph[curr]){
      if(!visited[node]){
	visited[node] = 1;
	q.push(node);
      }
    }

  }
  return false;
};



