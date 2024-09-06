#include "../include/997.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;


int findJudge(int n, vector<vector<int>>& trust){
  unordered_map<int,unordered_set<int>> trustclub(n);
  
  for(int i = 0; i < n; i++){
    trustclub[i].insert(i);
  }
  for(auto& t: trust){
    trustclub.erase(t[0]);
    trustclub[t[1]].insert(t[0]);
  }
  for(auto& a: trustclub){
    if(a.second.size()== n-1){
      return a.first;
    }
  }
  return -1;
}
