//DFS
/**
* Given a binary tree, determine if it is height-balanced.
* For this problem, a height-balanced binary tree is defined as:
* a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
* Example 1:
* Given the following tree [3,9,20,null,null,15,7]:
*    3
*    / \
*   9  20
*     /  \
*    15   7
* Return true.
*
* Example 2:
* 
* Given the following tree [1,2,2,3,3,null,null,4,4]:
* 
*        1
*       / \
*      2   2
*     / \
*    3   3
*   / \
*  4   4
* Return false.
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
    bool isBalanced(TreeNode* root) {
        if (computeDepth(root) == -1) return false; // Compute depth of root, if equals to -1, this means the tree is unbalanced. 
        else return true;
    }
    int computeDepth(TreeNode* root){   // Compute Depth for a node (recursive) if the difference of the depth of right and left node is larger than 1, return -1. Else, return the depth number. 
        if (!root) return 0; 
        int left = computeDepth(root->left);
        if (left == -1) return -1; 
        int right = computeDepth(root->right);
        if (right == -1) return -1; 
        
        if (abs(left-right)>1) return -1;
        else return 1 + max(left,right);
        
    }
};
