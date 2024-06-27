#include "../include/111.h"
#include <math.h>
#include <algorithm>
using namespace std;
int minDept(TreeNode* root){
    if(root == nullptr) return 0;
    return 1 + (min(minDept(root->left), minDept(root->right)));
}
