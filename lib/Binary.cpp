#include "../include/Binary.h"
#include <stack>
#include <vector>
#include <math.h>
 using namespace std;



int convertToDecimal(vector<int> bNumber){
  int answer = 0;

  int lastIndex = bNumber.size() - 1 ;
  for(int i = 0; i < bNumber.size(); i++){
  
    answer += bNumber[i]* pow(2, lastIndex - i);

  }
  return answer;

}
vector<int> convertToBinary(int dNumber){
  stack<int> s;
  vector<int> bin;
  int remainder;
  int devision = dNumber;
  do {
    remainder = devision%2;
    devision /= 2;
    s.push(remainder);
  } while(devision > 0);
  
  while(!s.empty()){
    bin.push_back(s.top());
    s.pop();
  }
  return bin;
}
