/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
class Solution {
public:
    int result = INT_MIN; 
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return result;
    }
    int maxSum(TreeNode* root) {
        if (!root) {
            return 0;
        }   
        int leftSum = max(0, maxSum(root->left));
        int rightSum = max(0, maxSum(root->right));
        
        //Update final result
        int sum = root->val + max(leftSum, 0) + max(rightSum, 0);
        result = max(result, sum);
        
        //Each root can only return root->val + one of the left and right
        return root->val + max(leftSum, rightSum);
    }
};
