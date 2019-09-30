/* DFS 
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    int res = 0; //Global Variable to update longest diameter
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int right_depth = maxDepth(root->right);
        int left_depth = maxDepth(root->left);
        res = max(res, right_depth + left_depth); //https://www.youtube.com/watch?v=0VnOfu2pYTo
        return 1 + max(right_depth, left_depth);
    }
};
