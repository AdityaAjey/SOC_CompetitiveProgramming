#include<bits/stdc++.h>
using namespace std;
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
    int Sum(TreeNode* root){ // sum of maximum at each node at top 
        if(!root) return 0;
        int left = Sum(root->left);
        int right = Sum(root->right);
        if(left>0){
            if(right>0)  return root->val+left+right;
            else return root->val+left;
        }
        if(right>0)  return root->val+right;
        return root->val;
    }
    void maxCalc(TreeNode* root, int &sum){
        if(!root) return;
        maxCalc(root->left,sum);
        maxCalc(root->right,sum);
        int curr=root->val;
        int left = Sum(root->left);
        int right = Sum(root->right);
        if(left>0){
            if(right>0) sum=curr+left+right;
            else sum=curr+left;
        }
        else if(right>0) sum =curr+right;
        return;
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxCalc(root,result);
        return result;
    }
};

// understood the problem my problem was doing split many times- to understand what I mean by split watch https://www.youtube.com/watch?v=Hr5cWUld4vU


// so for a node which will be at top I need to do dfs on left and right

/*
    Given root of binary tree, return max path sum (seq of adj node values added together)

    Path can only have <= 1 split point, assume curPath has it, so return can't split again

    Time: O(n)
    Space: O(n)
*/

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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
private:
    int dfs(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return 0;
        }
        
        int left = max(dfs(root->left, maxPath), 0);
        int right = max(dfs(root->right, maxPath), 0);
        
        int curPath = root->val + left + right;
        maxPath = max(maxPath, curPath);
        
        return root->val + max(left, right);
    }
};
