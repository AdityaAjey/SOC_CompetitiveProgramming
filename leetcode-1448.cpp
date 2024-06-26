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
    // int maxi = INT_MIN;
    // int count=0;
    // int goodNodes(TreeNode* root) {
    //     if(!root) return 0;
    //     if(root->val>=maxi) count++;
    //     maxi = max(maxi, root->val);
    //     return 1+goodNodes(root->left) + goodNodes(root->right);

        
    // }
    int good(TreeNode* root, int maxi) {
        if(!root) return 0;
        if(root->val>=maxi){
            return 1+good(root->left,max(maxi,root->val))+good(root->right,max(maxi,root->val));
        }
        return good(root->left,max(maxi,root->val))+good(root->right,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return 1+good(root->left, root->val) + good(root->right, root->val);
    }
};