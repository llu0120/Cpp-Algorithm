/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/ 

//Recursive 
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; 
        preorder(root, result);
        return result; 
    }
    
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }    
        result.push_back(root->val);
        if (root->left) {
            preorder(root->left, result);
        }
        if (root->right) {
            preorder(root->right, result);
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        //Corner Case: 
        if (!root) {
            return result;
        }
        //General Case: 
        stack<TreeNode*> st; 
        st.push(root);
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop(); 
            result.push_back(tmp->val);
            if (tmp->right) {
                st.push(tmp->right);
            }
            if (tmp->left) {
                st.push(tmp->left);
            }
        }
        return result; 
    }
};
