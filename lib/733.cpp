#include "../include/733.h"
#include <vector>
using namespace std;


// O(N*M)
vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color){
        if(image[sr][sc] == color){
            return image;
        }
        int currentValue = image[sr][sc];
        image[sr][sc] = color;
        if(sr - 1 >= 0 && image[sr - 1][sc] == currentValue){
           image = floodFill(image,sr -1, sc, color);
        }
        if(sc - 1 >= 0 && image[sr][sc - 1] == currentValue){
            floodFill(image,sr, sc - 1, color);
        }
        if(sr + 1 < image.size() && image[sr + 1][sc] == currentValue){
            floodFill(image, sr + 1, sc, color);
        }
        if(sc + 1 < image[sr].size() && image[sr][sc + 1 ] == currentValue){
           floodFill(image,sr, sc + 1, color);
        }
        return image;
};

vector<vector<int>> floodFill2(vector<vector<int>>& image,int sr, int sc, int color){
  return image;
};



