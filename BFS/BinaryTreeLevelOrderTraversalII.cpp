/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> tmp_result;
        //Corner Case 
        if (root == NULL) {
            return tmp_result;
        }
  		//BFS
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()) {
            int qsize = q.size(); 
            vector<int> oneLevelNode; 
            for (int i = 0; i < qsize; i++) {
                TreeNode * tmp = q.front();
                q.pop(); 
                oneLevelNode.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                } 
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            tmp_result.push_back(oneLevelNode);    
        }
        vector<vector<int>> result;
        for (int i = tmp_result.size()-1; i >= 0; i--) {
            result.push_back(tmp_result[i]);
        }
        return result;
    }
};
