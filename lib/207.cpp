#include "../include/207.h"
#include <vector>
#include <unordered_set>
#include <queue>

#define visited  1
#define processing 2
#define un_visited 0

using namespace std;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> degree(numCourses,0);
      vector<unordered_set<int>> graph(numCourses);

      for(auto& p : prerequisites){
	degree[p[1]] += 1;
	graph[p[0]].insert(p[1]);
      }

      queue<int> q;

      for(int i = 0; i < numCourses; i++){
	if(degree[i] == 0){
	  q.push(i);
	}
      }

      vector<int> topologicalList;

      while(!q.empty()){
	int current = q.front();
	q.pop();
	topologicalList.push_back(current);

	for(auto& g: graph[current]){
	  degree[g] -= 1;
	  if(degree[g] == 0){
	    q.push(g);
	  }
	}
  
      }

      return topologicalList.size() == numCourses;
    }
      
namespace Solution2 {
  bool DFS(vector<vector<int>> graph, vector<int> &status, int index){
    if(status[index] == processing){
      return false;
    } else if (status[index] == visited){
      return true;
    } else {
      status[index] = processing;
    }
    for(auto& g : graph[index]){
      if(DFS(graph,status,g) == false){
	return false;
      }
    }
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> graph(numCourses);
    for(auto& p : prerequisites){
      graph[p[1]].push_back(p[0]);
    }
    vector<int> status(numCourses,0); 
    for(int i = 0; i < numCourses; i++){
      if(DFS(graph,status,i) == false){
	return false;
      }
    }
    return true;
  }

}
    
