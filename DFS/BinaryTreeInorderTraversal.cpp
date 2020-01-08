/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
//Recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        inorder(root, result);
        return result;
    }
    
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return; 
        }
        if (root->left) {
            inorder(root->left, result);
        }
        
        result.push_back(root->val);
        
        if (root->right) {
            inorder(root->right, result);
        }
    }
};

//Iterative 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        stack<TreeNode*> st; 
        TreeNode* p = root; 
        while (p || !st.empty()) {
            //Push all the left nodes into the stack
            while(p) {
                st.push(p);
                p = p->left; 
            }
            p = st.top();
            st.pop();
            //inorder--> left, root, right 
            result.push_back(p->val);
            p = p->right; 
        }
        return result;
    }
};



