/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) {
            TreeNode* tmp = q.front(); 
            q.pop(); 
            if (tmp) {
                result += to_string(tmp->val);
                result.push_back(' ');
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                result +="# ";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        string val; 
        in >> val; 
        if (val == "#") {
            return NULL; 
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q; 
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front(); 
            q.pop(); 
            in >> val;  
            if (val != "#") {
                tmp->left = new TreeNode(stoi(val));
                q.push(tmp->left);
            }
            in >> val;
            if (val != "#") {
                tmp->right = new TreeNode(stoi(val));
                q.push(tmp->right);
            }
        }
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
