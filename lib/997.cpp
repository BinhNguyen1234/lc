#include "../include/997.h"		
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;


int findJudge(int n, vector<vector<int>>& trust){
  //edge case
  if(trust.size() == 0){
    return  n > 1 ? -1 : 1; 
  }


  unordered_map<int,unordered_set<int>> trustclub;
  vector<bool> isTrustSomeone(n + 1, true); 
  for(auto& t: trust){
    trustclub[t[1]].insert(t[0]);
    isTrustSomeone[t[0]] = false;
  }

  for(auto& tc: trustclub){
    if(tc.second.size() == n-1 && isTrustSomeone[tc.first] == true){
      return tc.first;
    }
  }
  return -1;
}
