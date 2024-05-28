#include "../include/1436.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    string result = "";
    unordered_map<string, int> map;
    for(auto path: paths){
        for(int i = 0; i < path.size() - 1; i++){
            map[path[i]]++;
        }
    }
    for(auto path : paths){
        if(map[path[path.size()-1]] == 0){
            return path[path.size()-1];
        };
    }
    return result;
}