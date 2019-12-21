/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/

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
    bool hasPathSum(TreeNode* root, int sum) {
        int tmpSum = 0;
        if (dfs(root, tmpSum, sum)) {
            return true; 
        }
        
        return false;
    } 
    
    bool dfs(TreeNode* cur, int tmpSum, int sum) {
        //if the current node is NULL
        if (cur == NULL) {
            return false;
        }
        
        tmpSum += cur->val;
        //check if is the leaf node and the sum is correct 
        if (cur->left == NULL && cur->right == NULL && tmpSum == sum) {
            return true;
        }
        
        //recursive to the left 
        bool left = dfs(cur->left, tmpSum, sum);
        //recursive to the right
        bool right = dfs(cur->right, tmpSum, sum);
        
        //if any of the left or right result is correct --> true
        return left || right; 
    }
};
