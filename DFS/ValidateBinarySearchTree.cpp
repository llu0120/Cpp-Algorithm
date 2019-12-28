/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

//Note: in order to cover the range of -2^31 ~ 2^31-1, we need to use long or nullable integer.
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
    bool isValidBST(TreeNode* root) {
        //Corner Case: 
        if (!root) {
            return true;
        }
        //General Case:
        return dfs(root, LONG_MIN, LONG_MAX);
    } 
    
    bool dfs(TreeNode* root, long low, long high) {
        if (!root) {
            return true;
        }
        if (root->val <= low || root->val >= high) {
            return false;
        } 
        return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
        
    }
};
