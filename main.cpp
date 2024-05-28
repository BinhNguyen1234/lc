#include <iostream>
#include "./include/printHW.h"
#include <vector>
#include <string>
#include "./include/1436.h"
using namespace std;

int main(){
    vector<vector<string>> test{{"pYyNGfBYbm","wxAscRuzOl"},{"kzwEQHfwce","pYyNGfBYbm"}};
    string result = destCity(test);
    cout << result;
    cin;
    return 0;
}