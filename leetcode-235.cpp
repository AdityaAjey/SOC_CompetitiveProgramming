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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q) return p;
        if(!p || !q) return p; //taking care of null  the null can be 
        
        // binary search tree hai yeh bhool gya kya
        if(p->val < root->val && q->val<root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        
        else if ((p->val > root->val && q->val>root->val)) return lowestCommonAncestor(root->right,p,q);
        return root;
        


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr; //pehle ! chhod diya
        if(p==q) return p;
        TreeNode* curr = root;
        while(curr){
            if(p->val < curr->val && q->val<curr->val){
                curr = root->left;
            }
            else if(p->val > root->val && q->val>root->val){
                curr = root->right;
            }
            else return curr;
        }
        return NULL;
    }
};