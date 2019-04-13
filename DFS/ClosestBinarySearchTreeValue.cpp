//DFS
/**
* Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
* Example
* Example1
* Input: root = {5,4,9,2,#,8,10} and target = 6.124780
* Output: 5
* Example2
* Input: root = {3,2,4,1} and target = 4.142857
* Output: 4
* Notice
* Given target value is a floating point.
* You are guaranteed to have only one unique value in the BST that is closest to the target.
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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        TreeNode* smaller = root;   // A node to store the smaller nearest
        TreeNode* larger = root;    // A node to store the lareger nearest 
        TreeNode* current = root;    
        while (current != NULL){  
            if (current -> val == target) {     //If current node's value equal to target, return current value.
                return current -> val;}
            else if (current -> val > target){  //If current node's value is larger than the target, goes to the left.
                larger = current; 
                current = current -> left;
            }
            else{                               // If current node's value is smaller than the target, goes to the right. 
                smaller = current;
                current = current -> right;
            }
        }
        
        if (abs((larger -> val) - target) < abs((smaller -> val) - target)) return larger -> val; //To see which whether the smaller node or the larger node is the closest. 
        else return smaller -> val;
        
    }
    
};
