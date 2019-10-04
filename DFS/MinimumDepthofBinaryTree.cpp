/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
//DFS recursion
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

//BFS iterative
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int result = 0;
        queue<TreeNode*> q; 
        q.push(root);
        while (!q.empty()) {
            result++;
            //To pop out both left and right child if they both exist in the queue
            for (int i = q.size(); i > 0; i--) {
                TreeNode* tmp = q.front();
                q.pop();
                //Return the result when first reach the condition tmp->right == tmp->left == NULL
                if (tmp->right == NULL && tmp->left == NULL) {
                    return result;
                }
                if (tmp->right != NULL) {
                    q.push(tmp->right);
                } 
                if (tmp->left != NULL) {
                    q.push(tmp->left);
                }
            }
            
        }
        return -1;
    }
};
