#include "../include/Binary.h"
#include <stack>
#include <vector>
 using namespace std;



int convertToDecimal(int bNumber){



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
