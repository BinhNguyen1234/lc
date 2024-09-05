#include "../include/1971.h"
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>


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
}



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

using dsu = vector<int>;
// parent[] where parent[v] = parentnode
int findParent(dsu& DSU, int vertex){
  return DSU[vertex] == vertex ? vertex : findParent(DSU,DSU[vertex]);
}

dsu createDSU(int numberOfVertex, vector<vector<int>> &edges){
  dsu DSU(numberOfVertex);

  for(int i = 0; i < numberOfVertex; i++){
    DSU[i] = i;
  }
  for(auto& edge: edges){
    int v1 = findParent(DSU, edge[0]);
    int v2 = findParent(DSU, edge[1]);
    DSU[v1] = v2;
  }
  return DSU;
}

int findRootOfVertexAndRebuildDsu(vector<int>& dsu, int vertex){
  return dsu[vertex] == vertex ? vertex : (dsu[vertex] = findRootOfVertexAndRebuildDsu(dsu,dsu[vertex]));
}
void buildDsu(vector<int>& dsu, vector<vector<int>>& edges){
    for(auto &edge : edges){
      int v1 = findRootOfVertexAndRebuildDsu(dsu,edge[0]);
      int v2 = findRootOfVertexAndRebuildDsu(dsu,edge[1]);
      dsu[v1] = v2;
    }
}


bool Solution3::validPath(int n, vector<vector<int> > &edges, int source, int destination){
  vector<int> dsu(n);
  for(int i = 0; i < n; i++){
    dsu[i] = i;
  }
  buildDsu(dsu, edges);
  return findRootOfVertexAndRebuildDsu(dsu,source) == findRootOfVertexAndRebuildDsu(dsu,destination);
}


