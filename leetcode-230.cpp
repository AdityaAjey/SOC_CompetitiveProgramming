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
    int number(TreeNode* root){
        if(!root) return 0;
        return 1+number(root->left)+number(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        // stack<TreeNode*> s;
        // TreeNode* curr = root;
        // while(curr){
        //     if(curr->left){
        //         s.push(curr);
        //         curr=curr->left;
        //     }
        //     else if(curr->right){
        //         s.push(curr);
        //         curr=curr->right;
        //     }
        // }
        // binary search lga dala toh life zingalala
        // TreeNode* curr = root;
        if(!root && k==0) return -1;
        int small = number(root->left);
        if(small<k-1) return kthSmallest(root->right, k-small-1);
        if(small ==k-1) return root->val;
        return kthSmallest(root->left, k);
        // while(1){
        //     int small = number(curr->left);
        //     if(small == k-1) return curr->val;
        //     else if(small>k-1) curr = curr->left;
        //     else curr = curr->right;
        // }
        // return 0; cancel
        // stack<TreeNode*> s;
        // while(curr){
        //     s.push(curr);
        //     curr = curr->left;

        // }
        // int count = k;
        // // write modular code naa
        // while(count>0 && !s.empty()){
        //     curr = s.top();
        //     count--;
        //     s.pop();
        //     if(count>0) {
        //         curr = s.top();


        //     }

        // }
    }
};
// finally seekha ki tree mein recursive hi chlega
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1; // Edge case if the root is null

        int leftNodeCount = countNodes(root->left);

        if (leftNodeCount == k - 1) {
            return root->val;
        } else if (leftNodeCount > k - 1) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k - leftNodeCount - 1);
        }
    }
};

class Solution {
     vector<int> inorder;
public:
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return inorder[k-1];
    }
}; // good code also simple