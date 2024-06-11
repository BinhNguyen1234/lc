#include "../include/463.h"


int islandPerimeter(vector<vector<int>> grid){
  int result = 0;

  for (int i = 0; i < grid.size(); i++){
    int isContinous = 4;
    for(int j = 0; j < grid[i].size(); j++){
      

      if(grid[i][j] == 1){
	result += isContinous;
	isContinous = 2;
	if(i+1 < grid.size() && grid[i+1][j] == 1){
	  result -= 2;
	}
      } else {
	isContinous = 4;
      }
    }
  } 

  return result;
}
