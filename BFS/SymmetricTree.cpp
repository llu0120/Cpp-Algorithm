/* 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
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
//Recursion DFS
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } 
        return checkSymmetric(root->left, root->right);
    }
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        } 
        if (left == NULL || right == NULL || left->val != right->val) {
            return false;
        }
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
};
//Iterative BFS
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(root->left);
        right.push(root->right);
        while (!left.empty() && !right.empty()) {
            TreeNode* tmp_left = left.front();
            TreeNode* tmp_right = right.front();
            left.pop();
            right.pop();
            if (tmp_left == NULL && tmp_right == NULL) {
                continue;
            }
            if (tmp_left == NULL || tmp_right == NULL) {
                return false;
            }
            if (tmp_left->val != tmp_right->val) {
                return false;
            }
            left.push(tmp_left->left);
            left.push(tmp_left->right);
            right.push(tmp_right->right);
            right.push(tmp_right->left);
        }
        return true;
    }
};
