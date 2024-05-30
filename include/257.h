#include <vector>
#include <string>

using namespace std;

#ifndef LeetCode257
#define LeetCode257
#ifdef __cplusplus
extern "C" {
#endif
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    vector<string> binaryTreePaths(TreeNode* root);
    void traverseToLeafNode(TreeNode* root, string previous, vector<string>& store);
#ifdef __cplusplus
}
#endif

#endif