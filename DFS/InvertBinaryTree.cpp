/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/
//Recursion DFS
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        //Swap the left and the right node and recursion
        TreeNode* tmp = root->left; 
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

//Iterative BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            //Swap the right and the left
            TreeNode* tmp  = node->left;
            node->left = node->right;
            node->right = tmp;
            //If exist left child --> push into queue
            if (node->left != NULL) {
                q.push(node->left);
            }
            //If exist right child --> push into queue
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        return root;
    }
};
