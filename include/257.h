
#ifndef LeetCode257
#define LeetCode257



#include <vector>
#include <string>
#include "TreeNode.h"

using namespace std;


#ifdef __cplusplus
extern "C" {
#endif
    vector<string> binaryTreePaths(TreeNode* root);
    void traverseToLeafNode(TreeNode* root, string previous, vector<string>& store);
#ifdef __cplusplus
}
#endif

#endif
