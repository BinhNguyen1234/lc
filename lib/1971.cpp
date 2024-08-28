#include "../include/1971.h"
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
  vector<vector<int>> graph(n);
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



namespace Solution2 {

bool validPath(int n, vector<vector<int> > &edges, int source, int destination){
  vector<vector<int>> graph(n);
  for(auto ed : edges){
    graph[ed[0]].push_back(ed[1]);
    graph[ed[0]].push_back(ed[0]);
  }
  vector<bool> visited(n,0);
  stack<int> s;
  s.push(source);
  visited[source] = 1;
  while(!s.empty()){
    int curr = s.top();
    s.pop();
    if(curr == destination){
      return true;
    }
    for(auto &node : graph[curr]){
      if(!visited[node]){
	visited[node] = true;
	s.push(node);
     }
    }
  }
  return false;
}
}

bool Solution3::validPath(int n, vector<vector<int> > &edges, int source, int destination){
  vector<int> DSU(n);
  for(int i = 0; i < n; i++){
    DSU[i] = i;
  }
}

