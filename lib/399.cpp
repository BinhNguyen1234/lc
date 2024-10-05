#include "../include/399.h"
#include <unordered_map>
#include <vector>

double DFS(unordered_map<string,unordered_map<string,double>> graph, string a, string b, unordered_map<string,bool>& visited){
  if(graph.find(a)== graph.end() || graph.find(b) == graph.end() || (visited.find(a) != visited.end() && visited[a] == true)){
    return -1.0;
  }
  visited[a] = true;
  if(graph.find(a) != graph.end()){
    if(graph[a].find(b) != graph[a].end()){
      return graph[a][b];
    }
    if(a == b){
      return 1.0;
    }
    for(auto& bQ : graph[a]){
      double temp = DFS(graph, bQ.first, b, visited);
      if(temp != -1.0){
	return bQ.second * temp;
      }
    }
  }
  return -1.0;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries){

  vector<double> answer(queries.size());
  unordered_map<string,unordered_map<string,double>> graph;
  for(int i = 0; i < values.size(); i++){
    graph[equations[i][0]][equations[i][1]] = values[i];
    graph[equations[i][1]][equations[i][0]] = 1/values[i];
  }
  for(int i = 0; i < queries.size(); i++){
    unordered_map<string, bool> visited;
    answer.push_back(DFS(graph,queries[i][0], queries[i][1], visited));
  }
  return answer;
}
