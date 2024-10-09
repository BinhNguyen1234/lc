#include "../include/684.h"


int findRoot(vector<int>& unionGroup, int index){
  return unionGroup[index] == index ? index : unionGroup[index] = findRoot(unionGroup, index);
}


vector<int> findRedundantConnection(vector<vector<int>>& edges){
  vector<int> unionGroup(edges.size()+ 1);
  vector<int> answer(2);

  for(int i = 0; i < unionGroup.size(); i++){
    unionGroup[i] = i;
  }

  for(auto& e : edges){
    int x = findRoot(unionGroup, e[0]);
    int y = findRoot(unionGroup, e[1]);
    if(x == y){ 
      answer[0] = e[0];
      answer[1] = e[1];
    }else  {
      unionGroup[x] = y;
    }
  }

  return answer;
}
