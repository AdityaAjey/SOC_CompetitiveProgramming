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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> level(1);
        // if(!root) return level;
        vector<vector<int>> order;
        if(!root) return order;
        level[0].push_back(root);
        while(level.back().size()>0){
            int i=0;
            for(auto c:level.back()){
                if(c) i=1;
            }
            if(i==0) break;
            vector<TreeNode*> temp;
            for(auto x:level.back()){
                if(x){
                temp.push_back(x->left);
                temp.push_back(x->right);
                }

            }
            if(temp.size()==0) {
                level.pop_back();
                break;
            }
            level.push_back(temp);

        }
        int i=0;
            for(auto c:level.back()){
                if(c) i=1;
            }
        if(i==0) level.pop_back();
        int n = level.size();

        vector<vector<int>> Order(n);
        for(int i=0;i<n;i++){
            for(auto x: level[i]){
               if(x) Order[i].push_back(x->val);
            }
        }
        return Order;
    }

    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }

};

//mistakes - I did level[0].push_back when the size of level was 0
// initialised Order 2 times then changed the name to correct it