/*
Similar to Binary Tree Level Order Traversal 

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if (root == NULL) {
            return result; 
        }
        queue<TreeNode*> q; 
        q.push(root);
        
        int count = 0; 
        while(!q.empty()){
            vector<int> oneLevelNode;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* tmp = q.front(); 
                q.pop();
                oneLevelNode.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            //Reverse if the level number is odd 
            if (count % 2 == 1) {
                reverse(oneLevelNode.begin(), oneLevelNode.end());
            }
            count++; 
            result.push_back(oneLevelNode);
        }
        return result;
    }
};
