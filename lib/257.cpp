#include "../include/257.h"
#include <vector>
#include <string>
using namespace std;

extern "C" {
    void traverseToLeafNode(TreeNode* root, string previous, vector<string>& store){
        if(root->left != nullptr){
            traverseToLeafNode(root->left, previous + to_string(root->val) + "->", store);
        }
        if(root->right !=nullptr){
            traverseToLeafNode(root->right, previous + to_string(root->val) + "->", store);
        }

        if(root->left == nullptr && root-> right == nullptr){
            previous = previous + to_string(root->val);
            store.push_back(previous);
        }
    };
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> result;
        traverseToLeafNode(root,"",result);
        return result;
    };
}

    
