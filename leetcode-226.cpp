/**
 * Definition for a binary tree node. */
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr; // when root is null
        if(root->left || root->right){ // the case when the root or the current node is not a leaf
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        else return root; // if node is a leaf return;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// congrats for your first question on trees 
