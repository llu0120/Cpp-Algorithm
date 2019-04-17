//DFS
/**
* Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.
* Example
* Example 1:
* Input:
*      1
*    /   \
*  -5     2
*  / \   /  \
* 0   2 -4  -5 
* Output:1
* Example 2:
* Input:
*    1
* Output:1
* Notice
* LintCode will print the subtree which root is your return node.
* It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    int minSum = INT_MAX; //Value of INT_MAX is +2147483647.
                          //Value of INT_MIN is -2147483648. 
    TreeNode* result = nullptr; 
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        CalculateSum(root); //Put the root in CalculateSum to do DFS
        return result;
        
    }
    int CalculateSum(TreeNode* root){
        if (root == nullptr) return 0;  
        int left = CalculateSum(root -> left); //Recursive to the left
        int right = CalculateSum(root -> right); //Recursive to the right
        int sum = left + right + root -> val; //Sum of the subtree 
        if (sum < minSum){
            minSum = sum;   //Replace minSum by the smaller sum 
            result = root;  //Set the node to the result
        }
        return sum; //Return the sum
    }
};
