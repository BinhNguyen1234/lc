#include "../include/210.h"
#include <vector>
#include <queue>
#
using namespace std;
namespace Solution1 {
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
  vector<int> answer;
  
  vector<vector<int>> graph(numCourses);
  vector<int> indegree(numCourses,0);
  
  for(auto& p : prerequisites){
    graph[p[0]].push_back(p[1]);
    indegree[p[1]] += 1;
  }
 
  queue<int> q;
  for(int  i = 0 ; i < numCourses; i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int current = q.front();
    q.pop();
    answer.push_back(current);

    for(auto& g: graph[current]){
      indegree[g] -= 1;
      if(indegree[g] == 0){
	q.push(g);
      }
    }
  }
  if(answer.size() != numCourses){
    answer = vector<int>();
  }
  int size = answer.size();
  for(int i = 0; i < size/2; i++){
    
    int temp = answer[i];
    answer[i] = answer[size - 1 - i];
    answer[size - 1 - i]= temp;
  }
  return answer;
}
}

namespace Solution2 {
#define visited 1
#define processing -1
#define un_visited 0
bool DFS(vector<vector<int>>& graph, int index, vector<int>& answer, vector<int>& status){
  if(status[index] == processing){
    return false;
  } else if (status[index] == visited){
    return true;
  } 
  else {
    status[index] = processing;
  }
  for(auto& g : graph[index]){
    DFS(graph, g, answer, status);
  }
  answer.push_back(index);
  status[index] = visited;
  return true;
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
    vector<int> answer;

    vector<int> status(numCourses,un_visited);

    vector<vector<int>> graph(numCourses);

    for(auto& p : prerequisites){
      graph[p[1]].push_back(p[0]);
    }

    for(int i = 0; i < graph.size(); i++){
     if(DFS(graph, i, answer, status) == false){
      return {};
     };
    }
    return answer;
}


}
