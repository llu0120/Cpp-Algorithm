/* Similar to 102. Binary Tree Level Order Traversal
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        //Corner Case 
        if (root == NULL) {
            return result;
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
			//Only push the right most node to the result vector
            result.push_back(oneLevelNode.back());    
        }
        return result;
    }
};
