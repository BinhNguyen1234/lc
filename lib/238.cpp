#include "../include/238.h"

vector<int> productExceptSelf(vector<int> &nums){
  vector<int> answer(nums.size());
  vector<int> leftProduct(nums.size(),1);
  vector<int> rightProduct(nums.size(),1);
  int size = nums.size();
  for(int i = 1; i < size; i++){
    leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
  }
  
  for(int i = size - 2; i >= 0; i++){
    rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
  }

  for(int i = 0; i < answer.size(); i++){
    answer[i] = leftProduct[i] * rightProduct[i];
  }
  return answer;
}
