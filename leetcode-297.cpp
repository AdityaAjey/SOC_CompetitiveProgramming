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
class Codec {
    void encrypt(TreeNode* root, ostringstream &out){
        if(!root){
            out<<"N ";
            return ;
        }
        out<< root->val<<" ";
        encrypt(root->left, out); // the order doesn't matter you could call right before left but just need to have the same order in decode
        encrypt(root->right, out);
        return;
    }
    TreeNode* decode(istringstream& in) {
        string value = "";
        in >> value; // Extract the next word from the stream just as you do cin>>value where you get data for value through user 
        
        if (value == "N") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(value));
        root->right = decode(in);
        root->left = decode(in);
        
        
        return root;
    }
public:
    // I was confused the question mow I know that it does not check how you serialise it checks that after deserialsie do you create the original tree
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encrypt(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data); // Create an input string stream from the given data string
        return decode(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));