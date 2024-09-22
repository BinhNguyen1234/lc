#include "../include/207.h"
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

      vector<bool> visited(numCourses);
      vector<unordered_set<int>> neighborList(numCourses);
      queue<int> q;

      for(auto& p : prerequisites){
	neighborList[p[0]].insert(p[1]);
      }
      
      for(int i = 0; i < neighborList.size(); i++){

	q.push(i);
	while(!q.empty()){
	  int current = q.front();
	  q.pop();
	  
	  
	}
      }
      
    }

  bool canFinishDFS(vector<int>& visited, vector<unordered_set<int>>& neigborsList, int i){
      

    
  }
