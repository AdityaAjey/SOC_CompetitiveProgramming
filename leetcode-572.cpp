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
    bool isSameTree(TreeNode* p, TreeNode* q) { // taking this function form leet 100
        if(p==nullptr || q==nullptr) return p==q;
        bool a=p->val==q->val;
        bool b=isSameTree(p->left, q->left);
        bool c=isSameTree(p->right, q->right);
        return a && b && c;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(isSameTree(root, subRoot)) return true;
        // if(root) return isSubtree(root->left, subRoot) || isSameTree(root->right, subRoot); // galat func call krdia be
        
        if(root) return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); // what if root is null
        return false;
    }
};