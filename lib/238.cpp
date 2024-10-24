#include "../include/238.h"

vector<int> productExceptSelf(vector<int> &nums){
  vector<int> answer(nums.size());
  vector<int> leftProduct(nums.size());
  vector<int> rightProduct(nums.size());
  int size = nums.size();
  leftProduct[0] = 1;
  rightProduct[size - 1] = 1;
  for(int i = 1; i < size - 1; i++){
    leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
    rightProduct[i] = rightProduct[size - 1 - i] * nums[i + 1];
  }
  for(int i = 0; i < answer.size(); i++){
    answer[i] = leftProduct[i] * rightProduct[i];
  }
  return answer;
}
