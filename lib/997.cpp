#include "../include/997.h"
#include <vector>

using namespace std;

void buildDsu(vector<int>& dsu, vector<vector<int>> trust){
  for(auto& t : trust){
    int

  }
}

int findRoot(vector<int>& dsu, int vertex){
  return dsu[vertex] == vertex ? vertext : (dsu[vertex] = findRoot(dsu, dsu[vertex]));
}

int findJudge(int n, vector<vector<int>>& trust){
  vector<int> dsu(n);
  for(int i = 0; i < n; i++){
    dsu[i] = i;
  }
  return -1;
}
