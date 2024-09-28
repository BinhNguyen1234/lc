#include "../include//210.h"
#include <vector>
#include <queue>

using namespace std;

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
  return answer;
}


