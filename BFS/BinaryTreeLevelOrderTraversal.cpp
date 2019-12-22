/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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

//BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
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
            result.push_back(oneLevelNode);    
        }
        return result;
    }
};

//DFS
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int level = 0;
        dfs(root, level, result);
        return result; 
    }
    
    void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
        //null node 
        if (!node) {
            return;
        }
        if (result.size() == level) {
            result.push_back({});
        }
        result[level].push_back(node->val);
        if (node->left) {
            dfs(node->left, level+1, result);
        }
        if (node->right) {
            dfs(node->right, level+1, result);
        }
    }
};

//My first solution 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> q; 
        q.push(root);
        vector<int> oneLevelNode; 
        oneLevelNode.push_back(root->val);
        result.push_back(oneLevelNode);
        while(!q.empty()) {
            int qsize = q.size(); 
            oneLevelNode = {}; 
            for (int i = 0; i < qsize; i++) {
                TreeNode * tmp = q.front();
                q.pop(); 
                if (tmp->left) {
                    oneLevelNode.push_back(tmp->left->val);
                    q.push(tmp->left);
                } 
                if (tmp->right) {
                    oneLevelNode.push_back(tmp->right->val);
                    q.push(tmp->right);
                }
            }
            if (oneLevelNode.size() != 0) {
                result.push_back(oneLevelNode);    
            }
        }
        return result;
    }
};
