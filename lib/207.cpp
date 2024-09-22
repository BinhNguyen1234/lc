#include "../include/207.h"
#include <vector>
#include <unordered_set>
#include <queue>

#define visited  1
#define processing 2
#define un_visited 0

using namespace std;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

      vector<int> status(numCourses,un_visited);
      vector<unordered_set<int>> neighborList(numCourses);
      queue<int> q;

      for(auto& p : prerequisites){
	neighborList[p[0]].insert(p[1]);
      }
      


      for(int i = 0; i < neighborList.size(); i++){
	if(status[i] != visited){ 
	 q.push(i);
	}

	while(!q.empty()){
	  int current = q.front();
	  q.pop();
	  if(status[current] == processing){
	    return false;
	  }else {
	    status[current] = processing;
	  }
	  for(auto& a : neighborList[current]){
	    if(status[a] == un_visited){
	      q.push(a);
	    }
	  }
	  status[current] = visited;
	}
      }
      return true;
    }
      

    
