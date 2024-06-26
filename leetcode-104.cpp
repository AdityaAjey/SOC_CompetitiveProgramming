#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // height of root is equal to maximum depth -1
        if(!root) return 0;  
        if(root->left || root->right){
            return std::max(maxDepth(root->left), maxDepth(root->right))+1;
        }
        return 0; // the maxdepth will be 1 if no children for the node
       
    }
};
// above is wrong
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // height of root is equal to maximum depth - 1
        if(!root) return 0;
        
        return std::max(maxDepth(root->left), maxDepth(root->right))+1;
        
        // the height is like maximum number of connections/roads from root to node while depth is number of nodes
       
    }
};