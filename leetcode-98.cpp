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
    int maximum(TreeNode* root){
        // no null here
        if(root->left && root->right) return max(root->val,max(maximum(root->left), maximum(root->right)));
        if(root->left) return max(root->val,maximum(root->left));
        if(root->right) return max(root->val,maximum(root->right));
        return root->val;
    }
    int minimum(TreeNode* root){
        // no null here
        if(root->left && root->right) return min(root->val,min(minimum(root->left), minimum(root->right)));
        if(root->left) return min(root->val,minimum(root->left));
        if(root->right) return min(root->val,minimum(root->right));
        return root->val;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root->left){
            if(root->right){
                
                    return maximum(root->left) < root->val && minimum(root->right) > root->val && isValidBST(root->left) && isValidBST(root->right);
                
            }
            else {
                return isValidBST(root->left) && maximum(root->left) < root->val ;
            }
        }
        if(root->right) {
            return minimum(root->right) > root->val && isValidBST(root->right);
        }
        return true;

        
    }

};