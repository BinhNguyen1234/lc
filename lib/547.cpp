#include "../include/547.h"
#include <unordered_set>


int findRoot(vector<int>& unionGroup, int index){
  return unionGroup[index] == index ? index : unionGroup[index] = findRoot(unionGroup,unionGroup[index]);  
}

int findCircleNum(vector<vector<int>>& isConnected) {
  vector<int> unionGroup(isConnected.size());

  for(int i = 0; i < unionGroup.size();i ++){
    unionGroup[i] = i;
  }
  
  unordered_set<int> inidivduallyProvince;

  for(int cityY = 0; cityY < isConnected.size(); cityY++){
    for(int cityX = 0; cityX < isConnected[cityY].size(); cityX++){
      if(isConnected[cityY][cityX] == 1){
	unionGroup[cityX] = findRoot(unionGroup, cityY);
      }
    }
  }
  for(int i =0; i < unionGroup.size(); i++){
    inidivduallyProvince.insert(findRoot(unionGroup, i));
  }
  return inidivduallyProvince.size();
}
