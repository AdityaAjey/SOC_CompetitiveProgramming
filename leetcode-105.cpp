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
    TreeNode* build( vector<int>& preorder, vector<int>& inorder, int n, int startp, int endp, unordered_map<int,int> &inOrderindex) {
        if(endp>=n || startp>endp) return nullptr;
        // TreeNode* root=new TreeNode;
        // root->val = preorder[startp];
        int rootVal = preorder[startp];
        TreeNode* root = new TreeNode(rootVal);
        if(startp==n-1 || startp==endp){
            return root;
        }
        int left = startp+1;
        while(left<n && inOrderindex[preorder[left]]< inOrderindex[preorder[startp]] ){ // left the cond. left<n it will cause index out of bound whne the condn remoans true and grows
            left++;
        }
        left --; 
        root->left =   build(preorder, inorder, n, startp+1, left, inOrderindex);
        root->right = build(preorder, inorder, n, left+1, endp, inOrderindex); //endp ke jagah pehle n-1 daala tha
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root ;
        if( preorder.size()==0) {
            root=nullptr;
            return root;
        }
        
        unordered_map<int,int> inOrderindex;
        // unordered_map<int,int> preOrderindex;
        int n=preorder.size();
        
        for(int i=0;i<n;i++){
            inOrderindex[inorder[i]] = i;
            // preOrderindex[preorder[i]] = i;
        }
        
        return build(preorder, inorder, n, 0,n-1, inOrderindex);




        


    }
};

//i didn't use preorderindex remove them



class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int startp, int endp, int starti, int endi, unordered_map<int, int>& inOrderIndex) {
        if (startp > endp || starti > endi) return nullptr;

        int rootVal = preorder[startp];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = inOrderIndex[rootVal];
        int leftTreeSize = rootIndex - starti;

        root->left = build(preorder, inorder, startp + 1, startp + leftTreeSize, starti, rootIndex - 1, inOrderIndex);
        root->right = build(preorder, inorder, startp + leftTreeSize + 1, endp, rootIndex + 1, endi, inOrderIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        unordered_map<int, int> inOrderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inOrderIndex[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inOrderIndex);
    }
};


 // my code was good but slow as it used while loop conitnuing from the earlier written func use starti to not use the while loop 


 class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }
        index++;
        
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);
        
        return root;
    }
};

























