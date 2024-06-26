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
    int height(TreeNode* root){
        if(!root) return -1;
        return 1+max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diam=0;
        if(!root) return 0;
        diam = max(2+ height(root->left)+ height(root->right),diam);
        diam = max(diam, diameterOfBinaryTree(root->left));
        diam = max(diam, diameterOfBinaryTree(root->right));
        return diam;

    }
};// height func is simple but the diameter needs to be calculated and updated at each node
// at each node do diameter   = max(diameter, 2+leftheight+rightheight)


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightAndDiameter(root, diameter);
        return diameter;
    }
    
private:
    int heightAndDiameter(TreeNode* node, int &diameter) {
        if (!node) return 0;
        
        int leftHeight = heightAndDiameter(node->left, diameter);
        int rightHeight = heightAndDiameter(node->right, diameter);
        
        // Update the diameter if the path through the current node is larger
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};//better given by gpt 